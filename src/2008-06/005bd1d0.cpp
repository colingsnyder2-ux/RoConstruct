// from server: 100% by king_originala
typedef unsigned int size_t;

extern "C" void* (__cdecl *malloc)(size_t);
extern "C" void __cdecl free(void*);

inline void* __cdecl operator new(size_t size)
{
    return malloc(size);
}

inline void __cdecl operator delete(void* memory)
{
    free(memory);
}

struct Object {
    char storage[0x170];
    Object(const char*);
};

struct Deleter {
};

struct Result {
    void* object;
    void* control;

    Result(Object*, Deleter);
    ~Result();
};

Result __cdecl create(const char* text)
{
    return Result(new Object(text), Deleter());
}
