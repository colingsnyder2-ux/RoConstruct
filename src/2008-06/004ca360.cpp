// from server: 100% by king_originala
struct TypeInfo;
extern const TypeInfo targetType;
extern bool (__thiscall *equalType)(const TypeInfo*, const TypeInfo&);

struct Data {
    void* first;
    unsigned int second;
    unsigned int third;
    unsigned int fourth;
};

void __cdecl manage(Data* source, Data* destination, int operation)
{
    if (operation == 0) {
        if (destination)
            *destination = *source;
    } else if (operation != 1) {
        destination->first =
            equalType(static_cast<const TypeInfo*>(destination->first), targetType)
            ? source : 0;
    }
}
