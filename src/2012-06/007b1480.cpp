// roc 2012-06 007b1480  unit: std::D::DU?$char_traits::V?$basic_string::?$MemEnforcedLRUCache  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b1480
//
// 007b1480  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 007b1486  e965faffff           jmp 0x7b0ef0
// auto-matched from its assembly shape

struct P_func_007b1480 { void g(); };
struct S_func_007b1480 {
    char pad[156];
    P_func_007b1480* m_p;
    void f();
};
void S_func_007b1480::f()
{
    m_p->g();
}
