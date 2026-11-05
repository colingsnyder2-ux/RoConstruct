// from server: 92% by atomic.potato
extern "C" void* allocate(unsigned int);

struct S
{
    int unused;
    int value4;
    int value8;
    void* f();
};

void* S::f()
{
    void* p = allocate(12);
    if (p != 0)
    {
        *(int*)p = 0xA1B068;
        *((int*)p + 1) = value4;
        *((int*)p + 2) = value8;
    }
    return p;
}
