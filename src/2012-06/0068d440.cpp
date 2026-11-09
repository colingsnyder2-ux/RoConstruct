// roc 2012-06 0068d440  unit: RBX::Camera  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0068d440
//
// 0068d440  8d81d0000000         lea eax, [ecx + 0xd0]
// 0068d446  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0068d440 {
    char pad0[208];
    int m_x;
    int* f();
};
int* S_func_0068d440::f()
{
    return &m_x;
}
