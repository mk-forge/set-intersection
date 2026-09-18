# Set Intersection

Console application that computes the intersection of two sets using Shell sort and binary search algorithms.

## Tech stack

- **Language:** C++
- **Build:** Makefile
- **Documentation:** Doxygen
- **WebAssembly:** Emscripten SDK
- **Deploy:** Cloudflare Workers

## Website

[Demo](https://set-intersection.mk-forge.workers.dev)

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

![Tests passed](./Screenshots/tests.png)
![Help message](./Screenshots/help.png)
![Custom files](./Screenshots/custom.png)
![Default run](./Screenshots/default.png)