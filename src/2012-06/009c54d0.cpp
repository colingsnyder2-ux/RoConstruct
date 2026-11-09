// roc 2012-06 009c54d0  unit: CXTPCommandBar  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c54d0
//
// 009c54d0  8b89fc000000         mov ecx, dword ptr [ecx + 0xfc]
// 009c54d6  e955e6ffff           jmp 0x9c3b30
// auto-matched from its assembly shape

struct P_func_009c54d0 { void g(); };
struct S_func_009c54d0 {
    char pad[252];
    P_func_009c54d0* m_p;
    void f();
};
void S_func_009c54d0::f()
{
    m_p->g();
}
