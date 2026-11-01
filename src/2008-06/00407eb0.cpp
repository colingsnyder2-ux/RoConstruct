// from server: 100% by king_originala
struct Interface;

struct InterfaceTable {
    long (__stdcall *QueryInterface)(Interface *, const void *, void **);
    unsigned long (__stdcall *AddRef)(Interface *);
    unsigned long (__stdcall *Release)(Interface *);
};

struct Interface {
    InterfaceTable *table;
};

struct Object {
    unsigned char padding[16];
    Interface *value;
};

long __stdcall SetValue(void *part, Interface *value)
{
    Object *object = part
        ? reinterpret_cast<Object *>(static_cast<char *>(part) - 12)
        : 0;

    if (object->value != value) {
        if (value)
            value->table->AddRef(value);
        if (object->value)
            object->value->table->Release(object->value);
        object->value = value;
    }
    return 0;
}
