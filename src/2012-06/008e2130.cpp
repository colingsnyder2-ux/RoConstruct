// roc 2012-06 008e2130  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e2130
//
// 008e2130  8a81a4030000         mov al, byte ptr [ecx + 0x3a4]
// 008e2136  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e2130 {
    char pad0[932];
    char m_x;
    char f();
};
char S_func_008e2130::f()
{
    return m_x;
}
