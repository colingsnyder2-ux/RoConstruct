// from server: 69% by atomic.potato
extern "C" void *sub_76dc90(void *, void *);
extern "C" void sub_76a190(void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    void *v;
    v = sub_76dc90(this, (char *)p + 4);
    v = *(void **)v;
    sub_76a190(this, &v);
}
