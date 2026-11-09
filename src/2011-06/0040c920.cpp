// from server: 69% by atomic.potato
struct S
{
    int *f(void *);
};

extern "C" void sub_40b3c0(void *, void *);

int *S::f(void *p)
{
    sub_40b3c0(this, p);
    *(int *)((char *)this + 0x3c) = 0xA5BEE8;
    *(int *)this = 0xA5C270;
    *(int *)((char *)this + 0x28) = 0xA5C268;
    *(int *)((char *)this + 0x3c) = 0xA5C258;
    return (int *)this;
}
