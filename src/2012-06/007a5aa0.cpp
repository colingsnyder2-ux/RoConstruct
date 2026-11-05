// roc 2012-06 007a5aa0  unit: RBX::VirtualHardwareDevice  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a5aa0
//
// 007a5aa0  8d8180000000         lea eax, [ecx + 0x80]
// 007a5aa6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007a5aa0 {
    char pad0[128];
    int m_x;
    int* f();
};
int* S_func_007a5aa0::f()
{
    return &m_x;
}
