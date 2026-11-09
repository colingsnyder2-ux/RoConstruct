// from server: 76% by atomic.potato
struct S
{
    void f(void *);
};

void S::f(void *value)
{
    if (*(void **)((char *)this + 0x150) == value)
        return;

    if (*(unsigned char *)((char *)this + 0x95) == 0)
    {
        *(void **)((char *)this + 0x150) = value;
        return;
    }

    *(void **)((char *)this + 0x150) = (void *)0xc1cb90;
}
