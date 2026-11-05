// roc 2012-06 0086f880  unit: RBX::VDebrisService::?$BoundFuncDesc  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0086f880
//
// 0086f880  8b442404             mov eax, dword ptr [esp + 4]
// 0086f884  8981f8000000         mov dword ptr [ecx + 0xf8], eax
// 0086f88a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_0086f880 {
    char pad0[248];
    int m_x;
    void f(int a1);
};
void S_func_0086f880::f(int a1)
{
    m_x = (int)a1;
}
