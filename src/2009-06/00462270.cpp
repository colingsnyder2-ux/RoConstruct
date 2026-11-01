// from server: 100% by why2
struct Inner {
    void method(int);
};

struct CScintillaView {
    char pad[0x58];
    Inner inner;
    void method();
};

void CScintillaView::method()
{
    inner.method(1);
}
