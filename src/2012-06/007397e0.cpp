// roc 2012-06 007397e0  unit: RBX::GuiTextButton  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007397e0
//
// 007397e0  8a8191000000         mov al, byte ptr [ecx + 0x91]
// 007397e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007397e0 {
    char pad0[145];
    char m_x;
    char f();
};
char S_func_007397e0::f()
{
    return m_x;
}
