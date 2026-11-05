// from server: 100% by atomic.potato
extern "C" void __cdecl target(void *, void *, void *, void *);

struct S
{
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    void *p = a ? (char *)a - 0x1c : 0;
    target(p, *(void **)((char *)this + 0x30),
           *(void **)((char *)this + 0x34), (char *)b + 4);
}
