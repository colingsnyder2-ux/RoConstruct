// from server: 100% by EspClaude
// from server: 94% by EspClaude
// roc 2009-06 00417720  unit: RBX::VHopperBin::?$FactoryProduct::Creator  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00417720
//

// from server: 100% by tester
// roc 2008-06 0048ea00  unit: RBX::VHopperBin::?$FactoryProduct::Creator  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048ea00
//

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

