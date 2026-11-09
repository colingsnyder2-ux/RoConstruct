// from server: 100% by tajop
struct HVCXTPPropertyGridItemEnum_XItem
{
    void method_0069e0d0();
    HVCXTPPropertyGridItemEnum_XItem* func_0043f260(unsigned int flags);
};

extern "C" void __cdecl func_0062fc62(void* p);

HVCXTPPropertyGridItemEnum_XItem* HVCXTPPropertyGridItemEnum_XItem::func_0043f260(unsigned int flags)
{
    char* esi;
    if (this != 0)
        esi = (char*)this + 0x108;
    else
        esi = 0;

    void* p = *(void**)(esi + 8);
    if (p != 0)
    {
        func_0062fc62(p);
    }

    *(int*)(esi + 8) = 0;
    *(int*)(esi + 0xc) = 0;
    *(int*)(esi + 0x10) = 0;

    this->method_0069e0d0();

    if (flags & 1)
    {
        func_0062fc62(this);
    }

    return this;
}
