// from server: 100% by king_originala
struct TypeInfo;

typedef bool (__thiscall *TypeCompare)(const TypeInfo*, const TypeInfo*);
extern TypeCompare compare_type;
extern const TypeInfo target_type;

union Buffer {
    const TypeInfo* type;
    const void* object;
    unsigned int words[3];
};

void __cdecl manage(const Buffer* source, Buffer* destination, int operation)
{
    if (operation == 0) {
        if (destination)
            *destination = *source;
    } else if (operation != 1) {
        destination->object =
            compare_type(destination->type, &target_type) ? source : 0;
    }
}
