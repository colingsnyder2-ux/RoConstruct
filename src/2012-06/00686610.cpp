// roc 2012-06 00686610  unit: RBX::VInstance::?$EventDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00686610
//
// 00686610  d9815c010000         fld dword ptr [ecx + 0x15c]
// 00686616  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00686610 {
    char pad[348];
    float m_x;
    float f();
};
float S_func_00686610::f()
{
    return m_x;
}
