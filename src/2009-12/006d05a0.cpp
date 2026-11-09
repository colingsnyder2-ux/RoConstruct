// from server: 79% by atomic.potato
extern "C" void __stdcall sub_006ec2d0(void *, unsigned char);
extern "C" void __stdcall sub_0040c080(void *, const void *);

struct S {
    void f(unsigned char);
};

void S::f(unsigned char value)
{
    unsigned char *p = *(unsigned char **)((char *)this + 0x168);
    if (value != p[0x80]) {
        sub_006ec2d0(p, value);
        sub_0040c080(this, (const void *)0x00b92a00);
    }
}
