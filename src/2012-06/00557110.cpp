// from server: 79% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" void *sub_5566F0(void *);
extern "C" int sub_76A190(void *, void *);

int S::f(void *p)
{
    void *v = sub_5566F0((char *)p + 4);
    void *value = *(void **)v;
    return sub_76A190(this, &value);
}
