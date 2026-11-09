// from server: 73% by atomic.potato
struct S
{
    void *f(void *);
    void *g(void *);
};

extern "C" void *sub_67b180(S *, void *);
extern "C" void *sub_76a190(S *, void *);

void *S::f(void *p)
{
    void *v = sub_67b180(this, (char *)p + 4);
    void *q = *(void **)v;
    return sub_76a190(this, &q);
}
