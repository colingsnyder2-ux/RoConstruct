// roc 2012-06 008e2190  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e2190
//
// 008e2190  8d81d0020000         lea eax, [ecx + 0x2d0]
// 008e2196  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e2190 {
    char pad0[720];
    int m_x;
    int* f();
};
int* S_func_008e2190::f()
{
    return &m_x;
}
