// roc 2012-06 00892980  unit: seg_00890000  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00892980
//
// 00892980  8d4110               lea eax, [ecx + 0x10]
// 00892983  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00892980 {
    char pad0[16];
    int m_x;
    int* f();
};
int* S_func_00892980::f()
{
    return &m_x;
}
