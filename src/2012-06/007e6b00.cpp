// roc 2012-06 007e6b00  unit: CXTPReportControl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e6b00
//
// 007e6b00  8a81e8020000         mov al, byte ptr [ecx + 0x2e8]
// 007e6b06  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007e6b00 {
    char pad0[744];
    char m_x;
    char f();
};
char S_func_007e6b00::f()
{
    return m_x;
}
