// roc 2012-06 0059a090  unit: RBX::Network::Marker  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059a090
//
// 0059a090  8b442404             mov eax, dword ptr [esp + 4]
// 0059a094  8981c0080000         mov dword ptr [ecx + 0x8c0], eax
// 0059a09a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_0059a090 {
    char pad0[2240];
    int m_x;
    void f(int a1);
};
void S_func_0059a090::f(int a1)
{
    m_x = (int)a1;
}
