// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);

struct Object {
    char storage[0x2d8];

    Object();
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
};

__forceinline void* Object::operator new(unsigned int size)
{
    return malloc(size);
}

struct Deleter {
    int value;
};

struct Result {
    Object* pointer;
    void* control;

    Result(Object* p, Deleter d);
};

Result makeObject()
{
    Deleter d = { 0 };
    *reinterpret_cast<volatile char*>(&d) = 0;
    return Result(new Object, d);
}
