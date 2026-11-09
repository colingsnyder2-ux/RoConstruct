// from server: 67% by colin
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall func_0062ff38(int, int);

void __fastcall func_006490cd(int edi, int ebx, int arg)
{
    if (edi == 2)
        return;

    int esi = (ebx == 0) ? 1 : 0;
    int saved = 0;
    if (esi != 0)
        saved = (int)GetLastError();

    func_0062ff38(arg, 0);

    if (esi != 0)
        SetLastError((unsigned long)saved);
}
