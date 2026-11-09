// roc 2012-06 00540710  unit: RBX::VObjectValue::?$FactoryProduct::Creator  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00540710
//
// 00540710  8b442404             mov eax, dword ptr [esp + 4]
// 00540714  8981b4010000         mov dword ptr [ecx + 0x1b4], eax
// 0054071a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00540710 {
    char pad0[436];
    int m_x;
    void f(int a1);
};
void S_func_00540710::f(int a1)
{
    m_x = (int)a1;
}
