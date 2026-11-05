// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S_func_006159f0 {
    int f(int a1);
};

struct Product {
    volatile int fields[9];
    Product(int a1);
};

inline Product::Product(int a1)
{
    reinterpret_cast<S_func_006159f0*>(this)->f(a1);
    fields[0] = 0x8399ec;
    fields[1] = 0x8399d4;
    fields[7] = 0;
    fields[8] = 0;
}

struct S {
    char padding[24];
    int value;
    Product* f();
};

Product* S::f()
{
    return new Product(value);
}
