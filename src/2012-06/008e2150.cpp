// roc 2012-06 008e2150  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e2150
//
// 008e2150  d98198030000         fld dword ptr [ecx + 0x398]
// 008e2156  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e2150 {
    char pad[920];
    float m_x;
    float f();
};
float S_func_008e2150::f()
{
    return m_x;
}
