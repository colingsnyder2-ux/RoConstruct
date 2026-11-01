// from server: 100% by colin
struct CScintillaView {
    char pad[0x58];
    struct Inner {
        int f(int, int);
        int g(int, int);
    } inner;
    int SetDocPointer(int);
};

int CScintillaView::SetDocPointer(int doc) {
    int r = inner.f(*(int*)((char*)doc + 0xc), 1);
    return inner.g(r, 1);
}
