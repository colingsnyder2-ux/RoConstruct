// roc 2012-06 008e2120  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e2120
//
// 008e2120  8b81a8030000         mov eax, dword ptr [ecx + 0x3a8]
// 008e2126  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e2120 {
    char pad0[936];
    int m_x;
    int f();
};
int S_func_008e2120::f()
{
    return m_x;
}
