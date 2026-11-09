// from server: 54% by colin
struct RBXName;
struct Variant;

struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct EnumDescriptor;

struct Item : Descriptor {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
    Item(const char* name, unsigned int attributes, int value, unsigned int index, const EnumDescriptor& owner);
};

struct EnumDescriptor {
    char pad[0x114];
    void* field114;
    void* field118;
    bool convertToValue(unsigned int index, Variant& value) const;
};

struct Variant {
    void* storage;
    Variant();
    ~Variant();
};

extern "C" void __cdecl sub_439850(Variant*, const void*);
extern "C" void __cdecl sub_5595A0(Variant*);

Item::Item(const char* name, unsigned int attributes, int value, unsigned int index, const EnumDescriptor& owner)
    : Descriptor(name, attributes)
    , owner(owner)
    , value(value)
    , index(index)
{
    void* p = *(void**)((char*)this->owner.field114 + 0x188);
    Variant v;
    sub_439850(&v, p);
    const void* arg = 0;
    if (name) {
        arg = (const char*)name + 4;
    }
    void** vtbl = *(void***)this->owner.field118;
    typedef void (__thiscall *Fn)(void*, const void*, const void*);
    Fn fn = (Fn)vtbl[5];
    fn(this->owner.field118, arg, (const void*)index);
    sub_5595A0(&v);
}
