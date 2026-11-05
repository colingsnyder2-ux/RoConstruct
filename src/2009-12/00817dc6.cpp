// from server: 43% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_7f3b24(int, int);

struct CXTPCommandBarsOptions {
    void __cdecl f(int, int);
};

void CXTPCommandBarsOptions::f(int edi, int ebx) {
    if (edi == 2) return;
    int esi = (ebx == 0) ? 1 : 0;
    int saved;
    if (esi) {
        saved = (int)GetLastError();
    } else {
        saved = 0;
    }
    sub_7f3b24(0, 0);
    if (esi) {
        SetLastError((unsigned long)saved);
    }
}
