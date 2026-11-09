// from server: 64% by atomic.potato
extern "C" void* __cdecl Allocate(unsigned int);
struct Object
{
    void Initialize(void*, void*);
};

void* Function(void* a, void* b)
{
    void* p = Allocate(32);
    if (p != 0)
        ((Object*)p)->Initialize(a, b);
    return p;
}
