// from server: 69% by atomic.potato
struct S
{
    void *f(void *p);
};

extern "C" void *fn761f80(void *, void *);
extern "C" void *fn76a190(void *, void *);

void *S::f(void *p)
{
    void *v;
    v = fn761f80(this, (char *)p + 4);
    v = *(void **)v;
    return fn76a190(this, &v);
}
