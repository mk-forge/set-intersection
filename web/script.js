let terminal = new Terminal({
    cursorBlink: true,
    fontFamily: "'Geist Mono', monospace",
    fontSize: 14,
    theme: {
        background: '#000000',
        foreground: '#d4d4d4'
    }
});

terminal.open(document.getElementById('terminal'));

let { master, slave } = openpty();
terminal.loadAddon(master);

function printPrompt() {
    terminal.write('\n\x1b[38;2;255;62;0m> \x1b[0m');
}

function printPromptNoNewline() {
    terminal.write('\x1b[38;2;255;62;0m> \x1b[0m');
}

(async () => {
    let initMainModule = (await import('./set_intersection.mjs')).default;
    let mainModule = await initMainModule({ pty: slave, noExitRuntime: true });

    terminal.writeln('\x1b[38;2;255;62;0m> Set Intersection\x1b[0m');
    terminal.writeln('');
    terminal.writeln('Available commands:');
    terminal.writeln('  set_intersection');
    terminal.writeln('  set_intersection <input1> <input2> [output]');
    terminal.writeln('  set_intersection --help');
    terminal.writeln('  test');
    terminal.writeln('  doxygen');
    terminal.writeln('  cls / clear');
    terminal.writeln('');
    terminal.writeln('Available key shortcuts:');
    terminal.writeln('  Tab          complete command');
    terminal.writeln('  Ctrl+Shift+V paste into terminal');

    let buffer = '';
    let commands = ['set_intersection', 'test', 'doxygen', 'cls', 'clear'];

    printPrompt();

    terminal.attachCustomKeyEventHandler((event) => {
        // block F1-F12, alt, arrows and other escape sequence keys
        if ((event.ctrlKey && !event.shiftKey) || (event.altKey && !event.ctrlKey) || /^F\d{1,2}$/.test(event.key) ||
            event.key == 'ArrowUp' || event.key == 'ArrowDown' || event.key == 'ArrowLeft' || event.key == 'ArrowRight' ||
            event.key == 'Home' || event.key == 'End' || event.key == 'PageUp' || event.key == 'PageDown' ||
            event.key == 'Delete' || event.key == 'Escape' || event.key == 'Insert' || event.key == 'ContextMenu') {
            
            event.preventDefault();
            return false;
        }

        if (event.key == 'Tab') {
            event.preventDefault();

            let parts = buffer.split(/\s+/);
            let lastWord = parts[parts.length - 1];

            if (parts.length == 1) {
                let suggestion = commands.find(cmd => cmd.startsWith(lastWord));

                if (suggestion) {
                    buffer = suggestion;
                    terminal.write('\r\x1b[K');
                    printPromptNoNewline();
                    terminal.write(buffer);
                }
            } else if (parts[0] == 'set_intersection' && parts.length >= 2) {
                if ('--help'.startsWith(lastWord)) {
                    buffer = buffer.slice(0, buffer.length - lastWord.length) + '--help';
                    terminal.write('\r\x1b[K');
                    printPromptNoNewline();
                    terminal.write(buffer);
                }
            }

            return false;
        }

        return true;
    });

    terminal.onData((data) => {
        // pasted multiline text would break the prompt, so keep only the first line
        if (data.length > 1 && (data.includes('\n') || data.includes('\r')))
            data = data.split(/[\r\n]/)[0];

        for (let char of data) {
            if (char == '\r' || char == '\n') {
                terminal.write('\r\n');
                let args = buffer.trim().split(/\s+/).filter(a => a.length > 0);
                buffer = '';

                if (args[0] == 'clear' || args[0] == 'cls') {
                    terminal.clear();
                    printPromptNoNewline();
                } else if (args[0] == 'doxygen') {
                    window.open('/docs/index.html', '_blank');
                    printPromptNoNewline();
                } else if (args[0] == 'test') {
                    runUnitTests();
                } else if (args[0] == 'set_intersection') {
                    args.shift(); // drop the command name because Emscripten adds its own argv[0]

                    if (args.length == 2)
                        args.push('intersection.txt');

                    try {
                        mainModule.callMain(args);
                    } catch (error) {}
                    setTimeout(() => printPrompt(), 100); // needed for the > symbol to show
                } else {
                    terminal.writeln('Unknown command. Type --help for usage.');
                    printPrompt();
                }
            } else if (char == '\u007F' || char == '\b') {
                if (buffer.length > 0)
                    buffer = buffer.slice(0, -1);
            } else if (char >= ' ' && char <= '~') {
                if (buffer.length < 256)
                    buffer += char;
            }
        }
    });

    async function runUnitTests() {
        let initTestModule = (await import('./test_intersection.mjs')).default;
        let testModule = await initTestModule({ pty: slave, noExitRuntime: true });
        
        try {
            testModule.callMain([]);
        } catch (error) {}
        setTimeout(() => printPrompt(), 100);
    }
})();