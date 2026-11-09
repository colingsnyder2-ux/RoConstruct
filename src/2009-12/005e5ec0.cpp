// from server: 100% by atomic.potato
extern "C" void __stdcall f(void *, int, int, void *);

struct S {
    void g();
};

void S::g()
{
    f((char *)this + 4, 4, 16, (void *)0x4e4d20);
}
