// from server: 73% by atomic.potato
struct S
{
    void *f(void *p);
};

extern "C" void *sub_754F20(void *, void *);
extern "C" void *sub_76A190(void *, void *);

void *S::f(void *p)
{
    void *v = sub_754F20(this, (char *)p + 4);
    void *x = *(void **)v;
    return sub_76A190(this, &x);
}
