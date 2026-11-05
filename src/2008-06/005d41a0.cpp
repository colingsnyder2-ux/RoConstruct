// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

extern char instance_type_descriptor;
extern char decal_type_descriptor;

struct Entry {
    void* object;
    void* reference;
};

struct Container;

struct Proxy {
    Container* owner;
};

struct Container {
    Proxy* proxy;
    unsigned long reserved[2];
    Entry* first;
    Entry* last;
};

struct S {
    char reserved[0x108];
    Container* children;

    void* findDecal();
};

void* S::findDecal() {
    Container* container = children;
    if (container) {
        Entry* finish = container->last;
        void (__cdecl *error)() = invalid_parameter_noinfo;
        if (container->first > finish)
            error();
        Proxy* finishProxy = container->proxy;

        container = children;
        Entry* current = container->first;
        if (current > container->last)
            error();
        Proxy* currentProxy = container->proxy;

        for (;;) {
            if (!currentProxy || currentProxy != finishProxy)
                error();
            if (current == finish)
                break;

            if (!currentProxy)
                error();
            Container* owner = currentProxy ? currentProxy->owner : 0;
            if (current >= owner->last)
                error();

            void* result = __RTDynamicCast(
                current->object, 0, &instance_type_descriptor,
                &decal_type_descriptor, 0);
            if (result)
                return result;

            if (!currentProxy)
                error();
            owner = currentProxy ? currentProxy->owner : 0;
            if (current >= owner->last)
                error();
            ++current;
        }
    }
    return 0;
}
