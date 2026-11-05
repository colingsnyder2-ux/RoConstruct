// from server: 70% by atomic.potato
struct S
{
    int *f(int *);
};

extern "C" void sub_40c160(int *);

int *S::f(int *p)
{
    sub_40c160(p);
    *(int *)((char *)this + 0x3c) = 0xA5BEE8;
    *(int *)this = 0xA5C2DC;
    *(int *)((char *)this + 0x28) = 0xA5C2D4;
    *(int *)((char *)this + 0x3c) = 0xA5C2C4;
    return (int *)this;
}
