// from server: 100% by king_originala
extern "C" {
    extern void* (__cdecl *allocate)(unsigned int);
}

inline void* __cdecl operator new(unsigned int size)
{
    return allocate(size);
}

void __cdecl operator delete(void*);

struct Vector2 {
    float x;
    float y;

    Vector2(const Vector2& other) : x(other.x), y(other.y) {}
};

struct Product {
    unsigned char storage[0x16c];
    Product(void*, void*, Vector2);
};

struct Deleter {
    union {
        unsigned int value;
        unsigned char unused;
    };
};

struct Result {
    Result(Product*, Deleter);
};

Result __cdecl create(void* first, void* second, Vector2 size)
{
    Deleter deleter = { 0 };
    *(volatile unsigned char*)&deleter.unused = 0;
    return Result(new Product(first, second, size), deleter);
}
