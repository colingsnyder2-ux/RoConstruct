// from server: 100% by atomic.potato
struct CDeclarationView;

typedef void (CDeclarationView::*Method0)();
typedef void (CDeclarationView::*Method1)(int);

struct CDeclarationView
{
    void f();
    void g();
    void h(int);
};

void CDeclarationView::f()
{
    g();
    h(210);
}
