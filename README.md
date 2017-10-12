
# poclmembench
## Portable OpenCL Memory Benchmark 

**poclmemebench** benchmarks amd gpu memory, works on platforms:

*	Linux
*	MacOS
*	Windows

Project inspired by delphi OclMemBench by duzenko [https://github.com/duzenko/OpenclMemBench](https://github.com/duzenko/OpenclMemBench "github")  


## Install

Standalone **executables** for _Linux_, _macOS_ and _Windows_ are provided in
the [Releases](https://github.com/kruzer/poclmembench/releases) section.
Download an archive for your operating system and unpack the content to a place
accessible from command line. 

## Usage

The **poclmembench** is a command line utility. This means you launch it either
from a Windows command prompt or Linux console, or create shortcuts to
predefined command lines using a Linux Bash script or Windows batch/cmd file.
For a full list of available command, please run

```sh
poclmembench --help
```

## Build

This project uses [CMake].

1. Create a build directory.

```sh
mkdir build; cd build
```

2. Configure the project with CMake.

```sh
cmake ..
```

3. Build the project using CMake. This is a portable variant of `make`.

```sh
cmake --build .
```
   

## example
```sh
poclmembench -p 0 -d 0
```
![Linux Screeenshot](img/ScreenshotLin.png?raw=true "Linux Screenshot")
![MacOS Screeenshot](img/ScreenshotMac.png?raw=true "MacOS Screenshot")
![Windows Screeenshot](img/ScreenshotWin.png?raw=true "Windows Screenshot")


