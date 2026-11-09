// from server: 61% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_7f3b24(int, int);

int __fastcall sub_8c1456(int edi, int ebx, int ebp_arg)
{
    if (edi == 2)
        return 0;

    int esi = (ebx == 0) ? 1 : 0;
    int saved;
    if (esi != 0)
    {
        saved = (int)GetLastError();
    }
    else
    {
        saved = 0;
    }

    sub_7f3b24(ebp_arg, 0);

    if (esi != 0)
    {
        SetLastError((unsigned long)saved);
    }
    return 0;
}
