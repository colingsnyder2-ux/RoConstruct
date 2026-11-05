// from server: 86% by atomic.potato
extern "C" void __stdcall sub_006ece90(unsigned char);
extern "C" void __cdecl sub_0040c080(void *, const void *);

struct S
{
    int f(unsigned char);
};

int S::f(unsigned char value)
{
    unsigned char *p = *(unsigned char **)((char *)this + 0x168);
    if (value != p[0x100])
    {
        sub_006ece90(value);
        sub_0040c080(this, (const void *)0x00b926a4);
    }
    return 0;
}
