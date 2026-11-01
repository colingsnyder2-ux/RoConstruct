// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete(void*, void*);

__forceinline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

struct Payload {
    char data[56];
    Payload(const Payload&);
};

struct Input {
    unsigned long value;
    Payload payload;
};

struct Product {
    unsigned long first;
    unsigned long second;
    unsigned long third;
    unsigned long value;
    Payload payload;
    unsigned char flag;
    unsigned char reserved;

    Product(unsigned long, unsigned long, unsigned long,
            const Input&, unsigned char);
};

__forceinline Product::Product(unsigned long a, unsigned long b,
                               unsigned long c, const Input& input,
                               unsigned char enabled)
    : first(a), second(b), third(c), value(input.value),
      payload(input.payload), flag(enabled), reserved(0)
{
}

Product* __stdcall createProduct(unsigned long a, unsigned long b,
                                 unsigned long c, const Input& input,
                                 unsigned char enabled)
{
    void* storage = operator new(sizeof(Product));
    try {
        new (storage) Product(a, b, c, input, enabled);
    }
    catch (...) {
        operator delete(storage);
        throw;
    }
    return static_cast<Product*>(storage);
}
