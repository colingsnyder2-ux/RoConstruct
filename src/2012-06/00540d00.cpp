// roc 2012-06 00540d00  unit: RBX::VObjectValue::?$FactoryProduct::Creator  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00540d00
//
// 00540d00  8b81ac010000         mov eax, dword ptr [ecx + 0x1ac]
// 00540d06  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00540d00 {
    char pad0[428];
    int m_x;
    int f();
};
int S_func_00540d00::f()
{
    return m_x;
}
