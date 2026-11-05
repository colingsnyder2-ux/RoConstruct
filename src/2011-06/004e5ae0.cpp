// from server: 100% by atomic.potato
struct FactoryProduct
{
    void f();
};

extern "C" void __cdecl sub_5980d0();

void FactoryProduct::f()
{
    *(int*)((char*)this + 0) = 0xA7A5BC;
    *(int*)((char*)this + 4) = 0xA7A5B4;
    *(int*)((char*)this + 0x18) = 0xA7A5A8;
    *(int*)((char*)this + 0x1C) = 0xA7A59C;
    sub_5980d0();
}
