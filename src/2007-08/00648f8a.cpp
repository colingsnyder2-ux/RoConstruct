// from server: 70% by colin
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_62FF38(int, int);

void __fastcall sub_648F8A(int edi, int ebx, int ebp_minus_20)
{
    if (edi == 2)
        return;

    int esi = (ebx == 0) ? 1 : 0;
    int saved;
    if (esi) {
        saved = (int)GetLastError();
    } else {
        saved = 0;
    }

    sub_62FF38(ebp_minus_20, 0);

    if (esi) {
        SetLastError((unsigned long)saved);
    }
}
