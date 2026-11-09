// from server: 42% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

struct CSettingsExplorer {
    void f(int edi, int ebx, int ebp_arg);
};

void CSettingsExplorer::f(int edi, int ebx, int ebp_arg)
{
    if (edi == 2)
        return;
    int esi = (ebx == 0) ? 1 : 0;
    int saved;
    if (esi != 0) {
        saved = (int)GetLastError();
    } else {
        saved = 0;
    }
    SetLastError(ebp_arg);
    if (esi != 0) {
        SetLastError(saved);
    }
}
