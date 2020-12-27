// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

extern "C" __declspec(dllexport) void  Matrix()
{

    int n, m, buf, i, j;
    int a[12][12];
    cout << "Input N ";
    cin >> n;
    m = n;
    cout << endl;
    srand(time(NULL));
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {

            a[i][j] = -100 + rand() % 100;
        }

    }
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {
            cout << a[i][j] << " ";

        }
        cout << endl;
    }
    system("pause");

}

extern "C" __declspec(dllexport) void  Funk()
{

    cout << "Hey world";
    system("pause<void");

}

#define MAXMODULE 50

char module[MAXMODULE];

extern "C" __declspec(dllexport) void NumberList()
{
    GetModuleFileName(NULL, (LPTSTR)module, MAXMODULE);
    cout << "\n\nThis function was called from "
        << module
        << endl << endl;
    cout << "NumberList(): ";
    for (int i = 0; i < 10; i++)
    {
        cout << i << " ";
    }
    cout << endl << endl;
}

extern "C" __declspec(dllexport) void LetterList()
{
    GetModuleFileName(NULL, (LPTSTR)module, MAXMODULE);
    cout << "\n\nThis function was called from "
        << module
        << endl << endl;
    cout << "LetterList(): ";
    for (int i = 0; i < 26; i++)
    {
        cout << char(97 + i) << " ";
    }
    cout << endl << endl;
}


BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

