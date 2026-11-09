// roc 2012-06 008dafc0  unit: RBX::VSelectionBox::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008dafc0
//
// 008dafc0  8b81a4030000         mov eax, dword ptr [ecx + 0x3a4]
// 008dafc6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008dafc0 {
    char pad0[932];
    int m_x;
    int f();
};
int S_func_008dafc0::f()
{
    return m_x;
}
