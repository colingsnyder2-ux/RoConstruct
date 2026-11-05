// roc 2012-06 004c23f0  unit: RBX::AdornRbxGfx  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c23f0
//
// 004c23f0  8b4110               mov eax, dword ptr [ecx + 0x10]
// 004c23f3  8b8074080000         mov eax, dword ptr [eax + 0x874]
// 004c23f9  c3                   ret 
// auto-matched from its assembly shape

struct I_func_004c23f0 {
    char pad[2164];
    int m_x;
};
struct S_func_004c23f0 {
    char pad[16];
    I_func_004c23f0* m_p;
    int f();
};
int S_func_004c23f0::f()
{
    return m_p->m_x;
}
