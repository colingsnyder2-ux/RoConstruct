// from server: 77% by atomic.potato
extern "C" void *__cdecl sub_76d9f0(void *);
extern "C" void sub_76a190(void *, void *);

struct S
{
    void *f(void *);
};

void *S::f(void *p)
{
    void *q = sub_76d9f0((char *)p + 4);
    void *v = *(void **)q;
    sub_76a190(this, &v);
    return 0;
}
