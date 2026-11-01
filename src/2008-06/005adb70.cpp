// from server: 100% by king_originala
typedef unsigned int size_t;

extern "C" void * (__cdecl *malloc)(size_t);
extern "C" void __cdecl free(void *);

struct Empty
{
};

struct Object
{
    char storage[0x158];

    Object(void *);

    static void *operator new(size_t n)
    {
        return malloc(n);
    }

    static void operator delete(void *p)
    {
        free(p);
    }
};

struct Result
{
    void *object;
    void *control;

    Result(Object *, Empty);
    ~Result();
};

Result __cdecl f(void *arg)
{
    return Result(new Object(arg), Empty());
}
