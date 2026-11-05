// from server: 67% by atomic.potato
typedef unsigned long DWORD;

extern "C" DWORD __stdcall GetProcAddress(DWORD, const char *);

DWORD __cdecl CreateImageListDragLeave();
extern DWORD (__stdcall *g_GetProcAddress)(DWORD);

struct CSettingsExplorer
{
    char pad[0x70];
    DWORD field70;
    void f(DWORD *out);
};

void CSettingsExplorer::f(DWORD *out)
{
    if (field70 == 0)
    {
        field70 = g_GetProcAddress(CreateImageListDragLeave());
    }
    *out = field70;
}
