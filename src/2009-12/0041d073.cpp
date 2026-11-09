// from server: 42% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

struct CSettingsExplorer {
    void __cdecl f(int edi, int ebx);
};

void CSettingsExplorer::f(int edi, int ebx) {
    if (edi == 2) return;
    int esi = (ebx == 0) ? 1 : 0;
    if (esi) {
        edi = GetLastError();
    } else {
        edi = 0;
    }
    SetLastError(0);
    if (esi) {
        SetLastError(edi);
    }
}
