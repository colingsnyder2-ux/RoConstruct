// roc 2012-06 008e2160  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e2160
//
// 008e2160  d9819c030000         fld dword ptr [ecx + 0x39c]
// 008e2166  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e2160 {
    char pad[924];
    float m_x;
    float f();
};
float S_func_008e2160::f()
{
    return m_x;
}
