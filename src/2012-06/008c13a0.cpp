// roc 2012-06 008c13a0  unit: RBX::BillboardGui  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008c13a0
//
// 008c13a0  8b81cc000000         mov eax, dword ptr [ecx + 0xcc]
// 008c13a6  83c074               add eax, 0x74
// 008c13a9  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008c13a0 {
    char pad0[204];
    int m_x;
    int f();
};
int S_func_008c13a0::f()
{
    return m_x + 0x74;
}
