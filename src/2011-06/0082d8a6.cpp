// from server: 48% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

struct CXTPCommandBarsOptions
{
    void __cdecl f(int, int);
};

void CXTPCommandBarsOptions::f(int edi, int ebx)
{
    if (edi == 2)
        return;
    int esi = (ebx == 0) ? 1 : 0;
    unsigned long edi2;
    if (esi != 0)
        edi2 = GetLastError();
    else
        edi2 = 0;
    SetLastError(edi2);
    if (esi != 0)
        SetLastError(edi2);
}
