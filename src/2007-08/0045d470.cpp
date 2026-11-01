// from server: 100% by colin
struct Inner {
    void sub_45C040(int);
};

struct CScintillaView {
    char pad[0x58];
    Inner inner;
    void f();
};

void CScintillaView::f() {
    inner.sub_45C040(1);
}
