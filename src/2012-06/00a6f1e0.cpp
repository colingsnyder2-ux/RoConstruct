// roc 2012-06 00a6f1e0  unit: CXTPRibbonGroupControlPopup  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a6f1e0
//
// 00a6f1e0  8b4130               mov eax, dword ptr [ecx + 0x30]
// 00a6f1e3  8b4034               mov eax, dword ptr [eax + 0x34]
// 00a6f1e6  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00a6f1e0 {
    char pad[52];
    int m_x;
};
struct S_func_00a6f1e0 {
    char pad[48];
    I_func_00a6f1e0* m_p;
    int f();
};
int S_func_00a6f1e0::f()
{
    return m_p->m_x;
}
