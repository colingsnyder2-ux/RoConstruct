// from server: 81% by atomic.potato
extern "C" void __stdcall sub_758310(void *, float);

struct S
{
    void f(float);
};

void S::f(float value)
{
    static volatile unsigned char flag = 0;
    if (flag)
        return;

    void *p = *(void **)((char *)this + 0x84);
    void *q = *(void **)p;
    sub_758310((char *)q + (long)this + 0x84, value);
}
