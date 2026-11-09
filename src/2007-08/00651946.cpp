// from server: 70% by colin
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall func_0062ff38(unsigned long, unsigned long);

void __fastcall func_00651946(int edi, int ebx, int ebp_minus_20)
{
    if (edi == 2)
        return;

    int esi = (ebx == 0) ? 1 : 0;

    unsigned long saved;
    if (esi != 0) {
        saved = GetLastError();
    } else {
        saved = 0;
    }

    func_0062ff38(ebp_minus_20, 0);

    if (esi != 0) {
        SetLastError(saved);
    }
}
