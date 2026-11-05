// from server: 100% by atomic.potato
struct S
{
    int *f(unsigned char);
};

extern "C" void __cdecl fn91f320();
extern "C" void __cdecl fn982114(S *);

int *S::f(unsigned char flags)
{
    *(int *)this = 0xbc6064;
    *(int *)((char *)this + 0x1c) = 0xbc6044;
    fn91f320();
    if (flags & 1)
        fn982114(this);
    return (int *)this;
}
