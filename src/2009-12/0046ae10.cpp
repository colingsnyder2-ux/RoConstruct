// from server: 100% by atomic.potato
struct CScintillaCtrl
{
    void f(int);
};

struct CScintillaView
{
    void f();
};

void CScintillaView::f()
{
    ((CScintillaCtrl *)((char *)this + 0x58))->f(1);
}
