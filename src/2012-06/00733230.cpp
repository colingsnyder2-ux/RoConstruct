// roc 2012-06 00733230  unit: RBX::VGuiMain::?$FactoryProduct  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00733230
//
// 00733230  8a4159               mov al, byte ptr [ecx + 0x59]
// 00733233  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00733230 {
    char pad0[89];
    char m_x;
    char f();
};
char S_func_00733230::f()
{
    return m_x;
}
