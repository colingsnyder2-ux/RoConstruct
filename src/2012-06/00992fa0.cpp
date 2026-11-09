// roc 2012-06 00992fa0  unit: CXTPCommandBar  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00992fa0
//
// 00992fa0  8b81c8000000         mov eax, dword ptr [ecx + 0xc8]
// 00992fa6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00992fa0 {
    char pad0[200];
    int m_x;
    int f();
};
int S_func_00992fa0::f()
{
    return m_x;
}
