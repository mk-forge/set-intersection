# Set Intersection

![C%2B%2B](https://img.shields.io/badge/C%2B%2B-00599C?logo=cplusplus&logoColor=white)
![WebAssembly](https://img.shields.io/badge/WebAssembly-654FF0?logo=webassembly&logoColor=white)
![Emscripten](https://img.shields.io/badge/Emscripten-000000?logo=emscripten&logoColor=white)
![Cloudflare](https://img.shields.io/badge/Cloudflare-F38020?logo=cloudflare&logoColor=white)

Console application that computes the intersection of two sets using Shell sort and binary search algorithms.

## Tech stack

- **Language:** C++
- **Build:** Makefile
- **Documentation:** Doxygen
- **Library:** xterm.js
- **WebAssembly:** Emscripten SDK
- **Deploy:** Cloudflare Workers

## Website

[Set Intersection](https://set-intersection.mk-forge.workers.dev)

## Features

- Interactive terminal emulator in the browser
- Tab completion for commands
- Clear the console with `cls` or `clear`
- All original CLI commands available (`set_intersection <input1> <input2> [output]`, `set_intersection --help`, `test`, `doxygen`)

## Usage

Default files:
```sh
make && .\set_intersection.exe
```

Custom files:
```sh
make && .\set_intersection.exe input1.txt input2.txt output.txt
```

Help:
```sh
make && .\set_intersection.exe --help
```

## Tests
```sh
make test
```

## Documentation
```sh
doxygen Doxyfile
```

## Screenshots

![Tests passed](https://raw.githubusercontent.com/mk-forge/set-intersection/main/Screenshots/tests.png)
![Help message](https://raw.githubusercontent.com/mk-forge/set-intersection/main/Screenshots/help.png)
![Custom files](https://raw.githubusercontent.com/mk-forge/set-intersection/main/Screenshots/custom.png)
![Default run](https://raw.githubusercontent.com/mk-forge/set-intersection/main/Screenshots/default.png)

## License

[MIT](LICENSE)