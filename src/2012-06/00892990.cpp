// roc 2012-06 00892990  unit: seg_00890000  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00892990
//
// 00892990  dd8188000000         fld qword ptr [ecx + 0x88]
// 00892996  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00892990 {
    char pad[136];
    double m_x;
    double f();
};
double S_func_00892990::f()
{
    return m_x;
}
