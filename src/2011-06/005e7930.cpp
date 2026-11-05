// from server: 100% by atomic.potato
extern "C" void __stdcall sub_80B1D8(void *, int, int, void *);

struct S
{
    void f();
};

void S::f()
{
    sub_80B1D8(this, 8, 10, (void *)0x7736f0);
}
