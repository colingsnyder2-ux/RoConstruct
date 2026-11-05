// from server: 100% by king_originala
extern "C" void *(__cdecl *malloc)(unsigned int);

struct Product
{
    unsigned char storage[0x154];

    Product(int);
    static void *__cdecl operator new(unsigned int size) throw();
    static void __cdecl operator delete(void *);
};

__forceinline void *__cdecl Product::operator new(unsigned int size) throw()
{
    return malloc(size);
}

struct Tag
{
};

struct Result
{
    void *object;
    void *control;

    Result(Product *, Tag);
    ~Result();
};

Result __cdecl createProduct(int argument)
{
    return Result(new Product(argument), Tag());
}
