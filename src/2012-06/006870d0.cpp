// roc 2012-06 006870d0  unit: RBX::VCamera::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006870d0
//
// 006870d0  8b814c010000         mov eax, dword ptr [ecx + 0x14c]
// 006870d6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006870d0 {
    char pad0[332];
    int m_x;
    int f();
};
int S_func_006870d0::f()
{
    return m_x;
}
