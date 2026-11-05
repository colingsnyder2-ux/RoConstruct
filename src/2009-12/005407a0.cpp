// from server: 77% by atomic.potato
struct S {};

extern "C" void *__cdecl sub_53f2f0(void *);
extern "C" void __cdecl sub_533260(void *, void *, void *);

void __cdecl sub_5407a0(void *a, void *b, void *c, void *d)
{
    struct T
    {
        void *a;
        void *b;
    } t;

    void *p = sub_53f2f0(a);
    t.a = *(void **)p;
    t.b = *((void **)p + 1);
    sub_533260(b, c, &t);
}
