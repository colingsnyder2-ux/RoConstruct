// from server: 51% by atomic.potato
extern "C" void func_00419618(void *, const void *);
extern "C" void func_0098B6F0(void *, void *);

struct CRBXHTMLControlSite
{
    int f(void *);
};

int CRBXHTMLControlSite::f(void *p)
{
    void *v = 0;
    func_00419618((char *)this + 24, &v);
    func_0098B6F0(p, v);
    return (int)p;
}
