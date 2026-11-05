// from server: 100% by atomic.potato
extern "C" void __stdcall sub_40C080(void *);

struct S
{
    void f(unsigned char);
};

void S::f(unsigned char value)
{
    if (value != *(unsigned char *)((char *)this + 0xf4))
    {
        *(unsigned char *)0xb7dc08 = value;
        *(unsigned char *)((char *)this + 0xf4) = value;
        sub_40C080((void *)0xb7aeb0);
    }
}
