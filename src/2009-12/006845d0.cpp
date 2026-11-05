// from server: 100% by atomic.potato
extern "C" void __stdcall target(void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    unsigned int value = *(unsigned int *)p;
    if (value != 0x00B851AC)
    {
        *(void **)((char *)&p) = (void *)value;
        target(p);
    }
}
