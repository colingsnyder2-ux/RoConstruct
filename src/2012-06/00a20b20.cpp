// roc 2012-06 00a20b20  unit: CXTPRibbonBar  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a20b20
//
// 00a20b20  8b8168020000         mov eax, dword ptr [ecx + 0x268]
// 00a20b26  8b80e0010000         mov eax, dword ptr [eax + 0x1e0]
// 00a20b2c  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00a20b20 {
    char pad[480];
    int m_x;
};
struct S_func_00a20b20 {
    char pad[616];
    I_func_00a20b20* m_p;
    int f();
};
int S_func_00a20b20::f()
{
    return m_p->m_x;
}
