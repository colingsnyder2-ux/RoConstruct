// roc 2012-06 008c4670  unit: RBX::VClickDetector::?$EventDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008c4670
//
// 008c4670  d9818c000000         fld dword ptr [ecx + 0x8c]
// 008c4676  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008c4670 {
    char pad[140];
    float m_x;
    float f();
};
float S_func_008c4670::f()
{
    return m_x;
}
