// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter)();
extern "C" void* __cdecl runtime_cast(void*, long, const void*, const void*, int);

struct Container;

struct Proxy {
    Container* container;
};

struct Container {
    Proxy* proxy;
    unsigned char padding[8];
    unsigned char* first;
    unsigned char* last;
};

struct Service {
    unsigned char padding[0x108];
    Container* items;

    void* find();
};

void* Service::find()
{
    Container* c = items;
    if (c) {
        unsigned char* finish = c->last;
        void (__cdecl *report)() = invalid_parameter;

        if (c->first > finish)
            report();
        Proxy* finishOwner = c->proxy;

        c = items;
        unsigned char* current = c->first;
        if (current > c->last)
            report();
        Proxy* owner = c->proxy;

        for (;;) {
            if (!owner || owner != finishOwner)
                report();

            if (current == finish)
                break;

            if (!owner)
                report();
            Container* range = owner ? owner->container : 0;
            if (current >= range->last)
                report();

            void* result = runtime_cast(
                *reinterpret_cast<void**>(current), 0,
                reinterpret_cast<const void*>(0x92907c),
                reinterpret_cast<const void*>(0x951950), 0);
            if (result)
                return result;

            if (!owner)
                report();
            range = owner ? owner->container : 0;
            if (current >= range->last)
                report();

            current += 8;
        }
    }
    return 0;
}
