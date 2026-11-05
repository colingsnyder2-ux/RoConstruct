// roc 2012-06 007b90d0  unit: RBX::TextureProxyBase  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b90d0
//
// 007b90d0  d94110               fld dword ptr [ecx + 0x10]
// 007b90d3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007b90d0 {
    char pad[16];
    float m_x;
    float f();
};
float S_func_007b90d0::f()
{
    return m_x;
}
