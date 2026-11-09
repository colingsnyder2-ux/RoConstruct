// from server: 75% by atomic.potato
extern "C" void sub_0040C080(void *);

struct S
{
    void f(void *);
};

void S::f(void *value)
{
    if (*(void **)((char *)this + 0xbc) != value)
    {
        *(void **)((char *)this + 0xbc) = value;
        sub_0040C080((void *)0x00b972f0);
    }
}
