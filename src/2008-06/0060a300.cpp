// from server: 100% by colin
struct TypeInfo {};

extern TypeInfo target_type;
extern "C" bool (__thiscall *type_equal)(
    const TypeInfo *, const TypeInfo *);

union Buffer {
    unsigned int words[4];
    const TypeInfo *type;
    const Buffer *object;
};

void __cdecl f(const Buffer *source, Buffer *destination, int operation)
{
    if (operation == 0) {
        if (destination)
            *destination = *source;
    } else if (operation != 1) {
        destination->object =
            type_equal(destination->type, &target_type) ? source : 0;
    }
}
