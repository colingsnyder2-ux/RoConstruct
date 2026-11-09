// from server: 100% by king_originala
typedef unsigned int size_t;

extern "C" void *(__cdecl *malloc)(size_t);
extern "C" void __cdecl free(void *);

struct Product {
    char storage[0x154];

    Product(const char *);
    static void *operator new(size_t) throw();
    static void operator delete(void *);
};

__forceinline void *Product::operator new(size_t size) throw()
{
    return malloc(size);
}

__forceinline void Product::operator delete(void *p)
{
    free(p);
}

struct Tag {
    union {
        int value;
        char flag;
    };

    Tag();
};

__forceinline Tag::Tag()
{
    value = 0;
    flag = 0;
}

struct Result {
    void *object;
    void *control;

    Result(Product *, Tag);
};

Result __cdecl create(const char *text)
{
    Tag tag;
    return Result(new Product(text), tag);
}
