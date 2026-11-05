// from server: 76% by atomic.potato
extern "C" void __stdcall sub_40d250(void *, void *);

struct S
{
    int *clone(void *);
};

int *S::clone(void *arg)
{
    sub_40d250(this, arg);
    *(int *)((char *)this + 0x3c) = 0x00b43c34;
    *(int *)this = 0x00b442fc;
    *(int *)((char *)this + 0x28) = 0x00b442f4;
    *(int *)((char *)this + 0x3c) = 0x00b442e4;
    return (int *)this;
}
