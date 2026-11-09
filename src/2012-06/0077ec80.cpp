// from server: 79% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" void *__cdecl sub_76aa40(void *);
extern "C" int sub_76a190(void *, void *);

int S::f(void *p)
{
    void *v = sub_76aa40((char *)p + 4);
    void *q = *(void **)v;
    return sub_76a190(this, &q);
}
