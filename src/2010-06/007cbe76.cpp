// from server: 70% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_7A7C64(unsigned long, unsigned long);

void __fastcall sub_7CBE76(int edi, int ebx, int ebp_20)
{
    if (edi != 2)
    {
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
        sub_7A7C64(ebp_20, 0);
        if (esi != 0)
        {
            SetLastError((unsigned long)saved);
        }
    }
}
