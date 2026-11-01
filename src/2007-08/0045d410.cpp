// from server: 100% by colin
struct Inner_0045cbd0 {
    void method(int);
};

struct CScintillaView {
    char pad[0x58];
    Inner_0045cbd0 inner;
    void func_0045d410();
};

void CScintillaView::func_0045d410()
{
    inner.method(1);
}
