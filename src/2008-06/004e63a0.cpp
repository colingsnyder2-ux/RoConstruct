// from server: 100% by king_originala
struct TypeInfo {};

extern TypeInfo targetType;
extern bool (__thiscall *typeEquals)(const TypeInfo*, const TypeInfo&);

struct Block {
    unsigned long a, b, c, d;
};

void __cdecl manage(const Block* source, void* destination, int operation)
{
    if (operation == 0) {
        if (destination)
            *static_cast<Block*>(destination) = *source;
    } else if (operation != 1) {
        const TypeInfo* type = *static_cast<const TypeInfo**>(destination);
        *static_cast<const Block**>(destination) =
            typeEquals(type, targetType) ? source : 0;
    }
}
