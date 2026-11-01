// from server: 100% by king_originala
struct TypeInfo;

extern TypeInfo expectedType;
extern bool (__thiscall *typeEqual)(const TypeInfo *, const TypeInfo &);

union Buffer {
    unsigned int words[4];
    const TypeInfo *type;
    const Buffer *object;
};

void __cdecl manage(const Buffer *source, Buffer *destination, int operation)
{
    if (operation == 0) {
        if (destination)
            *destination = *source;
    } else if (operation != 1) {
        destination->object =
            typeEqual(destination->type, expectedType) ? source : 0;
    }
}
