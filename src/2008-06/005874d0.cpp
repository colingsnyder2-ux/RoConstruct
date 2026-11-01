// from server: 100% by king_originala
struct Value {
    unsigned int words[4];
};

struct TypeInfo;
extern TypeInfo targetType;
extern bool (__thiscall *typeInfoEqual)(const TypeInfo *, const TypeInfo *);

void __cdecl manage(const Value *source, Value *destination, int operation)
{
    if (operation == 0) {
        if (destination)
            *destination = *source;
    } else if (operation != 1) {
        destination->words[0] =
            typeInfoEqual(
                reinterpret_cast<const TypeInfo *>(destination->words[0]),
                &targetType)
            ? reinterpret_cast<unsigned int>(source)
            : 0;
    }
}
