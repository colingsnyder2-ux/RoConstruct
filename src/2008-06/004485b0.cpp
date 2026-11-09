// from server: 100% by king_originala
struct Holder {
    void** vtable;
    int value;
};

struct Result {
    void* descriptor;
    Holder* object;
};

extern void* __cdecl getDescriptor();
extern void* __cdecl allocate(unsigned int);
extern void* holderVtable[];

struct EnumPropDescriptor {
    void** vtable;
    void convert(Holder* argument, Result* result);
};

void EnumPropDescriptor::convert(Holder* argument, Result* result)
{
    int value = reinterpret_cast<int (__thiscall*)(EnumPropDescriptor*, Holder*)>(
        vtable[14])(this, argument);

    result->descriptor = getDescriptor();

    Holder** destination = &result->object;
    Holder* object = static_cast<Holder*>(allocate(8));
    if (object) {
        object->vtable = holderVtable;
        object->value = value;
    } else {
        object = 0;
    }

    argument = object;
    if (&argument != destination) {
        Holder* previous = *destination;
        *destination = argument;
        argument = previous;
    }

    if (argument) {
        reinterpret_cast<void (__thiscall*)(Holder*, unsigned int)>(
            argument->vtable[0])(argument, 1);
    }
}
