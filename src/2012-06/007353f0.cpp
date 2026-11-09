// roc 2012-06 007353f0  unit: RBX::VFrame::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007353f0
//
// 007353f0  8a81dc010000         mov al, byte ptr [ecx + 0x1dc]
// 007353f6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007353f0 {
    char pad0[476];
    char m_x;
    char f();
};
char S_func_007353f0::f()
{
    return m_x;
}
