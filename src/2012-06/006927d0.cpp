// roc 2012-06 006927d0  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006927d0
//
// 006927d0  d981b0000000         fld dword ptr [ecx + 0xb0]
// 006927d6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006927d0 {
    char pad[176];
    float m_x;
    float f();
};
float S_func_006927d0::f()
{
    return m_x;
}
