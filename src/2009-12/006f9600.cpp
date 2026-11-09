// from server: 100% by atomic.potato
extern "C" void __stdcall SetGlobal(void *);

struct S
{
    void f(int);
};

void S::f(int value)
{
    if (*(int *)((char *)this + 0x150) != value)
    {
        if (*(unsigned char *)((char *)this + 0x95) == 0)
        {
            *(int *)((char *)this + 0x150) = value;
            return;
        }

        *(int *)((char *)this + 0x150) = value;
        SetGlobal((void *)0xb94b78);
    }
}
