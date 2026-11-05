// from server: 71% by atomic.potato
extern "C" void __cdecl Target(void *, void *, void *, void *);

struct S {
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    Target(a, b, *(void **)((char *)this + 8), a);
}
