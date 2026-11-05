// roc 2012-06 00993b00  unit: CXTPCommandBar  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00993b00
//
// 00993b00  8b81fc000000         mov eax, dword ptr [ecx + 0xfc]
// 00993b06  8b402c               mov eax, dword ptr [eax + 0x2c]
// 00993b09  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00993b00 {
    char pad[44];
    int m_x;
};
struct S_func_00993b00 {
    char pad[252];
    I_func_00993b00* m_p;
    int f();
};
int S_func_00993b00::f()
{
    return m_p->m_x;
}
