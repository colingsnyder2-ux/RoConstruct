// roc 2012-06 007bb710  unit: RBX::Primitive  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007bb710
//
// 007bb710  8b8908010000         mov ecx, dword ptr [ecx + 0x108]
// 007bb716  e9d5f5ffff           jmp 0x7bacf0
// auto-matched from its assembly shape

struct P_func_007bb710 { void g(); };
struct S_func_007bb710 {
    char pad[264];
    P_func_007bb710* m_p;
    void f();
};
void S_func_007bb710::f()
{
    m_p->g();
}
