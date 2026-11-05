// from server: 100% by atomic.potato
extern "C" void __cdecl Finish();

struct FactoryProduct
{
    void f();
};

void FactoryProduct::f()
{
    *(int*)0xb7b61c = 0;
    *(int*)((char*)this + 0) = 0x9cafd4;
    *(int*)((char*)this + 4) = 0x9cafc8;
    *(int*)((char*)this + 0x18) = 0x9cafbc;
    *(int*)((char*)this + 0x1c) = 0x9cafb4;
    Finish();
}
