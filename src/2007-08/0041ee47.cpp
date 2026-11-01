// from server: 70% by colin
extern "C" unsigned long __stdcall GetLastError(void);
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_62FF38(unsigned long, unsigned long);

void __fastcall sub_41EE47(int edi, int ebx, int ebp_minus_20)
{
    if (edi == 2)
        return;

    unsigned long esi = (ebx == -1) ? 1 : 0;
    unsigned long edi_saved;
    if (esi != 0)
        edi_saved = GetLastError();
    else
        edi_saved = 0;

    sub_62FF38(ebp_minus_20, 0);

    if (esi != 0)
        SetLastError(edi_saved);
}
