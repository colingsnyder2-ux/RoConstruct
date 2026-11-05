// from server: 77% by atomic.potato
extern "C" void *__cdecl sub_877990(void *, void *, int);

struct T
{
    void sub_878680();
};

struct S
{
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    void *p = sub_877990(a, b, 1);
    ((T *)p)->sub_878680();
}
