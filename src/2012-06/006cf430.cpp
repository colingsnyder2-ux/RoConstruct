// roc 2012-06 006cf430  unit: RBX::VServiceProvider::?$EventDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf430
//
// 006cf430  8b81d80c0000         mov eax, dword ptr [ecx + 0xcd8]
// 006cf436  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006cf430 {
    char pad0[3288];
    int m_x;
    int f();
};
int S_func_006cf430::f()
{
    return m_x;
}
