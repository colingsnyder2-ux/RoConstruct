// from server: 42% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    unsigned int* p = *(unsigned int**)this;
    return *p >= 0x3d09000 ? 0x400 : 0x200;
}
