// roc 2012-06 0071a1e0  unit: RBX::Game  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071a1e0
//
// 0071a1e0  8a81ac000000         mov al, byte ptr [ecx + 0xac]
// 0071a1e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0071a1e0 {
    char pad0[172];
    char m_x;
    char f();
};
char S_func_0071a1e0::f()
{
    return m_x;
}
