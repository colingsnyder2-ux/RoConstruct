// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);
extern "C" void __cdecl free(void*);

struct Object {
    char storage[0x178];

    Object(unsigned int);
    static void* operator new(unsigned int n) { return malloc(n); }
    static void operator delete(void* p) { free(p); }
};

struct Empty {};

struct Result {
    Object* object;
    void* control;

    Result(Object*, Empty = Empty());
    ~Result();
};

Result create(unsigned int argument)
{
    return Result(new Object(argument));
}
