// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern "C" void* __cdecl _RTDynamicCast(void*, long, void*, void*, int);
extern "C" char model_modifier_type;
extern "C" char skin_type;

struct Container {
    unsigned char padding[16];
    void** end;
};

struct Proxy {
    Container* container;
};

struct Iterator {
    Proxy* proxy;
    void** position;
};

struct S {
    unsigned char padding[0x1ec];
    Proxy* proxy;
    unsigned char gap[8];
    void** begin;
    void** end;
    void* f();
};

void* S::f()
{
    void (__cdecl *invalid)() = invalid_parameter_noinfo;

    Iterator last;
    last.position = end;
    if (begin > last.position)
        invalid();
    last.proxy = proxy;

    Iterator current;
    current.position = begin;
    if (current.position > end)
        invalid();
    current.proxy = proxy;

    for (;;) {
        if (!current.proxy || current.proxy != last.proxy)
            invalid();

        if (current.position == last.position)
            return 0;

        if (!current.proxy)
            invalid();
        Container* container =
            current.proxy ? current.proxy->container : 0;

        if (current.position >= container->end)
            invalid();

        void* result = _RTDynamicCast(
            *current.position, 0,
            &model_modifier_type, &skin_type, 0);
        if (result)
            return result;

        if (!current.proxy)
            invalid();
        container = current.proxy ? current.proxy->container : 0;

        if (current.position >= container->end)
            invalid();

        ++current.position;
    }
}
