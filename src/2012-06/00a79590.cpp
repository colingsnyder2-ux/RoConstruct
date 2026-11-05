// roc 2012-06 00a79590  unit: CXTMemDC  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a79590
//
// 00a79590  c7411400000000       mov dword ptr [ecx + 0x14], 0
// 00a79597  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a79590 {
    char pad0[20];
    int m_x;
    void f();
};
void S_func_00a79590::f()
{
    m_x = (int)0;
}
