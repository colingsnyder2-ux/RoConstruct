// roc 2012-06 00750a60  unit: RBX::PartInstance  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00750a60
//
// 00750a60  8d81b4010000         lea eax, [ecx + 0x1b4]
// 00750a66  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};
int* S_func_00750a60::f()
{
    return &m_x;
}
