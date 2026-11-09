// from server: 63% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

void __stdcall sub_7f3b24(unsigned long);

int __fastcall f(int edi, int ebx, int ebp_arg)
{
    if (edi == 2)
        return 0;
    int esi = (ebx == 0) ? 1 : 0;
    int edi2;
    if (esi != 0) {
        edi2 = (int)GetLastError();
    } else {
        edi2 = 0;
    }
    sub_7f3b24(ebp_arg);
    if (esi != 0) {
        SetLastError((unsigned long)edi2);
    }
    return 0;
}
