// roc 2012-06 009a2250  unit: CXTPCommandBars  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a2250
//
// 009a2250  8b81b4000000         mov eax, dword ptr [ecx + 0xb4]
// 009a2256  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009a2250 {
    char pad0[180];
    int m_x;
    int f();
};
int S_func_009a2250::f()
{
    return m_x;
}
