// from server: 65% by colin
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __cdecl sub_62FF38(unsigned long, unsigned long);

void __fastcall sub_41EF67(int edi, int ebx, unsigned long arg)
{
    if (edi == 2)
        return;

    int esi = (ebx == -1) ? 1 : 0;

    unsigned long saved;
    if (esi) {
        saved = GetLastError();
    } else {
        saved = 0;
    }

    sub_62FF38(arg, 0);

    if (esi) {
        SetLastError(saved);
    }
}
