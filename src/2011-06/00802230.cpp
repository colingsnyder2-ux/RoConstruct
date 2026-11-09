// from server: 40% by atomic.potato
extern "C" void __stdcall rbx_call(void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    rbx_call(*(void **)this, p);
}
