// from server: 69% by atomic.potato
struct S
{
    void f(void *);
};

extern "C" void *sub_76c790(void *, void *);
extern "C" void sub_76a190(void *, void *);

void S::f(void *p)
{
    void *v;
    v = sub_76c790(this, (char *)p + 4);
    v = *(void **)v;
    sub_76a190(this, &v);
}
