// from server: 100% by king_originala
struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual int get(void* object);
};

struct EnumDescriptor {
    void convert(void* output, const int* value);
};

extern "C" void __cdecl initialize(void (__cdecl* callback)(), void* storage);
extern "C" void __cdecl callback();
extern "C" EnumDescriptor* __cdecl descriptor();
extern unsigned char storage;

struct Property {
    unsigned char padding[28];
    Accessor* accessor;

    void* get(void* output, int object);
};

void* Property::get(void* output, int object)
{
    volatile int initial = 0;
    object = accessor->get(reinterpret_cast<void*>(object));
    initialize(callback, &storage);
    EnumDescriptor* desc = descriptor();
    desc->convert(output, &object);
    return output;
}
