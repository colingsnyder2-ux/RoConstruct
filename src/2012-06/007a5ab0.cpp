// roc 2012-06 007a5ab0  unit: RBX::VirtualHardwareDevice  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a5ab0
//
// 007a5ab0  d981b4000000         fld dword ptr [ecx + 0xb4]
// 007a5ab6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007a5ab0 {
    char pad[180];
    float m_x;
    float f();
};
float S_func_007a5ab0::f()
{
    return m_x;
}
