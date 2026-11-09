// roc 2012-06 00a1e580  unit: CXTPRibbonBar  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1e580
//
// 00a1e580  8b815c020000         mov eax, dword ptr [ecx + 0x25c]
// 00a1e586  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a1e580 {
    char pad0[604];
    int m_x;
    int f();
};
int S_func_00a1e580::f()
{
    return m_x;
}
