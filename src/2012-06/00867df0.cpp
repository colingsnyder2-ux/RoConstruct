// roc 2012-06 00867df0  unit: RBX::MouseCommand  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00867df0
//
// 00867df0  8d4124               lea eax, [ecx + 0x24]
// 00867df3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00867df0 {
    char pad0[36];
    int m_x;
    int* f();
};
int* S_func_00867df0::f()
{
    return &m_x;
}
