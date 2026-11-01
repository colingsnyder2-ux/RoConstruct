// from server: 100% by king_originala
extern "C" void *(__cdecl *malloc)(unsigned int);

struct Deleter {
    char value;
    Deleter();
};

inline Deleter::Deleter() : value(0) {}

struct Object {
    char storage[0x154];

    Object(void *);
    static void *operator new(unsigned int size) throw();
    static void operator delete(void *);
};

inline void *Object::operator new(unsigned int size) throw()
{
    return malloc(size);
}

struct Result {
    void *object;
    void *control;

    Result(Object *, Deleter);
    Result(const Result &);
    ~Result();
};

Result __cdecl create(void *argument)
{
    Deleter deleter = Deleter();
    return Result(new Object(argument), deleter);
}
