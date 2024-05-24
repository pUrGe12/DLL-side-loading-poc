DLL side-loading takes advantage of _Windows’ side-by-side_ (SxS or WinSxS) assembly feature, which helps manage conflicting and duplicate DLL versions by loading them on demand from a _common directory_.

WinSxS stores multiple versions of a DLL in the %systemroot%\WinSxS directory, and loads them on demand. This reduces dependency problems for applications that include a side-by-side manifest. Runtime libraries in Visual C++ 2010 and above don’t use this feature, rather they include the version number of the DLL such that each new version of a DLL is a treated as a separate DLL.

WinSxS 'manifests' describe dependencies and libraries used by an application. It gives developers flexibility to update binaries by easily replacing the old binaries in the same location.

-	It reduces DLL version conflicts
-	Enables win assemblies to run simultaneously
-	Updates assembly configuration 

The problem with WinSxS is that

-	Offers no validation of the loaded DLL other than what is mentioned in the `WinSxS manifest’s metadata`.
-	This means, malicious DLL can be loaded, withot much effort


Traditionally, **search-order hijacking attacks** utilize an executable file’s DLL search path to load spoofed DLLs through the known DLLs record. This record comprises a list of known DLLs on the current system, stored in the following registry key:

    HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\KnownDLLs. 

DLL side-loading, in contrast, utilizes the `WinSxS assembly` to load the malicious DLL from the `SxS listing`, which is located in the following registry key:

    %TEMP%\RarSFX%\%ALLUSERS PROFILE%\SXS\ or %TEMP%\RarSFX%\%ALLUSERS PROFILE%\WinSxS\

With WinSxS, a malware can bypass anti-virus scans for a longer period of time. 
