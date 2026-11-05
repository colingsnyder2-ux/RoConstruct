// from server: 100% by atomic.potato
extern "C" void __cdecl sub_40eb10();

struct FactoryProduct
{
    void f();
};

void FactoryProduct::f()
{
    *(int*)this = 0xA5C964;
    *(int*)((char*)this + 4) = 0xA5C958;
    *(int*)((char*)this + 0x18) = 0xA5C94C;
    *(int*)((char*)this + 0x1C) = 0xA5C940;
    sub_40eb10();
}
