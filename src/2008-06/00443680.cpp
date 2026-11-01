// from server: 100% by king_originala
struct Holder;
typedef void (__thiscall *DestroyHolder)(Holder *, unsigned int);

struct Holder {
    DestroyHolder *vtable;
    int value;
};

extern DestroyHolder holder_vtable[];
extern void * __cdecl get_type();
extern void * __cdecl allocate(unsigned int);

struct Accessor {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual int get(Holder *) = 0;
};

struct Result {
    void *type;
    Holder *holder;
};

struct Descriptor {
    unsigned char padding[24];
    Accessor *accessor;
    void get(Holder *argument, Result *result);
};

void Descriptor::get(Holder *argument, Result *result)
{
    int value = accessor->get(argument);
    result->type = get_type();
    Holder **destination = &result->holder;

    argument = (Holder *)allocate(8);
    if (argument) {
        argument->vtable = holder_vtable;
        argument->value = value;
    } else {
        argument = 0;
    }

    Holder *previous = argument;
    if (&argument != destination) {
        previous = *destination;
        *destination = argument;
    }

    if (previous)
        previous->vtable[0](previous, 1);
}
