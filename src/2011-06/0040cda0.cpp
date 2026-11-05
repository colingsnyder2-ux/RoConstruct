// from server: 70% by atomic.potato
struct S {
    int f(void *);
    int *v0;
    int v1[9];
};

extern "C" void __cdecl sub_40c0d0(void *);

int S::f(void *arg)
{
    sub_40c0d0(arg);
    *(int *)((char *)this + 0x3c) = 0x00a5bee8;
    v0 = (int *)0x00a5c2b8;
    *(int *)((char *)this + 0x28) = 0x00a5c2b0;
    *(int *)((char *)this + 0x3c) = 0x00a5c2a0;
    return (int)this;
}
