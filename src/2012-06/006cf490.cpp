// roc 2012-06 006cf490  unit: RBX::VServiceProvider::?$EventDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf490
//
// 006cf490  8b81d40c0000         mov eax, dword ptr [ecx + 0xcd4]
// 006cf496  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006cf490 {
    char pad0[3284];
    int m_x;
    int f();
};
int S_func_006cf490::f()
{
    return m_x;
}
