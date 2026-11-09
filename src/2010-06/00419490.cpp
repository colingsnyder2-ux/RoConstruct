// from server: 61% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
}

extern "C" void __stdcall Target(S *p);

void __stdcall Wrapper(S *p)
{
    Target((S *)((char *)p - 0xF0));
}
