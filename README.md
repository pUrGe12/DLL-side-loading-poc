# DLL-side-loading-poc
This repo contains a proof of concept for a technique called DLL side-loading, used to import malicious code into legitimate executables. This does not make use of the WinSxS assembly, for that, refer the extended version. 

First we'll be looking at DLL search order hijacking.

To see how it all fits,

- Compile the DLLs and the binary
- Save the DLLs and the binary in the same directory
- Run the binary to get the expected result
- Move the `good_dll.dll` to the previous directory and rename `mal_dll.dll` as good_dll.dll

Going by how windows searches for relevant DLLs, it will first look in the current directory for `good_dll.dll` and thus, read our malicious DLL and load that instead.

- Run the binary again and get the hacked message

Alternatively,

Compile the `Malware.cpp` using

    g++ -o malware Malware.cpp
and run that to do all the above automatically


The [extended version](https://github.com/pUrGe12/DLL-side-loading-poc/tree/main/extended) contains code relevant to WinSxS directory and a more traditional DLL side-loading. 
