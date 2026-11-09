// from server: 70% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_7F3B24(unsigned long, unsigned long);

void __fastcall sub_809997(int edi, int ebx, unsigned long arg)
{
    if (edi == 2)
        return;

    int esi = (ebx == -1) ? 1 : 0;

    int saved;
    if (esi)
        saved = (int)GetLastError();
    else
        saved = 0;

    sub_7F3B24(arg, 0);

    if (esi)
        SetLastError((unsigned long)saved);
}
