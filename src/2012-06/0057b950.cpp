// roc 2012-06 0057b950  unit: RBX::Network::Replicator::NewInstanceItem  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0057b950
//
// 0057b950  8b89441a0000         mov ecx, dword ptr [ecx + 0x1a44]
// 0057b956  e975f9ffff           jmp 0x57b2d0
// auto-matched from its assembly shape

struct P_func_0057b950 { void g(); };
struct S_func_0057b950 {
    char pad[6724];
    P_func_0057b950* m_p;
    void f();
};
void S_func_0057b950::f()
{
    m_p->g();
}
