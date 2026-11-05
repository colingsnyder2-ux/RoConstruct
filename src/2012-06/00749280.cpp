// roc 2012-06 00749280  unit: RBX::ContentProvider  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00749280
//
// 00749280  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 00749286  e965281700           jmp 0x8bbaf0
// auto-matched from its assembly shape

struct P_func_00749280 { void g(); };
struct S_func_00749280 {
    char pad[156];
    P_func_00749280* m_p;
    void f();
};
void S_func_00749280::f()
{
    m_p->g();
}
