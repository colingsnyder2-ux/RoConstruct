// from server: 100% by colin
struct TypeInfo {};

extern bool (__thiscall *typeEqual)(const TypeInfo *, const TypeInfo &);
extern const TypeInfo emptyType;
extern const TypeInfo integerType;
extern const TypeInfo stringType;

struct String {
    unsigned allocator;
    union {
        char local[16];
        char *pointer;
    } storage;
    unsigned length;
    unsigned capacity;

    ~String();
};

struct TypeName {
    unsigned prefix;
    String text;
};

struct Type {
    unsigned reserved[2];
    const TypeInfo *info;
    TypeName *name;
};

struct Placeholder {
    virtual void destroy();
    virtual const TypeInfo &type() const;
};

struct Any {
    Placeholder *content;
    void assign(const double *);
};

struct CastError {
    unsigned storage[10];
    CastError(const String &);
    CastError(const CastError &);
};

extern Type *__cdecl integerDescriptor();
extern String *__cdecl stringCast(Any *);
extern int *__cdecl integerCast(Any *);
extern bool __cdecl parseInteger(const String *, double *);
extern String __cdecl formatMessage(const char *, const char *, const char *);

struct Value {
    Type *descriptor;
    Any value;
    int *convert();
};

int *Value::convert()
{
    bool (__thiscall *equal)(const TypeInfo *, const TypeInfo &) = typeEqual;
    Any *source = &value;
    if (source) {
        const TypeInfo &info =
            source->content ? source->content->type() : emptyType;
        if (equal(&info, integerType)) {
            int *result = reinterpret_cast<int *>(
                reinterpret_cast<char *>(source->content) + 8);
            if (result)
                return result;
        }
    }

    const TypeInfo *descriptorInfo = descriptor->info;
    if (equal(&stringType, *descriptorInfo)) {
        double converted;
        if (parseInteger(stringCast(source), &converted)) {
            source->assign(&converted);
            descriptor = integerDescriptor();
            return integerCast(source);
        }
    }

    TypeName *destinationName = integerDescriptor()->name;
    const char *destination =
        destinationName->text.capacity >= 16
            ? destinationName->text.storage.pointer
            : destinationName->text.storage.local;

    String *sourceName = &descriptor->name->text;
    const char *origin =
        sourceName->capacity >= 16
            ? sourceName->storage.pointer
            : sourceName->storage.local;

    throw CastError(formatMessage("Unable to cast %s to %s",
                                  origin, destination));
}
