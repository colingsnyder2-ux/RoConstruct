// from server: 91% by atomic.potato
extern "C" void __stdcall Call758380(void *, float);

struct S
{
    void f(float);
};

void S::f(float value)
{
    static unsigned char flag = 0;
    if (flag)
        return;

    void *p = *(void **)((char *)this + 0x84);
    void *q = *(void **)p;
    Call758380((char *)q + (unsigned int)this + 0x84, value);
}
