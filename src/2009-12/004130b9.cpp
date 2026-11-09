// from server: 53% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_7f3b24(unsigned long, unsigned long);

struct CRbxChildFrame
{
    void __cdecl func_4130b9(int edi, int ebx, unsigned long arg);
};

void CRbxChildFrame::func_4130b9(int edi, int ebx, unsigned long arg)
{
    if (edi == 2)
        return;

    int esi = (ebx == -1) ? 1 : 0;

    int saved;
    if (esi)
        saved = (int)GetLastError();
    else
        saved = 0;

    sub_7f3b24(arg, 0);

    if (esi)
        SetLastError((unsigned long)saved);
}
