// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);

struct Base
{
    char data;
};

struct Source
{
    char padding[0x1f0];
    Base base;
};

struct Object
{
    char storage[0x45c];

    Object(Base*, bool);
    static void* operator new(unsigned int size);
    static void operator delete(void*);
};

inline void* Object::operator new(unsigned int size)
{
    return malloc(size);
}

struct Tag
{
    int value;
    Tag();
};

inline Tag::Tag() : value(0)
{
    *reinterpret_cast<volatile char*>(&value) = 0;
}

struct Result
{
    Result(Object*, Tag);
};

Result __cdecl func_00576ff0(Source* source)
{
    Tag tag;
    Object* object = new Object(source ? &source->base : 0, true);
    return Result(object, tag);
}
