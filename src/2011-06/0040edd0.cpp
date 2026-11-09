// from server: 100% by atomic.potato
struct VClassFactoryProduct
{
    void set();
};

extern "C" void __cdecl sub_5980D0();

void VClassFactoryProduct::set()
{
    *(int*)((char*)this + 0) = 0xA5C644;
    *(int*)((char*)this + 4) = 0xA5C638;
    *(int*)((char*)this + 0x18) = 0xA5C62C;
    *(int*)((char*)this + 0x1C) = 0xA5C620;
    sub_5980D0();
}
