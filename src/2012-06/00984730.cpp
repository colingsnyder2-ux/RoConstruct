// roc 2012-06 00984730  unit: CXTPControlAction  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00984730
//
// 00984730  8b4170               mov eax, dword ptr [ecx + 0x70]
// 00984733  8b4034               mov eax, dword ptr [eax + 0x34]
// 00984736  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00984730 {
    char pad[52];
    int m_x;
};
struct S_func_00984730 {
    char pad[112];
    I_func_00984730* m_p;
    int f();
};
int S_func_00984730::f()
{
    return m_p->m_x;
}
