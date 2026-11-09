// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern "C" void* __cdecl runtime_cast(void*, long, const void*, const void*, int);

struct Container;

struct Proxy {
    Container* owner;
};

struct Entry {
    void* object;
    void* control;
};

struct Container {
    Proxy* proxy;
    unsigned int reserved[2];
    Entry* begin;
    Entry* end;
};

struct PartTool {
    unsigned char reserved[0x108];
    Container* entries;
    void* findModel();
};

void* PartTool::findModel()
{
    if (entries) {
        Container* container = entries;
        Entry* last = container->end;
        void (__cdecl *invalid)() = invalid_parameter_noinfo;

        if (container->begin > last)
            invalid();

        Proxy* lastProxy = container->proxy;
        container = entries;
        Entry* current = container->begin;

        if (current > container->end)
            invalid();

        Proxy* proxy = container->proxy;

        for (;;) {
            if (!proxy || proxy != lastProxy)
                invalid();

            if (current == last)
                break;

            if (!proxy)
                invalid();

            Container* owner = proxy ? proxy->owner : 0;
            if (current >= owner->end)
                invalid();

            void* result = runtime_cast(
                current->object, 0,
                (const void*)0x92907c,
                (const void*)0x932a40, 0);

            if (result)
                return result;

            if (!proxy)
                invalid();

            owner = proxy ? proxy->owner : 0;
            if (current >= owner->end)
                invalid();

            ++current;
        }
    }

    return 0;
}
