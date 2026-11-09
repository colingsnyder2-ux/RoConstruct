// from server: 59% by colin
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long);

extern "C" void __cdecl sub_0062ff38(int, int);

struct CSettingsExplorer
{
    void __cdecl sub_0041f2ba(int, int);
};

void CSettingsExplorer::sub_0041f2ba(int edi, int ebx)
{
    if (edi != 2)
    {
        int esi = (ebx == 0) ? 1 : 0;
        unsigned long saved;
        if (esi != 0)
        {
            saved = GetLastError();
        }
        else
        {
            saved = 0;
        }
        sub_0062ff38(0, 0);
        if (esi != 0)
        {
            SetLastError(saved);
        }
    }
}
