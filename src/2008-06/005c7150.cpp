// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern const void* table1[];
extern const void* table2[];

struct Product {
    const void** first;
    const void** second;
    char pad[0x1c];
    Product(void*);
};

struct DerivedProduct : Product {
    DerivedProduct(void*);
};

struct Context {
    char pad[0x204];
    void* value;
};

struct Tool {
    char pad[0xc];
    Context* context;
    Product* f();
};

__forceinline DerivedProduct::DerivedProduct(void* value)
    : Product(value)
{
    first = table1;
    second = table2;
}

Product* Tool::f()
{
    return new DerivedProduct(context->value);
}
