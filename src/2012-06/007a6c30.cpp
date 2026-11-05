// roc 2012-06 007a6c30  unit: RBX::Keyframe  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a6c30
//
// 007a6c30  8b81d0000000         mov eax, dword ptr [ecx + 0xd0]
// 007a6c36  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007a6c30 {
    char pad0[208];
    int m_x;
    int f();
};
int S_func_007a6c30::f()
{
    return m_x;
}
