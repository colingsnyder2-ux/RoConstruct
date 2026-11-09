// from server: 100% by colin
struct Inner {
    void sub_45CC30(int);
};

struct CScintillaView {
    char pad[0x58];
    Inner inner;
    void f();
};

void CScintillaView::f() {
    inner.sub_45CC30(1);
}
