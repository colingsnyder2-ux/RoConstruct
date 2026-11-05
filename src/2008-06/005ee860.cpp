// from server: 100% by king_originala
extern void __cdecl registerInitializer(void (__cdecl*)(), void*);

struct EnumTable {
    bool lookup(const void*, int*);
};

extern EnumTable* __cdecl getEnumTable();

struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const int*);
};

struct Descriptor {
    unsigned char storage[28];
    Accessor* access;

    bool setValue(void*, const void*);
};

bool Descriptor::setValue(void* object, const void* value)
{
    int result;
    registerInitializer(
        reinterpret_cast<void (__cdecl*)()>(0x005ed620),
        reinterpret_cast<void*>(0x0097b11c));
    EnumTable* table = getEnumTable();
    if (table->lookup(value, &result)) {
        access->set(object, &result);
        return true;
    }
    return false;
}
