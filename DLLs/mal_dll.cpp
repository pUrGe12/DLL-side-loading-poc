#include <windows.h>
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
  switch (ul_reason_for_call){
    case DLL_PROCESS_ATTACH:
      MessageBox(NULL, "You've been side loaded!", "Alert", MB_OK | MB_ICONWARNING);
      break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
      break;
  }
  return TRUE;
}
