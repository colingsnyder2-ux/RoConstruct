// roc 2012-06 008e2170  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e2170
//
// 008e2170  d981a0030000         fld dword ptr [ecx + 0x3a0]
// 008e2176  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e2170 {
    char pad[928];
    float m_x;
    float f();
};
float S_func_008e2170::f()
{
    return m_x;
}
