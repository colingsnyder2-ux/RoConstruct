// roc 2012-06 007e6af0  unit: CXTPReportControl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e6af0
//
// 007e6af0  8a81dd010000         mov al, byte ptr [ecx + 0x1dd]
// 007e6af6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007e6af0 {
    char pad0[477];
    char m_x;
    char f();
};
char S_func_007e6af0::f()
{
    return m_x;
}
