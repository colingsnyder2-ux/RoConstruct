// roc 2012-06 008c1380  unit: RBX::BillboardGui  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008c1380
//
// 008c1380  8b81cc000000         mov eax, dword ptr [ecx + 0xcc]
// 008c1386  83c068               add eax, 0x68
// 008c1389  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008c1380 {
    char pad0[204];
    int m_x;
    int f();
};
int S_func_008c1380::f()
{
    return m_x + 0x68;
}
