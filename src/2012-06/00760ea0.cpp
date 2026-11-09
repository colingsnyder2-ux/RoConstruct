// roc 2012-06 00760ea0  unit: RBX::Network::VPlayer::?$BoundPropGetSet  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00760ea0
//
// 00760ea0  8b81b8000000         mov eax, dword ptr [ecx + 0xb8]
// 00760ea6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00760ea0 {
    char pad0[184];
    int m_x;
    int f();
};
int S_func_00760ea0::f()
{
    return m_x;
}
