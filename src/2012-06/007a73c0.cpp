// roc 2012-06 007a73c0  unit: RBX::KeyframeSequence  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a73c0
//
// 007a73c0  c6818000000000       mov byte ptr [ecx + 0x80], 0
// 007a73c7  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_007a73c0 {
    char pad0[128];
    char m_x;
    void f(int a1);
};
void S_func_007a73c0::f(int a1)
{
    m_x = (char)0;
}
