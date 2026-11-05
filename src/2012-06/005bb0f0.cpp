// roc 2012-06 005bb0f0  unit: RakNet::RakPeer  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb0f0
//
// 005bb0f0  8b8184040000         mov eax, dword ptr [ecx + 0x484]
// 005bb0f6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_005bb0f0 {
    char pad0[1156];
    int m_x;
    int f();
};
int S_func_005bb0f0::f()
{
    return m_x;
}
