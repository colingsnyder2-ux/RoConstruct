// roc 2012-06 0080ce60  unit: RBX::TextLabel  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0080ce60
//
// 0080ce60  8a8153020000         mov al, byte ptr [ecx + 0x253]
// 0080ce66  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0080ce60 {
    char pad0[595];
    char m_x;
    char f();
};
char S_func_0080ce60::f()
{
    return m_x;
}
