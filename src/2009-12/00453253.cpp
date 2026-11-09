// from server: 43% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern int G_98b230;
extern int G_98b1d4;

extern void __cdecl sub_7f3b24(int, int);

struct CRobloxControlColorSelector
{
    void __cdecl sub_453253(int edi, int ebx, int ebp_20);
};

void CRobloxControlColorSelector::sub_453253(int edi, int ebx, int ebp_20)
{
    if (edi == 2)
        return;

    int esi = (ebx == 0) ? 1 : 0;
    int saved = 0;
    if (esi != 0)
    {
        saved = GetLastError();
        edi = saved;
    }
    else
    {
        edi = 0;
    }

    sub_7f3b24(ebp_20, 0);

    if (esi != 0)
    {
        SetLastError(edi);
    }
}
