// from server: 100% by colin
struct Inner {
    void method(int);
};

struct CScintillaView {
    char pad[0x58];
    Inner inner;
    void func();
};

void CScintillaView::func()
{
    inner.method(1);
}
