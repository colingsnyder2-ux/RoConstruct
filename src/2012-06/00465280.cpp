// from server: 47% by atomic.potato
extern "C" void* __cdecl sub_98211A(unsigned int);
extern "C" void __cdecl sub_982114(void*);

struct VCRenderSettingsItem_FactoryProduct {
    void* method(void* a, void* b, void* c);
};

void* VCRenderSettingsItem_FactoryProduct::method(void* a, void* b, void* c)
{
    void* p = sub_98211A(0x10);
    if (p != 0)
    {
        *(unsigned int*)p = 0xb57cb4;
        *(void**)((char*)p + 4) = a;
        *(void**)((char*)p + 8) = b;
        *(void**)((char*)p + 12) = c;
    }
    else
    {
        p = 0;
    }
    sub_982114(p);
    return p;
}
