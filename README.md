# DLL-side-loading-poc
This repo contains a proof of concept for a technique called DLL side-loading, used to import malicious code into legitimate executables. This does not make use of the WinSxS assembly, for that, refer the extended version. 

To see how it all fits,

- Compile the DLLs and the binary
- Save the DLLs and the binary in the same directory
- Run the binary to get the expected result
- Move the `good_dll.dll` to the previous directory and rename `mal_dll.dll` as good_dll.dll

Going by how windows searches for relevant DLLs, it will first look in the current directory for `good_dll.dll` and thus, read our malicious DLL and load that instead.

- Run the binary again and get the hacked message

## Problems with this approach
----------------------------
1. Windows doesn't let you delete or move DLLs stored in the `System32` directory
2. A lot of DLLs have static and dynamics dependencies, which makes creating a valid DLL for side-loading difficult

These are the problems I hope to solve in the extended version.
