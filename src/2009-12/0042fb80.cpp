// from server: 100% by atomic.potato
struct CDeclarationView
{
    char padding[0xb0];
    void *fieldB0;
    void f(void *, void **);
};

struct Helper
{
    void f(void *);
};

void CDeclarationView::f(void *arg1, void **arg2)
{
    if (fieldB0 != 0)
        ((Helper *)fieldB0)->f(*(void **)((char *)arg1 + 0x5c));
    *arg2 = 0;
}
