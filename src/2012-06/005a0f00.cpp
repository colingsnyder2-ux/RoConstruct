// roc 2012-06 005a0f00  unit: RBX::Network::ClientReplicator  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a0f00
//
// 005a0f00  8a81641f0000         mov al, byte ptr [ecx + 0x1f64]
// 005a0f06  c3                   ret 
// auto-matched from its assembly shape

struct S_func_005a0f00 {
    char pad0[8036];
    char m_x;
    char f();
};
char S_func_005a0f00::f()
{
    return m_x;
}
