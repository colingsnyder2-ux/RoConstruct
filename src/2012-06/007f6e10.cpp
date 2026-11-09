// roc 2012-06 007f6e10  unit: RBX::ScriptInformationProvider  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007f6e10
//
// 007f6e10  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007f6e13  e9c85e0c00           jmp 0x8bcce0
// auto-matched from its assembly shape

struct P_func_007f6e10 { void g(); };
struct S_func_007f6e10 {
    char pad[12];
    P_func_007f6e10* m_p;
    void f();
};
void S_func_007f6e10::f()
{
    m_p->g();
}
