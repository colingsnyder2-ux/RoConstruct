// roc 2012-06 0080ce50  unit: RBX::TextLabel  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0080ce50
//
// 0080ce50  8a81a0020000         mov al, byte ptr [ecx + 0x2a0]
// 0080ce56  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0080ce50 {
    char pad0[672];
    char m_x;
    char f();
};
char S_func_0080ce50::f()
{
    return m_x;
}
