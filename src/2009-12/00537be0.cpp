// from server: 92% by atomic.potato
extern "C" void* __cdecl allocate(unsigned int);

struct S
{
    int unused;
    int value1;
    int value2;
    void* f();
};

void* S::f()
{
    void* p = allocate(12);
    if (p != 0)
    {
        *(unsigned int*)p = 0x9bd188;
        *(unsigned int*)((char*)p + 4) = (unsigned int)value1;
        *(unsigned int*)((char*)p + 8) = (unsigned int)value2;
    }
    return p;
}
