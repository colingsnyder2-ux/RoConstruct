// from server: 43% by atomic.potato
extern "C" void* __stdcall sub_40A350();

struct VClientFactoryProduct {
    void* vtable;
    void* field4;
    VClientFactoryProduct();
};

VClientFactoryProduct::VClientFactoryProduct()
{
    vtable = (void*)0x9be8dc;
    field4 = 0;
    *(volatile char*)0xb901e4 = 1;
    field4 = sub_40A350();
    vtable = (void*)0x9be8e4;
}
