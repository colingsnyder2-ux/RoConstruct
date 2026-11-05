// roc 2012-06 009f5e00  unit: CXTPWinThemeWrapper  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f5e00
//
// 009f5e00  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 009f5e03  8b8088020000         mov eax, dword ptr [eax + 0x288]
// 009f5e09  c3                   ret 
// auto-matched from its assembly shape

struct I_func_009f5e00 {
    char pad[648];
    int m_x;
};
struct S_func_009f5e00 {
    char pad[60];
    I_func_009f5e00* m_p;
    int f();
};
int S_func_009f5e00::f()
{
    return m_p->m_x;
}
