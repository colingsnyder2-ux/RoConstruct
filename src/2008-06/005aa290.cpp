// from server: 100% by king_originala
struct Buffer {
    void* data[4];
};

struct TypeInfo;
extern TypeInfo targetType;
extern bool (__thiscall *typeEqual)(const void*, const TypeInfo*);

void manage(const Buffer* source, Buffer* destination, int operation)
{
    if (operation == 0) {
        if (destination)
            *destination = *source;
    } else if (operation != 1) {
        destination->data[0] =
            typeEqual(destination->data[0], &targetType)
                ? const_cast<Buffer*>(source)
                : 0;
    }
}
