// roc 2012-06 007e69f0  unit: CXTPReportControl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e69f0
//
// 007e69f0  8a81b1000000         mov al, byte ptr [ecx + 0xb1]
// 007e69f6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007e69f0 {
    char pad0[177];
    char m_x;
    char f();
};
char S_func_007e69f0::f()
{
    return m_x;
}
