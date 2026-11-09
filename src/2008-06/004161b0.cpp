// from server: 100% by king_originala
struct TypeInfo {};
extern TypeInfo placeholderType;
extern TypeInfo contentIdType;
extern bool (__thiscall *sameType)(const TypeInfo *, const TypeInfo *);

struct Placeholder {
    virtual void destroy() = 0;
    virtual const TypeInfo &type() const = 0;
};

struct Any {
    Placeholder *value;
};

struct String {
    unsigned char storage[28];
    String(const String &);
    ~String();
};

extern void (__thiscall *copyString)(String *, const String *);

String::String(const String &other)
{
    copyString(this, &other);
}

struct ContentId {
    String text;
    unsigned int value;
    ContentId(const ContentId &);
};

ContentId::ContentId(const ContentId &other)
    : text(other.text), value(other.value)
{
}

struct BadCast {
    const void *vtable;
    unsigned int data[2];
    BadCast();
    ~BadCast();
};

extern const unsigned int badAnyCastVtable[];
extern void (__thiscall *constructBadCast)(BadCast *, const char *);
extern __declspec(noreturn) void __cdecl raiseBadCast(const BadCast &);

BadCast::BadCast()
{
    constructBadCast(this, "bad cast");
    vtable = badAnyCastVtable;
}

static __forceinline const ContentId *contentPointer(const Any *source)
{
    if (source) {
        const TypeInfo &type = source->value
            ? source->value->type()
            : placeholderType;
        if (sameType(&type, &contentIdType))
            return reinterpret_cast<const ContentId *>(
                reinterpret_cast<const char *>(source->value) + 4);
    }
    return 0;
}

ContentId __cdecl extractContentId(const Any *source)
{
    const ContentId *content = contentPointer(source);
    if (!content) {
        BadCast error;
        raiseBadCast(error);
    }
    return ContentId(*content);
}
