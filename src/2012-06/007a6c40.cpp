// roc 2012-06 007a6c40  unit: RBX::Keyframe  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a6c40
//
// 007a6c40  c6818000000000       mov byte ptr [ecx + 0x80], 0
// 007a6c47  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007a6c40 {
    char pad0[128];
    char m_x;
    void f();
};
void S_func_007a6c40::f()
{
    m_x = (char)0;
}
