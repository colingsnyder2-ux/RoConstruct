// from server: 100% by king_originala
struct Instance;

struct Entry {
    Instance* object;
    void* control;
};

struct Children {
    char padding[12];
    Entry* first;
    Entry* last;
};

struct Instance {
    char padding[0x108];
    Children* children;
    unsigned int childCount();
};

struct Part {
    char padding[0x1f0];
    bool value;
};

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

bool __cdecl check(Instance* object)
{
    Part* part = static_cast<Part*>(
        __RTDynamicCast(object, 0,
                       reinterpret_cast<void*>(0x92907c),
                       reinterpret_cast<void*>(0x92dd50), 0));
    if (part)
        return part->value;

    unsigned int i = 0;
    if (object->childCount() > 0) {
        void (__cdecl* invalid)() = _invalid_parameter_noinfo;
        do {
            Children* children = object->children;
            if (i >= static_cast<unsigned int>(children->last - children->first))
                invalid();

            Instance* child = children->first[i].object;
            if (check(child))
                return true;
            ++i;
        } while (i < object->childCount());
    }
    return false;
}
