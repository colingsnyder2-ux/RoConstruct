// from server: 100% by king_originala
struct Buffer {
    unsigned int words[6];
};

struct TypeInfo;
extern const TypeInfo target_type;
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo *);

void __cdecl manage(const Buffer *source, Buffer *destination, int operation)
{
    if (operation == 0) {
        if (destination)
            *destination = *source;
    } else if (operation != 1) {
        const TypeInfo *requested =
            reinterpret_cast<const TypeInfo *>(destination->words[0]);
        destination->words[0] = type_equal(requested, &target_type)
            ? reinterpret_cast<unsigned int>(source) : 0;
    }
}
