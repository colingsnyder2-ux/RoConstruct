// roc 2012-06 008d34b0  unit: RBX::VHandles::?$FactoryProduct  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008d34b0
//
// 008d34b0  8a4120               mov al, byte ptr [ecx + 0x20]
// 008d34b3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008d34b0 {
    char pad0[32];
    char m_x;
    char f();
};
char S_func_008d34b0::f()
{
    return m_x;
}
