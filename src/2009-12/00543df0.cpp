// from server: 50% by atomic.potato
extern "C" void __cdecl f004164b0(const char *, ...);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    f004164b0("d$,P", p);
}
