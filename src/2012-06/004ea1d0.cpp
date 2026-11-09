// roc 2012-06 004ea1d0  unit: RBX::TextureProxyBase  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ea1d0
//
// 004ea1d0  8b442404             mov eax, dword ptr [esp + 4]
// 004ea1d4  89410c               mov dword ptr [ecx + 0xc], eax
// 004ea1d7  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_004ea1d0 {
    char pad0[12];
    int m_x;
    void f(int a1);
};
void S_func_004ea1d0::f(int a1)
{
    m_x = (int)a1;
}
