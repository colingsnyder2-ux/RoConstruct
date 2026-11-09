// roc 2012-06 00868370  unit: RBX::MegaClusterPoly  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00868370
//
// 00868370  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00868373  8b4014               mov eax, dword ptr [eax + 0x14]
// 00868376  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00868370 {
    char pad[20];
    int m_x;
};
struct S_func_00868370 {
    char pad[20];
    I_func_00868370* m_p;
    int f();
};
int S_func_00868370::f()
{
    return m_p->m_x;
}
