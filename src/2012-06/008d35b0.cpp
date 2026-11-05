// from server: 100% by atomic.potato
extern "C" void __cdecl sub_8d3420();

struct FactoryProduct
{
    void constructor();
};

void FactoryProduct::constructor()
{
    *(void**)this = (void*)0xbe9bac;
    *(void**)((char*)this + 4) = (void*)0xbe9ba0;
    *(void**)((char*)this + 0x18) = (void*)0xbe9b94;
    *(void**)((char*)this + 0x1c) = (void*)0xbe9b88;
    *(void**)((char*)this + 0x80) = (void*)0xbe9b78;
    *(void**)((char*)this + 0x84) = (void*)0xbe9b4c;
    sub_8d3420();
}
