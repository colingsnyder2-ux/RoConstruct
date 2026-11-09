// roc 2012-06 00868380  unit: RBX::MegaClusterPoly  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00868380
//
// 00868380  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00868383  8b4024               mov eax, dword ptr [eax + 0x24]
// 00868386  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00868380 {
    char pad[36];
    int m_x;
};
struct S_func_00868380 {
    char pad[20];
    I_func_00868380* m_p;
    int f();
};
int S_func_00868380::f()
{
    return m_p->m_x;
}
