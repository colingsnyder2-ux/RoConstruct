// from server: 100% by colin
struct Sub {
    void f1(int);
    void f2(int);
};

struct CScintillaView {
    char pad0[0x58];
    Sub sub;
    void method();
};

void CScintillaView::method()
{
    sub.f1(1);
    sub.f2(1);
}
