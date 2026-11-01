// from server: 91% by atomic.potato
struct S
{
    void f();
};

extern "C" void __stdcall sub_0040C080(void *, const void *);

void S::f()
{
    sub_0040C080((char *)this - 0xa4, (const void *)0x00b92a00);
}
