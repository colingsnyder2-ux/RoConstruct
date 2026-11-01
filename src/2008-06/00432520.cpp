// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);
void __cdecl operator delete(void*);

inline void* __cdecl operator new(unsigned int size)
{
    return malloc(size);
}

struct Object {
    unsigned char storage[472];
    Object(int);
};

struct Result {
    Object* pointer;
    void* control;
    Result(Object*, int);
};

Result create()
{
    int tag = 0;
    *reinterpret_cast<volatile unsigned char*>(&tag) = 0;
    return Result(new Object(1), tag);
}
