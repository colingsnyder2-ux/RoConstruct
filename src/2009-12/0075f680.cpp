// from server: 95% by atomic.potato
extern "C" void __cdecl sub_0040c080(const void *);

struct S
{
    void f(const void *);
};

void S::f(const void *value)
{
    if (*(const void **)((char *)this + 0xa8) != value)
    {
        *(const void **)((char *)this + 0xa8) = value;
        sub_0040c080((const void *)0xb97a0c);
    }
}
