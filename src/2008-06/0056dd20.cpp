// from server: 100% by colin
namespace std {
    struct type_info;
}

extern bool (__thiscall *typeEqual)(
    const std::type_info*, const std::type_info&);

extern const std::type_info emptyType;
extern const std::type_info colorType;
extern const std::type_info stringType;

struct String {
    unsigned int proxy;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    ~String();
};

struct TypeName {
    unsigned int reserved;
    String text;
};

struct Descriptor {
    unsigned int reserved[2];
    const std::type_info* type;
    TypeName* name;
};

struct Placeholder {
    virtual ~Placeholder();
    virtual const std::type_info& type() const;
};

struct Any {
    Placeholder* content;
    void assign(const int&);
};

struct RuntimeError {
    virtual ~RuntimeError();
    char* message;
    bool owns;
    String text;

    RuntimeError(const String&);
    RuntimeError(const RuntimeError&);
};

extern int* __cdecl extractString(Any*);
extern bool __cdecl parseColor(const int*, int*);
extern Descriptor* __cdecl colorDescriptor();
extern void __cdecl finalizeColor(Any*);
extern String __cdecl format(const char*, ...);

struct Value {
    Descriptor* descriptor;
    Any value;

    void convert();
};

void Value::convert()
{
    bool (__thiscall *equal)(
        const std::type_info*, const std::type_info&) = typeEqual;

    Any* object = &value;
    if (object) {
        const std::type_info& source =
            object->content ? object->content->type() : emptyType;
        if (equal(&source, colorType)) {
            int* color = reinterpret_cast<int*>(
                reinterpret_cast<char*>(object->content) + 4);
            if (color)
                return;
        }
    }

    Descriptor* d = descriptor;
    const std::type_info* destType = d->type;
    if (equal(&stringType, *destType)) {
        int color = 194;
        int* colorPtr = &color;
        if (parseColor(extractString(object), colorPtr)) {
            object->assign(color);
            descriptor = colorDescriptor();
            finalizeColor(object);
            return;
        }
    }

    const TypeName* target = colorDescriptor()->name;
    const char* targetName =
        target->text.capacity >= 16
            ? target->text.storage.pointer
            : target->text.storage.buffer;

    const String* source = &descriptor->name->text;
    const char* sourceName =
        source->capacity >= 16
            ? source->storage.pointer
            : source->storage.buffer;

    throw RuntimeError(format("Unable to cast %s to %s",
                              sourceName, targetName));
}
