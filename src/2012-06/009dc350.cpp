// roc 2012-06 009dc350  unit: CXTPTabClientWnd::CWorkspace  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009dc350
//
// 009dc350  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 009dc356  8b80bc000000         mov eax, dword ptr [eax + 0xbc]
// 009dc35c  c3                   ret 
// auto-matched from its assembly shape

struct I_func_009dc350 {
    char pad[188];
    int m_x;
};
struct S_func_009dc350 {
    char pad[144];
    I_func_009dc350* m_p;
    int f();
};
int S_func_009dc350::f()
{
    return m_p->m_x;
}
