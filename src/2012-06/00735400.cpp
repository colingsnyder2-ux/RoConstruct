// roc 2012-06 00735400  unit: RBX::VFrame::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00735400
//
// 00735400  8a815c010000         mov al, byte ptr [ecx + 0x15c]
// 00735406  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00735400 {
    char pad0[348];
    char m_x;
    char f();
};
char S_func_00735400::f()
{
    return m_x;
}
