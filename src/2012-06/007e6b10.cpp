// roc 2012-06 007e6b10  unit: CXTPReportControl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e6b10
//
// 007e6b10  8a81e9020000         mov al, byte ptr [ecx + 0x2e9]
// 007e6b16  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007e6b10 {
    char pad0[745];
    char m_x;
    char f();
};
char S_func_007e6b10::f()
{
    return m_x;
}
