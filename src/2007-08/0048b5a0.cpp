// from server: 27% by colin
extern "C" void* __cdecl malloc(unsigned int size);

struct ICreator {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
};

struct Creator : ICreator {
    void construct(void* p);
};

struct FactoryProduct {
    void* field0;
    void* field4;
    void init(void* a, void* b);
};

void __fastcall Creator_construct(Creator* self, void* unused, void* p);

void __fastcall FactoryProduct_init(FactoryProduct* self, void* unused, void* a, void* b);

void __fastcall Creator_construct(Creator* self, void* unused, void* p)
{
    if (p) {
        ((void (__thiscall*)(void*, int))0x5a1150)(p, 1);
    }
}

void __fastcall FactoryProduct_init(FactoryProduct* self, void* unused, void* a, void* b)
{
    ((void (__thiscall*)(FactoryProduct*, void*, void*))0x48b4f0)(self, a, b);
}

void* __fastcall FactoryProduct_creator(FactoryProduct* self, void* unused)
{
    void* mem = malloc(0x2bc);
    void* obj = 0;
    if (mem) {
        obj = mem;
        ((void (__thiscall*)(void*, int))0x5a1150)(obj, 1);
    }
    ((void (__thiscall*)(FactoryProduct*, void*, void*))0x48b4f0)(self, obj, 0);
    return self;
}
