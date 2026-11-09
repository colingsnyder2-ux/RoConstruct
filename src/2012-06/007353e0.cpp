// roc 2012-06 007353e0  unit: RBX::VFrame::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007353e0
//
// 007353e0  8b8140010000         mov eax, dword ptr [ecx + 0x140]
// 007353e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007353e0 {
    char pad0[320];
    int m_x;
    int f();
};
int S_func_007353e0::f()
{
    return m_x;
}
