// from server: 100% by king_originala
extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

extern char instance_type;
extern char part_instance_type;
extern "C" void (__cdecl * const invalid_parameter_noinfo)();

struct Instance;

struct Entry {
    Instance* object;
    void* control;
};

struct Children {
    char padding[12];
    Entry* begin;
    Entry* end;
};

struct Instance {
    char padding[264];
    Children* children;
    unsigned int count();
};

struct Output {
    void append(char* const&);
};

void __cdecl collect(Instance* object, Output* output)
{
    char* part = static_cast<char*>(__RTDynamicCast(
        object, 0, &instance_type, &part_instance_type, 0));

    if (part) {
        char* value = part + 552;
        output->append(value);
    }

    for (unsigned int i = 0; i < object->count(); ++i) {
        Children* children = object->children;
        if (i >= static_cast<unsigned int>(children->end - children->begin))
            invalid_parameter_noinfo();
        collect(children->begin[i].object, output);
    }
}
