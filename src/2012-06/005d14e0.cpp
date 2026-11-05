// roc 2012-06 005d14e0  unit: RBX::SceneUpdater  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005d14e0
//
// 005d14e0  8d8198000000         lea eax, [ecx + 0x98]
// 005d14e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_005d14e0 {
    char pad0[152];
    int m_x;
    int* f();
};
int* S_func_005d14e0::f()
{
    return &m_x;
}
