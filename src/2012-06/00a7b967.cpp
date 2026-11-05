// from server: 35% by atomic.potato
extern "C" void __stdcall RaiseException(unsigned long, unsigned long, unsigned long, const unsigned long *);

struct CXTIconHandle
{
    void **data;
    int count;
    void *f(int index);
};

void *CXTIconHandle::f(int index)
{
    if (index < 0 || index >= count)
    {
        RaiseException(0xc000008cUL, 1UL, 0UL, 0);
    }
    return data[index];
}
