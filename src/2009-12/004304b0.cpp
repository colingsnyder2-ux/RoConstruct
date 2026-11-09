// from server: 100% by atomic.potato
struct COutputView;

typedef void (COutputView::*COutputViewMethod)();

struct COutputView
{
    void f();
    void sub_007f3cbc();
    void sub_007f43b2(int);
};

void COutputView::f()
{
    sub_007f3cbc();
    sub_007f43b2(0x86);
}
