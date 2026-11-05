// from server: 100% by atomic.potato
extern "C" void __cdecl sub_413D60();

struct FactoryProduct
{
    void f();
};

void FactoryProduct::f()
{
    *(int*)((char*)this + 0) = 0xA727BC;
    *(int*)((char*)this + 4) = 0xA727B4;
    *(int*)((char*)this + 0x18) = 0xA727A8;
    *(int*)((char*)this + 0x1C) = 0xA7279C;
    *(int*)((char*)this + 0x90) = 0xA72794;
    sub_413D60();
}
