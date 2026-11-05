// roc 2012-06 009b42b0  unit: RBX::VirtualHardwareDevice  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b42b0
//
// 009b42b0  8b4138               mov eax, dword ptr [ecx + 0x38]
// 009b42b3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009b42b0 {
    char pad0[56];
    int m_x;
    int f();
};
int S_func_009b42b0::f()
{
    return m_x;
}
