// roc 2012-06 00a13f20  unit: CXTPControlEdit  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a13f20
//
// 00a13f20  8b8190010000         mov eax, dword ptr [ecx + 0x190]
// 00a13f26  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a13f20 {
    char pad0[400];
    int m_x;
    int f();
};
int S_func_00a13f20::f()
{
    return m_x;
}
