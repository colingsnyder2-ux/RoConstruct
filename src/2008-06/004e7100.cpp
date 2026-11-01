// from server: 100% by king_originala
struct TypeInfo {
    void *vtable;
};

extern const TypeInfo target_type;
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo *);

struct Buffer {
    const void *first;
    const void *second;
};

void __cdecl manage(const Buffer &source, Buffer &destination, int operation)
{
    if (operation != 3) {
        if (operation == 0) {
            if (&destination)
                destination = source;
        } else if (operation != 1) {
            destination.first =
                type_equal(static_cast<const TypeInfo *>(destination.first),
                           &target_type)
                ? &source : 0;
        }
    } else {
        destination.first = &target_type;
    }
}
