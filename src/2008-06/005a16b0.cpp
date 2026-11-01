// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

extern char instance_type;
extern char part_instance_type;

struct Container;

struct Proxy {
    Container* container;
};

struct Entry {
    void* object;
    void* control;
};

struct Container {
    Proxy* proxy;
    unsigned reserved[2];
    Entry* begin;
    Entry* end;
};

struct PartTool {
    char reserved[0x108];
    Container* entries;
    void* findPart();
};

void* PartTool::findPart()
{
    Container* list = entries;
    if (list) {
        Entry* last = list->end;
        void (__cdecl *invalid)() = invalid_parameter_noinfo;

        if (list->begin > last)
            invalid();

        Proxy* lastOwner = list->proxy;
        list = entries;
        Entry* current = list->begin;

        if (current > list->end)
            invalid();

        Proxy* owner = list->proxy;

        for (;;) {
            if (!owner || owner != lastOwner)
                invalid();

            if (current == last)
                break;

            if (!owner)
                invalid();

            Container* container = owner ? owner->container : 0;
            if (current >= container->end)
                invalid();

            void* result = __RTDynamicCast(current->object, 0,
                                          &instance_type, &part_instance_type, 0);
            if (result)
                return result;

            if (!owner)
                invalid();

            container = owner ? owner->container : 0;
            if (current >= container->end)
                invalid();

            ++current;
        }
    }
    return 0;
}
