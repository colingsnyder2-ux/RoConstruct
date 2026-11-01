// from server: 100% by colin
struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual int get(void* object);
};

struct EnumDescriptor {
    unsigned char padding[172];
    void** first;
    void** volatile last;
};

extern "C" void __cdecl initialize(void (__cdecl* callback)(), void* storage);
extern "C" void __cdecl callback();
extern "C" EnumDescriptor* __cdecl descriptor();
extern "C" void (__cdecl* _invalid_parameter_noinfo)();
extern unsigned char storage;

struct Property {
    unsigned char padding[28];
    Accessor* accessor;

    void* get(void* object);
};

void* Property::get(void* object)
{
    int value = accessor->get(object);
    initialize(callback, &storage);
    EnumDescriptor* desc = descriptor();

    if (value < 0)
        return 0;

    if (static_cast<unsigned int>(value) >=
        static_cast<unsigned int>(desc->last - desc->first))
        return 0;

    if (static_cast<unsigned int>(value) >=
        static_cast<unsigned int>(desc->last - desc->first))
        _invalid_parameter_noinfo();

    return desc->first[value];
}
