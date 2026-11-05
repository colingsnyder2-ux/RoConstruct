// roc 2012-06 008da8f0  unit: RBX::ArcHandles  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008da8f0
//
// 008da8f0  8d81e0020000         lea eax, [ecx + 0x2e0]
// 008da8f6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008da8f0 {
    char pad0[736];
    int m_x;
    int* f();
};
int* S_func_008da8f0::f()
{
    return &m_x;
}
