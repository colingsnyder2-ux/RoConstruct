// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);

inline void* __cdecl operator new(unsigned int size)
{
    return malloc(size);
}

void __cdecl operator delete(void*);

struct Object
{
    char storage[0x1a8];
    Object();
};

struct Result
{
    void* object;
    void* control;
    Result(Object*, int);
};

Result __cdecl makeResult()
{
    union
    {
        volatile int value;
        volatile unsigned char byte;
    } tag;

    tag.value = 0;
    tag.byte = 0;
    return Result(new Object, tag.value);
}
