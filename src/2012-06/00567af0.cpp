// roc 2012-06 00567af0  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567af0
//
// 00567af0  8b442404             mov eax, dword ptr [esp + 4]
// 00567af4  8901                 mov dword ptr [ecx], eax
// 00567af6  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00567af0 {
    int m_x;
    void f(int a1);
};
void S_func_00567af0::f(int a1)
{
    m_x = (int)a1;
}
