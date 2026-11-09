// from server: 69% by atomic.potato
extern "C" void sub_006d3aa0(void *, void *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    sub_006d3aa0(this, arg);
    *(void **)((char *)this + 0x28) = (void *)0x00b43c34;
    *(void **)this = (void *)0x00b9902c;
    *(void **)((char *)this + 0x14) = (void *)0x00b99024;
    *(void **)((char *)this + 0x28) = (void *)0x00b99014;
    return 0;
}
