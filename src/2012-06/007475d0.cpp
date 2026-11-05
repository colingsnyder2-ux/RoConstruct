// from server: 73% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" void *sub_746b00(void *, void *);
extern "C" int sub_747250(void *, void *);

int S::f(void *p)
{
    void *v = sub_746b00(this, (char *)p + 4);
    void *q = *(void **)v;
    return sub_747250(this, &q);
}
