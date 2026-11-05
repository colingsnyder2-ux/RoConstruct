// roc 2012-06 007491f0  unit: RBX::ContentProvider  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007491f0
//
// 007491f0  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 007491f3  e9e83a1700           jmp 0x8bcce0
// auto-matched from its assembly shape

struct P_func_007491f0 { void g(); };
struct S_func_007491f0 {
    char pad[28];
    P_func_007491f0* m_p;
    void f();
};
void S_func_007491f0::f()
{
    m_p->g();
}
