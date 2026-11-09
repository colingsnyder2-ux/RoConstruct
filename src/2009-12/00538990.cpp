// from server: 92% by atomic.potato
struct S
{
    int value;
    int a;
    int b;
    void* f();
};

extern "C" void* __cdecl allocate(unsigned int);

void* S::f()
{
    void* p = allocate(12);
    if (p != 0)
    {
        *(int*)p = 0x9bd29c;
        *((int*)p + 1) = a;
        *((int*)p + 2) = b;
    }
    return p;
}
