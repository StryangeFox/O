#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

#define MAXMODULE 50

typedef void (WINAPI* cfunc)();

cfunc Matrix;
cfunc Funk;

void main()
{
    HINSTANCE hLib = LoadLibrary(TEXT("DLL1.DLL"));
    if (hLib == NULL)
    {
        cout << "Unable to load library!" << endl;
        _getch();
        return;
    }

    char mod[MAXMODULE];

    GetModuleFileName((HMODULE)hLib, (LPTSTR)mod, MAXMODULE);
    cout << "Library loaded: " << mod << endl;
    Matrix = (cfunc)GetProcAddress((HMODULE)hLib, "Matrix");
    Funk = (cfunc)GetProcAddress((HMODULE)hLib, "Funk");
    if ((Matrix == NULL) || (Funk == NULL))
    {
        cout << "Unable to load function(s)." << endl;
        FreeLibrary((HMODULE)hLib);
        return;
    }
    Matrix();
    cout << endl;
    Funk();
    cout << endl;
    FreeLibrary((HMODULE)hLib);
    _getch();
}


/*
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main() {
    typedef void (*VoidReturnFunc)();
    HINSTANCE a = LoadLibrary(TEXT("Dll1.dll"));
    if (a == NULL) cout << "error1";
    if (a != NULL) cout << "it's working";

    VoidReturnFunc funk = (VoidReturnFunc) GetProcAddress(a, "funk");
    if (a == NULL) cout << "error2";
    if (a != NULL) funk();


    _getch();
    FreeLibrary(a);
    return 0;
}
*/