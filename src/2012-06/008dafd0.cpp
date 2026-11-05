// roc 2012-06 008dafd0  unit: RBX::VSelectionBox::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008dafd0
//
// 008dafd0  8b81bc030000         mov eax, dword ptr [ecx + 0x3bc]
// 008dafd6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008dafd0 {
    char pad0[956];
    int m_x;
    int f();
};
int S_func_008dafd0::f()
{
    return m_x;
}
