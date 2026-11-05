// from server: 36% by atomic.potato
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
struct S_006f6210 {
    char pad0[4];
    int m_x;
    int f();
};
extern "C" int __stdcall call_006f5b10(DWORD, DWORD);
int S_006f6210::f()
{
    DWORD eax = *(DWORD*)(this + 4);
    if (!eax)
        return 0;
    DWORD edx = *(DWORD*)(this + 8);
    DWORD ecx = *(DWORD*)(eax + 0x38);
    eax = (DWORD)(eax - 0x1c);
    ecx += eax;
    call_006f5b10(edx, ecx);
    return 0;
}
