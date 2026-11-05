// from server: 100% by king_originala
struct TypeInfo;
typedef bool (__thiscall *TypeCompare)(const TypeInfo*, const TypeInfo&);

extern TypeCompare compareTypes;
extern const TypeInfo targetType;

struct Payload {
    void destroy();
};

struct Buffer {
    void* value;
    Payload payload;
    void clone(const void* source);
};

void __cdecl manage(const void* source, Buffer* destination, int operation)
{
    if (operation == 0) {
        if (destination)
            destination->clone(source);
    } else if (operation == 1) {
        destination->payload.destroy();
    } else {
        destination->value =
            compareTypes(static_cast<const TypeInfo*>(destination->value),
                         targetType)
            ? const_cast<void*>(source) : 0;
    }
}
