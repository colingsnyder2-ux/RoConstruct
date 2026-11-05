// roc 2012-06 00751770  unit: RBX::PartInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00751770
//
// 00751770  8b8998010000         mov ecx, dword ptr [ecx + 0x198]
// 00751776  e9a57d0600           jmp 0x7b9520
// auto-matched from its assembly shape

struct P_func_00751770 { void g(); };
struct S_func_00751770 {
    char pad[408];
    P_func_00751770* m_p;
    void f();
};
void S_func_00751770::f()
{
    m_p->g();
}
