// from server: 61% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_7f3b24(unsigned long);

struct CSettingsExplorer {
    void f();
};

void CSettingsExplorer::f() {
    int edi;
    int ebx;
    int esi;
    int eax;
    if (edi == 2) {
        return;
    }
    eax = 0;
    if (ebx == 0) {
        eax = 1;
    }
    esi = eax;
    if (esi != 0) {
        edi = GetLastError();
    } else {
        edi = 0;
    }
    sub_7f3b24(0);
    if (esi != 0) {
        SetLastError(edi);
    }
}
