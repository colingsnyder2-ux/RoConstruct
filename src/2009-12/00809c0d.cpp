// from server: 70% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

int __stdcall sub_7f3b24(int, int);

void __fastcall f(int edi, int ebx, int ebp_minus_20)
{
    if (edi != 2)
    {
        int esi = (ebx == 0) ? 1 : 0;
        if (esi != 0)
        {
            edi = (int)GetLastError();
        }
        else
        {
            edi = 0;
        }
        sub_7f3b24(ebp_minus_20, 0);
        if (esi != 0)
        {
            SetLastError((unsigned long)edi);
        }
    }
}
