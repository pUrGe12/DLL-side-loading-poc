#include <Windows.h>
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            MessageBox(NULL, "Do you want to continue?", "Confirmation", MB_YESNO | MB_ICONQUESTION);
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}
extern "C" __declspec(dllexport) int IncrementNumber(int number) {
    return number + 1;
}
