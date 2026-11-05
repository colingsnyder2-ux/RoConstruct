// roc 2012-06 00867f80  unit: RBX::MegaClusterPoly  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00867f80
//
// 00867f80  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00867f83  8b4034               mov eax, dword ptr [eax + 0x34]
// 00867f86  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00867f80 {
    char pad[52];
    int m_x;
};
struct S_func_00867f80 {
    char pad[20];
    I_func_00867f80* m_p;
    int f();
};
int S_func_00867f80::f()
{
    return m_p->m_x;
}
