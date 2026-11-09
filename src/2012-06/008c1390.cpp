// roc 2012-06 008c1390  unit: RBX::BillboardGui  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008c1390
//
// 008c1390  8b81cc000000         mov eax, dword ptr [ecx + 0xcc]
// 008c1396  83c05c               add eax, 0x5c
// 008c1399  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008c1390 {
    char pad0[204];
    int m_x;
    int f();
};
int S_func_008c1390::f()
{
    return m_x + 0x5c;
}
