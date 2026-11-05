// roc 2012-06 007a6c20  unit: RBX::Keyframe  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a6c20
//
// 007a6c20  8a81cc000000         mov al, byte ptr [ecx + 0xcc]
// 007a6c26  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007a6c20 {
    char pad0[204];
    char m_x;
    char f();
};
char S_func_007a6c20::f()
{
    return m_x;
}
