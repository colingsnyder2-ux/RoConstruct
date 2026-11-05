// from server: 100% by atomic.potato
extern "C" void __cdecl EmptyBoostFunction(void *);

struct S
{
    void *unused[8];
    void *member20;
    int f(unsigned char flags);
};

int S::f(unsigned char flags)
{
    EmptyBoostFunction(member20);
    *(void **)this = (void *)0x0099fd70;
    if (flags & 1)
        EmptyBoostFunction(this);
    return (int)this;
}
