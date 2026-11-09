// from server: 60% by atomic.potato
struct CIDEBrowserView
{
    int f();
};

int CIDEBrowserView::f()
{
    struct VTable
    {
        int (*f)(void*);
    };

    VTable* p = *(VTable**)((char*)this + 0xf0);
    return p->f(p);
}
