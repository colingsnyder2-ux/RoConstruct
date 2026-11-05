// roc 2012-06 006cf440  unit: RBX::VServiceProvider::?$EventDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf440
//
// 006cf440  8b81dc0c0000         mov eax, dword ptr [ecx + 0xcdc]
// 006cf446  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006cf440 {
    char pad0[3292];
    int m_x;
    int f();
};
int S_func_006cf440::f()
{
    return m_x;
}
