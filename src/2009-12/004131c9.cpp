// from server: 55% by atomic.potato
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long);

extern "C" void __cdecl sub_007F3B24(unsigned long, unsigned long);

struct CRbxChildFrame
{
    void __cdecl sub_004131C9(int edi, int ebx, unsigned long arg);
};

void CRbxChildFrame::sub_004131C9(int edi, int ebx, unsigned long arg)
{
    if (edi != 2)
    {
        int esi = (ebx == -1) ? 1 : 0;
        int saved;
        if (esi)
        {
            saved = (int)GetLastError();
        }
        else
        {
            saved = 0;
        }
        sub_007F3B24(arg, 0);
        if (esi)
        {
            SetLastError((unsigned long)saved);
        }
    }
}
