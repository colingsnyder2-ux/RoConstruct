// from server: 100% by atomic.potato
extern "C" void __stdcall SetGlobal(void *);

struct S
{
    void f(unsigned char);
};

void S::f(unsigned char value)
{
    if (*(unsigned char *)((char *)this + 0x95) != value)
    {
        *(unsigned char *)((char *)this + 0x95) = value;
        SetGlobal((void *)0xb94770);
    }
}
