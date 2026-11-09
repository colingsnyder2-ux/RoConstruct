// from server: 69% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" void sub_4114a0(S *, void *);

int S::f(void *arg)
{
    sub_4114a0(this, arg);
    *(int *)((char *)this + 0x3c) = 0x99fd90;
    *(int *)this = 0x9a20dc;
    *(int *)((char *)this + 0x28) = 0x9a20d4;
    *(int *)((char *)this + 0x3c) = 0x9a20c4;
    return (int)this;
}
