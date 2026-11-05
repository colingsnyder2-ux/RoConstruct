// from server: 64% by colin
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern void __cdecl func_0062ff38(int, int);

void __fastcall func_00648e57(int edi, int ebx, int ebp_minus_20)
{
    if (edi == 2)
        return;

    int esi = (ebx == -1) ? 1 : 0;
    int saved = 0;
    if (esi)
        saved = (int)GetLastError();

    func_0062ff38(ebp_minus_20, 0);

    if (esi)
        SetLastError((unsigned long)saved);
}
