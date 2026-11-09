// from server: 100% by king_originala
struct TypeInfo {};
typedef bool (__thiscall *TypeEqual)(const TypeInfo *, const TypeInfo &);
extern TypeEqual typeEqual;

extern TypeInfo emptyType;
extern TypeInfo valueType;
extern TypeInfo conversionType;
extern char descriptorName[];
extern char castFormat[];

struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char *pointer;
    } data;
    unsigned int length;
    unsigned int capacity;

    ~String();
};

struct NamedString {
    unsigned int prefix;
    String value;
};

struct Exception {
    char storage[40];

    Exception(const String &);
    Exception(const Exception &);
    ~Exception();
};

struct Placeholder;
struct PlaceholderTable {
    void (__thiscall *destroy)(Placeholder *, unsigned int);
    const TypeInfo &(__thiscall *type)(const Placeholder *);
};

struct Placeholder {
    PlaceholderTable *vtable;
};

struct Descriptor {
    unsigned int fields[2];
    const TypeInfo *type;
    NamedString *name;
};

extern void __cdecl descriptorCallback();
extern void __cdecl registerDescriptor(void (__cdecl *)(), const char *);
extern Descriptor *__cdecl getDescriptor();
extern void *__cdecl convert(Placeholder **);
extern String __cdecl format(const char *, ...);

struct SurfaceDescriptor {
    Descriptor *descriptor;
    Placeholder *storage;

    int *cast();
};

int *SurfaceDescriptor::cast()
{
    TypeEqual equal = typeEqual;
    Placeholder **source = &storage;
    if (source) {
        const TypeInfo &type = *source
            ? (*source)->vtable->type(*source)
            : emptyType;
        if (equal(&type, valueType)) {
            int *result = reinterpret_cast<int *>(*source) + 1;
            if (result)
                return result;
        }
    }

    const TypeInfo *actualType = descriptor->type;
    if (equal(&conversionType, *actualType))
        convert(source);

    registerDescriptor(descriptorCallback, descriptorName);

    String *destinationName = &getDescriptor()->name->value;
    const char *destination = destinationName->capacity >= 16
        ? destinationName->data.pointer
        : destinationName->data.buffer;

    String *sourceName = &descriptor->name->value;
    const char *name = sourceName->capacity >= 16
        ? sourceName->data.pointer
        : sourceName->data.buffer;

    throw Exception(format(castFormat, name, destination));
}
