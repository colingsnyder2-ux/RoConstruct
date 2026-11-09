// roc 2012-06 007300a0  unit: RBX::GameSettings  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007300a0
//
// 007300a0  8a819c000000         mov al, byte ptr [ecx + 0x9c]
// 007300a6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007300a0 {
    char pad0[156];
    char m_x;
    char f();
};
char S_func_007300a0::f()
{
    return m_x;
}
