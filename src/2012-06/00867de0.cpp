// roc 2012-06 00867de0  unit: RBX::MouseCommand  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00867de0
//
// 00867de0  8d411c               lea eax, [ecx + 0x1c]
// 00867de3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00867de0 {
    char pad0[28];
    int m_x;
    int* f();
};
int* S_func_00867de0::f()
{
    return &m_x;
}
