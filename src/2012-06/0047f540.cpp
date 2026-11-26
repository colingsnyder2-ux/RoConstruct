// from server: 100% by Xemicl
// copied from an identical function in another client (function ?create@@YA?AUResult@@XZ)

// from server: 94% by EspClaude

// from server: 100% by tester

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Product {
    unsigned char storage[0xc4];
    Product();
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

Result __cdecl create()
{
    Deleter deleter = { 0 };
    *(volatile unsigned char*)&deleter.unused = 0;
    return Result(new Product, deleter);
}
