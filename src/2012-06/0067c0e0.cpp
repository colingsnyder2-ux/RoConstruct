// from server: 73% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void *__cdecl sub_67afd0(void *);
extern "C" void sub_76a190(S *, void *);

int S::f(int value)
{
    void *p;
    p = sub_67afd0((char *)value + 4);
    p = *(void **)p;
    sub_76a190(this, &p);
    return 0;
}
