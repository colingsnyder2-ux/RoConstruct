// roc 2012-06 008dafe0  unit: RBX::VSelectionBox::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008dafe0
//
// 008dafe0  8a81cc030000         mov al, byte ptr [ecx + 0x3cc]
// 008dafe6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008dafe0 {
    char pad0[972];
    char m_x;
    char f();
};
char S_func_008dafe0::f()
{
    return m_x;
}
