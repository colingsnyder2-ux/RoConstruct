// from server: 100% by tajop
extern "C" void __cdecl func_0062fc62(void*);

struct XItem
{
    char pad0[0x114];
    void* ptr8;
    void* ptrC;
    void* ptr10;

    void method_0069dd50();
    XItem* destroy(int flags);
};

XItem* XItem::destroy(int flags)
{
    XItem* self = this;
    char* base;
    if (self != 0)
        base = (char*)self + 0x114;
    else
        base = 0;

    void* p = *(void**)(base + 8);
    if (p != 0)
    {
        func_0062fc62(p);
    }

    *(void**)(base + 8) = 0;
    *(void**)(base + 0xc) = 0;
    *(void**)(base + 0x10) = 0;

    self->method_0069dd50();

    if (flags & 1)
    {
        func_0062fc62(self);
    }

    return self;
}
