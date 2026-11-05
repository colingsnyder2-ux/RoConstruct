// roc 2012-06 008e2140  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e2140
//
// 008e2140  8b81ac030000         mov eax, dword ptr [ecx + 0x3ac]
// 008e2146  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e2140 {
    char pad0[940];
    int m_x;
    int f();
};
int S_func_008e2140::f()
{
    return m_x;
}
