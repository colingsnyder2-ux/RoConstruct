// roc 2012-06 00a1cc10  unit: CXTPMenuBar::CControlMDIButton  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1cc10
//
// 00a1cc10  8b89bc010000         mov ecx, dword ptr [ecx + 0x1bc]
// 00a1cc16  e9b5f9ffff           jmp 0xa1c5d0
// auto-matched from its assembly shape

struct P_func_00a1cc10 { void g(); };
struct S_func_00a1cc10 {
    char pad[444];
    P_func_00a1cc10* m_p;
    void f();
};
void S_func_00a1cc10::f()
{
    m_p->g();
}
