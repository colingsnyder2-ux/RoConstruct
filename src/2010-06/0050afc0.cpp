// from server: 80% by atomic.potato
struct T
{
    void __cdecl g(void *, void *);
};

struct S
{
    void f(void *, void *);
};

void __thiscall S::f(void *a, void *b)
{
    ((T *)((char *)this + 0xe24))->g(a, b);
}
