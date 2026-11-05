// from server: 100% by king_originala
struct TypeInfo {
    bool operator==(const TypeInfo&) const;
};

extern TypeInfo targetType;
extern bool (__thiscall *typeInfoEqual)(const TypeInfo*, const TypeInfo&);

void manage(void* source, void** destination, int operation)
{
    if (operation != 3) {
        if (operation == 0) {
            *destination = *static_cast<void**>(source);
            return;
        }
        if (operation == 1) {
            *destination = 0;
            return;
        }
        *destination = typeInfoEqual(static_cast<TypeInfo*>(*destination), targetType)
            ? source : 0;
    } else {
        *destination = &targetType;
    }
}
