// from server: 71% by atomic.potato
struct S
{
    void f(void *);
};

extern "C" void *__cdecl sub_7c5f90(void *);
extern "C" void __cdecl sub_76a190(S *, void *);

void S::f(void *p)
{
    void *v = sub_7c5f90((char *)p + 4);
    sub_76a190(this, *(void **)v);
}
