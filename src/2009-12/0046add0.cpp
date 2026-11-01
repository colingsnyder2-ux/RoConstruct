// from server: 100% by nuck16
// roc 2009-12 0046add0  (same-shape propagation from exact 0046adc0)

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
    ((CScintillaCtrl*)((char*)this + 0x58))->f(1);
}
