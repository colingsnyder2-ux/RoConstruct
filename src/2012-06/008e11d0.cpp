// roc 2012-06 008e11d0  unit: RBX::VSkateboardPlatform::?$EventDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e11d0
//
// 008e11d0  d981b8000000         fld dword ptr [ecx + 0xb8]
// 008e11d6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e11d0 {
    char pad[184];
    float m_x;
    float f();
};
float S_func_008e11d0::f()
{
    return m_x;
}
