// from server: 100% by king_originala
extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct Container {
    unsigned char padding[16];
    void** finish;
};

struct Proxy {
    Container* container;
};

struct Iterator {
    Proxy* proxy;
    void** position;
};

struct S {
    unsigned char padding0[0x1ec];
    Proxy* proxy;
    unsigned char padding1[8];
    void** first;
    void** last;

    void* f();
};

void* S::f()
{
    void (__cdecl *invalid)() =
        *reinterpret_cast<void (__cdecl **)()>(0x802890);

    Iterator finish;
    finish.position = last;
    if (first > finish.position)
        invalid();

    void** current = first;
    finish.proxy = proxy;
    if (current > last)
        invalid();

    Proxy* currentProxy = proxy;
    for (;;) {
        if (!currentProxy || currentProxy != finish.proxy)
            invalid();

        if (current == finish.position)
            return 0;

        if (!currentProxy)
            invalid();

        Container* container =
            currentProxy ? currentProxy->container : 0;
        if (current >= container->finish)
            invalid();

        void* result = __RTDynamicCast(
            *current, 0,
            reinterpret_cast<void*>(0x936908),
            reinterpret_cast<void*>(0x9534e0), 0);

        if (result)
            return result;

        if (!currentProxy)
            invalid();

        container = currentProxy ? currentProxy->container : 0;
        if (current >= container->finish)
            invalid();

        ++current;
    }
}
