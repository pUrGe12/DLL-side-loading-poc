#include <Windows.h>
#include <iostream>
using namespace std;
int main() {
    HMODULE hGoodDLL = LoadLibrary("good_dll.dll");
    if (hGoodDLL == NULL) {
        cout << "Failed to load good.dll" << endl;
        return 1;
    }
// Prompt user to enter a number
    int number;
    cout << "Enter a number: ";
    cin >> number;
// Call IncrementNumber function from good.dll
    typedef int (*IncrementNumberFunc)(int);
    IncrementNumberFunc incrementNumber = (IncrementNumberFunc)GetProcAddress(hGoodDLL, "IncrementNumber");
    if (incrementNumber != NULL) {
        int incrementedNumber = incrementNumber(number);
        cout << "Number incremented by 1: " << incrementedNumber << endl;
    } else {
        cout << "Failed to find IncrementNumber function in good.dll" << endl;
    }
    FreeLibrary(hGoodDLL);
    return 0;
}
