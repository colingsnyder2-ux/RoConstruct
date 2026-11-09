// roc 2012-06 005a2d00  unit: RBX::Network::ClientReplicator  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a2d00
//
// 005a2d00  c60101               mov byte ptr [ecx], 1
// 005a2d03  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_005a2d00 {
    char m_x;
    void f(int a1);
};
void S_func_005a2d00::f(int a1)
{
    m_x = (char)1;
}
