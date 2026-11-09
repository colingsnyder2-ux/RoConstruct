// from server: 66% by atomic.potato
struct S
{
    S(void *);
};

S::S(void *arg)
{
    typedef void (__thiscall *Fn)(S *, void *);
    ((Fn)0x411c20)(this, arg);
    *(int *)((char *)this + 0x3c) = 0xa00920;
    *(int *)this = 0xa02d88;
    *(int *)((char *)this + 0x28) = 0xa02d80;
    *(int *)((char *)this + 0x3c) = 0xa02d70;
}
