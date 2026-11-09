// roc 2012-06 0098ea70  unit: CXTPCommandBar  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0098ea70
//
// 0098ea70  8b8138010000         mov eax, dword ptr [ecx + 0x138]
// 0098ea76  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0098ea70 {
    char pad0[312];
    int m_x;
    int f();
};
int S_func_0098ea70::f()
{
    return m_x;
}
