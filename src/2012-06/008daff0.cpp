// roc 2012-06 008daff0  unit: RBX::VSelectionBox::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008daff0
//
// 008daff0  8b81d8030000         mov eax, dword ptr [ecx + 0x3d8]
// 008daff6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008daff0 {
    char pad0[984];
    int m_x;
    int f();
};
int S_func_008daff0::f()
{
    return m_x;
}
