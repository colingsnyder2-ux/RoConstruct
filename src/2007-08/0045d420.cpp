// from server: 100% by colin
struct Inner {
    void sub_45CC00(int);
};

struct CScintillaView {
    char pad[0x58];
    Inner inner;
    void func_45D420();
};

void CScintillaView::func_45D420()
{
    inner.sub_45CC00(1);
}
