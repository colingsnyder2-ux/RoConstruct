// roc 2012-06 007d4d20  unit: CXTCaptionButton  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007d4d20
//
// 007d4d20  dd8180000000         fld qword ptr [ecx + 0x80]
// 007d4d26  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007d4d20 {
    char pad[128];
    double m_x;
    double f();
};
double S_func_007d4d20::f()
{
    return m_x;
}
