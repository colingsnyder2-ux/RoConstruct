// from server: 70% by atomic.potato
extern "C" void __stdcall RaiseException(unsigned long, unsigned long, unsigned long, const unsigned long*);

struct CXTIconHandle
{
    void* data;
    int count;
    void* f(int);
};

void* CXTIconHandle::f(int index)
{
    if (index >= 0 && index < count)
        return static_cast<void**>(data) + index;

    RaiseException(0xc000008cUL, 1, 0, 0);
    return 0;
}
