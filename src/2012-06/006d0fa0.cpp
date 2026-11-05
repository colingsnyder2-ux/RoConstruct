// roc 2012-06 006d0fa0  unit: RBX::DataModel  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d0fa0
//
// 006d0fa0  8b89cc0a0000         mov ecx, dword ptr [ecx + 0xacc]
// 006d0fa6  e905820b00           jmp 0x7891b0
// auto-matched from its assembly shape

struct P_func_006d0fa0 { void g(); };
struct S_func_006d0fa0 {
    char pad[2764];
    P_func_006d0fa0* m_p;
    void f();
};
void S_func_006d0fa0::f()
{
    m_p->g();
}
