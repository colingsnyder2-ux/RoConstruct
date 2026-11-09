// from server: 73% by atomic.potato
struct S
{
    void *f(void *);
    void g(void *);
};

extern "C" void *fn_76c250(void *, void *);
extern "C" void fn_76a190(void *, void *);

void S::g(void *p)
{
    void *v = fn_76c250(this, (char *)p + 4);
    void *q = *(void **)v;
    fn_76a190(this, &q);
}
