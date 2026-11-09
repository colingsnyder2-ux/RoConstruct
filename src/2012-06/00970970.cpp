// roc 2012-06 00970970  unit: W4_D3DFORMAT::?$EnumDesc  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00970970
//
// 00970970  8d4150               lea eax, [ecx + 0x50]
// 00970973  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00970970 {
    char pad0[80];
    int m_x;
    int* f();
};
int* S_func_00970970::f()
{
    return &m_x;
}
