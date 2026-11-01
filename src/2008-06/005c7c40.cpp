// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern void* table1[];
extern void* table2[];

struct Context {
    char pad[0x204];
    void* value;
};

struct Product {
    void* vtable1;
    void* vtable2;
    char pad[0x28];
    Product(void*, int, int);
};

struct Derived : Product {
    Derived(void*);
};

inline Derived::Derived(void* value) : Product(value, 0, 90)
{
    vtable1 = table1;
    vtable2 = table2;
}

struct Tool {
    char pad[0x0c];
    Context* context;
    Product* create();
};

Product* Tool::create()
{
    return new Derived(context->value);
}
