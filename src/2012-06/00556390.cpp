// roc 2012-06 00556390  unit: RBX::Network::ServerReplicator  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00556390
//
// 00556390  8b815c1f0000         mov eax, dword ptr [ecx + 0x1f5c]
// 00556396  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00556390 {
    char pad0[8028];
    int m_x;
    int f();
};
int S_func_00556390::f()
{
    return m_x;
}
