// from server: 67% by tajop
extern "C" unsigned long (__stdcall *pGetLastError)(void);
extern "C" void (__stdcall *pSetLastError)(unsigned long);

extern "C" void __stdcall sub_62FF38(int, int);

extern int g_frameValue;

void __fastcall sub_41F3E2(int state, int flag)
{
    if (state == 2)
        return;

    int preserve = (flag == 0) ? 1 : 0;
    unsigned long saved;
    if (preserve != 0) {
        saved = pGetLastError();
    } else {
        saved = 0;
    }

    sub_62FF38(0, g_frameValue);

    if (preserve != 0)
        pSetLastError(saved);
}
