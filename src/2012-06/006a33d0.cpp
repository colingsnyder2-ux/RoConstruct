// roc 2012-06 006a33d0  unit: RBX::VScriptContext::?$FactoryProduct  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a33d0
//
// 006a33d0  8b897c020000         mov ecx, dword ptr [ecx + 0x27c]
// 006a33d6  e9d5231a00           jmp 0x8457b0
// auto-matched from its assembly shape

struct P_func_006a33d0 { void g(); };
struct S_func_006a33d0 {
    char pad[636];
    P_func_006a33d0* m_p;
    void f();
};
void S_func_006a33d0::f()
{
    m_p->g();
}
