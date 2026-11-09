// roc 2012-06 009ee3b0  unit: CXTPPropertyGridView  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ee3b0
//
// 009ee3b0  8b81b0000000         mov eax, dword ptr [ecx + 0xb0]
// 009ee3b6  8b8044010000         mov eax, dword ptr [eax + 0x144]
// 009ee3bc  c3                   ret 
// auto-matched from its assembly shape

struct I_func_009ee3b0 {
    char pad[324];
    int m_x;
};
struct S_func_009ee3b0 {
    char pad[176];
    I_func_009ee3b0* m_p;
    int f();
};
int S_func_009ee3b0::f()
{
    return m_p->m_x;
}
