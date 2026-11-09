// roc 2012-06 008bd230  unit: RBX::AsyncHttpQueue  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008bd230
//
// 008bd230  dd4138               fld qword ptr [ecx + 0x38]
// 008bd233  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008bd230 {
    char pad[56];
    double m_x;
    double f();
};
double S_func_008bd230::f()
{
    return m_x;
}
