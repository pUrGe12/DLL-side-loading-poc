The files `good_dll.cpp` and `mal_dll.cpp` are to be converted into DLLs. 

Compile them using

    g++ -o -shared good_dll.dll good_dll.cpp
    g++ -o -shared mal_dll.dll mal_dll.cpp

The good_dll contains a simple increment function, to be run during exectution of the main `binary.exe`. The malicious DLL can be made to do many other things, but in this case, its just prompting a dialogue box.
