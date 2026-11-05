// roc 2012-06 00751730  unit: RBX::PartInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00751730
//
// 00751730  8b8998010000         mov ecx, dword ptr [ecx + 0x198]
// 00751736  e9d59f0600           jmp 0x7bb710
// auto-matched from its assembly shape

struct P_func_00751730 { void g(); };
struct S_func_00751730 {
    char pad[408];
    P_func_00751730* m_p;
    void f();
};
void S_func_00751730::f()
{
    m_p->g();
}
