// roc 2012-06 009cec90  unit: CXTPPopupBar::CControlExpandButton  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009cec90
//
// 009cec90  8b8900010000         mov ecx, dword ptr [ecx + 0x100]
// 009cec96  e925f7ffff           jmp 0x9ce3c0
// auto-matched from its assembly shape

struct P_func_009cec90 { void g(); };
struct S_func_009cec90 {
    char pad[256];
    P_func_009cec90* m_p;
    void f();
};
void S_func_009cec90::f()
{
    m_p->g();
}
