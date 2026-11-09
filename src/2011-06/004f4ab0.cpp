// from server: 85% by atomic.potato
extern "C" void* allocate(unsigned int);

struct S
{
    void* f();
    unsigned int x;
    unsigned int y;
};

void* S::f()
{
    void* p = allocate(12);
    if (p)
    {
        ((unsigned int*)p)[0] = 0x00a7b2d4;
        ((unsigned int*)p)[1] = x;
        ((unsigned int*)p)[2] = y;
    }
    return p;
}
