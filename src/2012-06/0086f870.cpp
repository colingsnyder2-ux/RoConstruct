// roc 2012-06 0086f870  unit: RBX::VDebrisService::?$BoundFuncDesc  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0086f870
//
// 0086f870  8b442404             mov eax, dword ptr [esp + 4]
// 0086f874  8981f4000000         mov dword ptr [ecx + 0xf4], eax
// 0086f87a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_0086f870 {
    char pad0[244];
    int m_x;
    void f(int a1);
};
void S_func_0086f870::f(int a1)
{
    m_x = (int)a1;
}
