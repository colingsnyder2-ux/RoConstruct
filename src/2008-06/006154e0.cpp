// from server: 100% by king_originala
struct TypeInfo;
typedef bool (__thiscall *TypeEqual)(const TypeInfo*, const TypeInfo&);
extern TypeEqual typeEqual;

struct TypeInfo {
    __forceinline bool equals(const TypeInfo& other, TypeEqual compare) const;
};

__forceinline bool TypeInfo::equals(const TypeInfo& other, TypeEqual compare) const
{
    return compare(this, other);
}

extern const TypeInfo emptyType;
extern const TypeInfo meshType;
extern const TypeInfo stringType;

struct String;
extern void (__thiscall *destroyString)(String*);

struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;

    __forceinline ~String();
};

__forceinline String::~String()
{
    destroyString(this);
}

struct MeshId : String {
    unsigned int extra;
    MeshId();
};

struct Placeholder {
    virtual void unused();
    virtual const TypeInfo& type() const;
};

struct Any {
    Placeholder* content;
    Any& assign(const MeshId&);
};

struct Descriptor {
    unsigned int words[2];
    const TypeInfo* castType;
    const TypeInfo* storedType;
};

struct Error {
    char storage[40];
    Error(const String&);
    Error(const Error&);
    ~Error();
};

extern Descriptor* __cdecl meshDescriptor();
extern String* __cdecl stringCast(Any*);
extern bool __cdecl convertString(const String*, MeshId*);
extern MeshId* __cdecl meshCast(Any*);
extern String __cdecl format(const char*, ...);

struct S {
    Descriptor* descriptor;
    Any value;

    MeshId* get();
};

MeshId* S::get()
{
    TypeEqual equal = typeEqual;
    Any* source = &value;
    if (source) {
        const TypeInfo& type = source->content
            ? source->content->type()
            : emptyType;
        if (type.equals(meshType, equal)) {
            MeshId* result = reinterpret_cast<MeshId*>(
                reinterpret_cast<char*>(source->content) + 4);
            if (result)
                return result;
        }
    }

    if (stringType.equals(*descriptor->castType, equal)) {
        MeshId converted;
        if (convertString(stringCast(source), &converted)) {
            source->assign(converted);
            descriptor = meshDescriptor();
            return meshCast(source);
        }
    }

    const String* destinationName = reinterpret_cast<const String*>(
        reinterpret_cast<const char*>(meshDescriptor()->storedType) + 4);
    const char* destination = destinationName->capacity >= 16
        ? destinationName->pointer
        : destinationName->buffer;

    const String* sourceName = reinterpret_cast<const String*>(
        reinterpret_cast<const char*>(descriptor->storedType) + 4);
    const char* origin = sourceName->capacity >= 16
        ? sourceName->pointer
        : sourceName->buffer;

    throw Error(format("Unable to cast %s to %s", origin, destination));
}
