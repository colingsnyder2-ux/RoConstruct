// roc 2012-06 00749070  unit: CPropGrid::UpdateItemsJob  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00749070
//
// 00749070  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 00749076  e9a5251700           jmp 0x8bb620
// auto-matched from its assembly shape

struct P_func_00749070 { void g(); };
struct S_func_00749070 {
    char pad[156];
    P_func_00749070* m_p;
    void f();
};
void S_func_00749070::f()
{
    m_p->g();
}
