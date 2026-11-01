// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);
extern "C" void __cdecl free(void*);

struct Object
{
    unsigned char storage[0x178];

    Object(int);
    static void* operator new(unsigned int) throw();
    static void operator delete(void*);
};

__forceinline void* Object::operator new(unsigned int size) throw()
{
    return malloc(size);
}

__forceinline void Object::operator delete(void* memory)
{
    free(memory);
}

struct Shared
{
    Object* object;
    void* control;

    Shared(Object*, int);
};

union Tag
{
    int value;
    unsigned char byte;
};

Shared create(int argument)
{
    volatile Tag tag;
    tag.value = 0;
    tag.byte = 0;
    return Shared(new Object(argument), tag.value);
}
