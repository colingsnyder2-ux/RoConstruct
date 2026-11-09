// roc 2012-06 00992b80  unit: CXTPCommandBar  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00992b80
//
// 00992b80  8b8178010000         mov eax, dword ptr [ecx + 0x178]
// 00992b86  8b4014               mov eax, dword ptr [eax + 0x14]
// 00992b89  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00992b80 {
    char pad[20];
    int m_x;
};
struct S_func_00992b80 {
    char pad[376];
    I_func_00992b80* m_p;
    int f();
};
int S_func_00992b80::f()
{
    return m_p->m_x;
}
