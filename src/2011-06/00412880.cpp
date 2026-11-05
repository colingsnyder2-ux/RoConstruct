// from server: 100% by atomic.potato
struct CIDEBrowserView
{
    unsigned char padding[0x2ad];
    unsigned char field_2ad;
    void f(void *);
};

void CIDEBrowserView::f(void *p)
{
    typedef void (__thiscall *Fn)(void *, int);
    Fn fn = *(Fn *)*(void **)p;
    fn(p, field_2ad);
}
