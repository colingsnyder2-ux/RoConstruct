// from server: 41% by atomic.potato
struct S
{
    void f();
};

extern "C" void __stdcall G(void *);

void S::f()
{
    G((void *)0x00ba1f38);
}
