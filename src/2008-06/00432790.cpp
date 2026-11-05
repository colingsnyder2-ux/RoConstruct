// from server: 100% by king_originala
extern "C" void *(__cdecl *malloc)(unsigned int);

struct Object {
    char storage[0x1d8];

    Object(int);
    static void *operator new(unsigned int size);
    static void operator delete(void *);
};

inline void *Object::operator new(unsigned int size)
{
    return malloc(size);
}

struct Result {
    void construct(Object *, int);
};

union Tag {
    int value;
    volatile unsigned char byte;
};

Result *__cdecl create(Result *result)
{
    Tag tag;
    tag.value = 0;
    tag.byte = 0;
    Object *object = new Object(1);
    result->construct(object, tag.value);
    return result;
}
