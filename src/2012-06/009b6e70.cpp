// roc 2012-06 009b6e70  unit: RBX::VirtualHardwareDevice  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b6e70
//
// 009b6e70  8b442404             mov eax, dword ptr [esp + 4]
// 009b6e74  894138               mov dword ptr [ecx + 0x38], eax
// 009b6e77  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_009b6e70 {
    char pad0[56];
    int m_x;
    void f(int a1);
};
void S_func_009b6e70::f(int a1)
{
    m_x = (int)a1;
}
