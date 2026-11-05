// from server: 100% by colin
extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern "C" void* __cdecl runtime_cast(void*, int, const void*, const void*, int);
extern char instance_type;
extern char backpack_type;

struct Container;

struct Proxy {
    Container* owner;
};

struct Entry {
    void* object;
    void* reference;
};

struct Container {
    Proxy* proxy;
    unsigned char padding[8];
    Entry* first;
    Entry* last;
};

struct S {
    unsigned char padding[0x108];
    Container* container;
    void* findBackpack();
};

void* S::findBackpack()
{
    Container* c = container;
    if (c) {
        Entry* end = c->last;
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        if (c->first > end)
            invalid();

        Proxy* endProxy = c->proxy;
        c = container;
        Entry* current = c->first;
        if (current > c->last)
            invalid();

        Proxy* proxy = c->proxy;
        for (;;) {
            if (!proxy || proxy != endProxy)
                invalid();

            if (current == end)
                break;

            if (!proxy)
                invalid();
            Container* owner = proxy ? proxy->owner : 0;
            if (current >= owner->last)
                invalid();

            void* result = runtime_cast(current->object, 0,
                                        &instance_type, &backpack_type, 0);
            if (result)
                return result;

            if (!proxy)
                invalid();
            owner = proxy ? proxy->owner : 0;
            if (current >= owner->last)
                invalid();
            ++current;
        }
    }
    return 0;
}
