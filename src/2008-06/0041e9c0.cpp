// from server: 100% by atomic.potato
extern "C" {
    extern void* (__cdecl *malloc)(unsigned int);
    void __cdecl free(void*);
}

inline void* __cdecl operator new(unsigned int size) throw()
{
    return malloc(size);
}

inline void __cdecl operator delete(void* p) throw()
{
    free(p);
}

struct Object {
    char storage[0x404];
    Object(int);
};

struct Result {
    Result(Object*, unsigned int);
};

Result f()
{
    volatile unsigned int deleter = 0;
    *reinterpret_cast<volatile unsigned char*>(&deleter) = 0;
    return Result(new Object(1), deleter);
}
