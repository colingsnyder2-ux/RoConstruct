// roc 2012-06 00749060  unit: CPropGrid::UpdateItemsJob  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00749060
//
// 00749060  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 00749066  e995ef1600           jmp 0x8b8000
// auto-matched from its assembly shape

struct P_func_00749060 { void g(); };
struct S_func_00749060 {
    char pad[156];
    P_func_00749060* m_p;
    void f();
};
void S_func_00749060::f()
{
    m_p->g();
}
