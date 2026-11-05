// roc 2012-06 0059a0a0  unit: RBX::Network::Marker  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059a0a0
//
// 0059a0a0  8b81c0080000         mov eax, dword ptr [ecx + 0x8c0]
// 0059a0a6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0059a0a0 {
    char pad0[2240];
    int m_x;
    int f();
};
int S_func_0059a0a0::f()
{
    return m_x;
}
