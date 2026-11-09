// roc 2012-06 00736070  unit: RBX::BuoyancyContact  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00736070
//
// 00736070  8b414c               mov eax, dword ptr [ecx + 0x4c]
// 00736073  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00736070 {
    char pad0[76];
    int m_x;
    int f();
};
int S_func_00736070::f()
{
    return m_x;
}
