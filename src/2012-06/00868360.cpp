// roc 2012-06 00868360  unit: RBX::MegaClusterPoly  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00868360
//
// 00868360  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00868363  8b4004               mov eax, dword ptr [eax + 4]
// 00868366  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00868360 {
    char pad[4];
    int m_x;
};
struct S_func_00868360 {
    char pad[20];
    I_func_00868360* m_p;
    int f();
};
int S_func_00868360::f()
{
    return m_p->m_x;
}
