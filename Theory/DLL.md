Dynamic Link Library, or DLL for short, is Microsoft’s implementation of the _shared library concept_. These libraries, have the extension .dll file extension, contain code and data that can be used by multiple programs at the same time. When an application requires a DLL to run, Windows attempts to load the DLL from either a full path defined by the application or via a manifest file. A manifest is essentially a plain text file that contains information about the dependencies and configuration requirements of an application or component.

Adversaries exploit poorly configured manifest files by placing a malicious DLL with the **same name as a legitimate DLL** in a location where an application will load it before the DLL that should be loaded.

If Safe DLL search mode is enabled (which is by default on most versions) then OS will check whether the DLL is already loaded in memory or is it a part of Known DLLs registry key located at HKEY_LOCAL_MACHINESYSTEMCurrentControlSetControlSession ManagerKnownDLLs. If OS cannot find the DLL at either of these, then DLL search starts in the following order:

-	The directory from which the application is loaded (if that happens to be the current directory then be it)
-	The system directory
-	The 16-bit system directory
-	The windows directory
-	The current working directory
-	The directories listed in the PATH environment variable

The earliest known exploit that used this DLL side loading is, `CVE-2000-0854` (When a Microsoft Office 2000 document is launched, the directory of that document is first used to locate DLLs such as `riched20.dll` and `msi.dll`, which could allow an attacker to execute arbitrary commands by inserting a Trojan Horse DLL into the same directory as the document).

    reg add "HKEY_CURRENT_USER\Software\Microsoft\Office test\Special\Perf" /t REG_SZ /d C:\Users\<username>\<same_name_but_malicious>.dll

This command add a malicious dll `same_name_but_malicious.dll` to the microsoft registry key, implying that everytime a microsoft application (like word, excel) is launched, it loads this malicious DLL instead of the actual DLL (if actual DLL is not in memory already), due to the way microsoft searches for DLLs.
