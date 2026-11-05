// from server: 100% by atomic.potato
extern "C" void __stdcall g(void *, int, int, void *);

struct S
{
    void f();
};

void S::f()
{
    g(this, 0x30, 2, (void *)0x854a90);
}
