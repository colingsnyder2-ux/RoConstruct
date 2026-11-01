// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Header
{
    int* count;
    Control* control;
    unsigned int unused;
};

struct Object
{
    unsigned char padding[32];
    void* first;
    unsigned int unused;
    void* second;
    unsigned int firstCount;
    unsigned int secondCount;
};

extern void __cdecl cleanup(Object*, void*);
extern void __cdecl resizeBlock(void*, void*, unsigned int, unsigned int);

void __cdecl releaseObject(void* state, Object* object)
{
    cleanup(object, object->first);

    Header* header = reinterpret_cast<Header*>(object) - 1;
    --*header->count;

    Control* control = header->control;
    if (control)
    {
        if (_InterlockedDecrement(&control->strong) == 0)
        {
            control->dispose();
            if (_InterlockedDecrement(&control->weak) == 0)
                control->destroy();
        }
    }

    resizeBlock(state, object->second, object->secondCount * 24, 0);
    resizeBlock(state, object->first, object->firstCount * 16, 0);
    resizeBlock(state, header, 0x84, 0);
}
