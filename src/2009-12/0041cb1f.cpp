// from server: 61% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

void __stdcall sub_7f3b24(int, int);

int __fastcall sub_41cb1f(int edi, int ebx, int ebp_20)
{
    if (edi == 2)
        return 0;

    int esi = (ebx == 0) ? 1 : 0;

    int edi2;
    if (esi != 0)
        edi2 = (int)GetLastError();
    else
        edi2 = 0;

    sub_7f3b24(ebp_20, 0);

    if (esi != 0)
        SetLastError((unsigned long)edi2);

    return 0;
}
