// from server: 71% by tajop
typedef unsigned long DWORD;

extern DWORD (__stdcall *pGetLastError)(void);
extern void (__stdcall *pSetLastError)(DWORD);

void __stdcall func_0062ff38(int flags, int p);

void __fastcall func_00648e57(int state, int result, int p)
{
    if (state == 2)
        return;

    int preserve = (result == -1);
    DWORD err;
    if (preserve)
        err = pGetLastError();
    else
        err = 0;

    func_0062ff38(0, p);

    if (preserve)
        pSetLastError(err);
}
