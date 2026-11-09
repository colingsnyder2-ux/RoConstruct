// roc 2012-06 008d34a0  unit: RBX::$$A6AXW4NormalId::?$signal::Vslot::?$callable  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008d34a0
//
// 008d34a0  8a81a4000000         mov al, byte ptr [ecx + 0xa4]
// 008d34a6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008d34a0 {
    char pad0[164];
    char m_x;
    char f();
};
char S_func_008d34a0::f()
{
    return m_x;
}
