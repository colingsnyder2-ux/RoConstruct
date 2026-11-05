// from server: 79% by atomic.potato
struct S
{
    void *f(void *);
    void *g(void *);
};

extern "C" void *__cdecl sub_67b0f0(void *);
extern "C" void *sub_76a190(S *, void *);

void *S::f(void *p)
{
    void *v = sub_67b0f0((char *)p + 4);
    void *x = *(void **)v;
    return sub_76a190(this, &x);
}
