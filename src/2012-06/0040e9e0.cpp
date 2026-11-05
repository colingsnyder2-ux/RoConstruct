// from server: 100% by atomic.potato
struct S
{
    int *clone(int *);
};

int *S::clone(int *p)
{
    clone(p);
    *(volatile int *)((char *)this + 0x3c) = 0xb43c34;
    *(int *)this = 0xb442b4;
    *(int *)((char *)this + 0x28) = 0xb442ac;
    *(int *)((char *)this + 0x3c) = 0xb4429c;
    return (int *)this;
}
