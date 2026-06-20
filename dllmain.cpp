#include <Windows.h>

#include <edit_on_release.h>

void dll_main() {
    EditOnRelease::find_functions();
    EditOnRelease::place_hooks();

    while (true) {
        if (GetAsyncKeyState(VK_F3) & 1) {
            EditOnRelease::g_UseEditOnRelease = !EditOnRelease::g_UseEditOnRelease;
        }

        Sleep(1000);
    }
}


BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)dll_main, 0, 0, 0);
    }

    return TRUE;
}
