// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);

struct Product {
    unsigned char storage[0x154];

    Product(void* argument);

    static void* operator new(unsigned int size) {
        return malloc(size);
    }

    static void operator delete(void* memory);
};

struct Result {
    Result(Product* product, unsigned int tag);
};

Result __cdecl create(void* argument)
{
    volatile unsigned int tag = 0;
    *reinterpret_cast<volatile unsigned char*>(&tag) = 0;
    Product* product = new Product(argument);
    return Result(product, tag);
}
