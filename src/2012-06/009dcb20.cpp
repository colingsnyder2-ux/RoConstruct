// roc 2012-06 009dcb20  unit: CXTPTabClientWnd  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009dcb20
//
// 009dcb20  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 009dcb26  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009dcb20 {
    char pad0[140];
    int m_x;
    int f();
};
int S_func_009dcb20::f()
{
    return m_x;
}
