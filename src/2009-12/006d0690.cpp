// from server: 72% by atomic.potato
struct S
{
    int f(unsigned char value);
};

extern "C" void call_6eceb0(void *, unsigned char);
extern "C" void call_40c080(void *, const void *);

int S::f(unsigned char value)
{
    unsigned char *p = *(unsigned char **)((char *)this + 0x168);
    if (value != p[0x101])
    {
        call_6eceb0(p, value);
        call_40c080(this, (const void *)0x00b92808);
    }
    return 0;
}
