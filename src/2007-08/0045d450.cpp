// from server: 100% by colin
struct Inner {
    void Target(int);
};

struct CScintillaView {
    char pad[0x58];
    Inner inner;
    void Method();
};

void CScintillaView::Method() {
    inner.Target(1);
}
