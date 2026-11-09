// from server: 100% by king_originala
struct TypeInfo {};
extern const TypeInfo emptyType;
extern const TypeInfo targetType;
extern bool (__thiscall *typeEqual)(const TypeInfo*, const TypeInfo&);

struct Holder {
    virtual ~Holder();
    virtual const TypeInfo& type() const;
    unsigned long value;
};

struct Storage {
    Holder* content;
};

extern void (__thiscall *construct_bad_cast)(void*, const char*);
extern __declspec(noreturn) void __cdecl raise_bad_cast(const void*);
extern const unsigned long badCastVtable[];

struct BadCast {
    unsigned long object[3];
    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    construct_bad_cast(this, "bad cast");
    object[0] = reinterpret_cast<unsigned long>(badCastVtable);
}

unsigned long* __cdecl cast_value(Storage* source)
{
    unsigned long* result = 0;
    if (source) {
        const TypeInfo& type = source->content
            ? source->content->type() : emptyType;
        if (typeEqual(&type, targetType))
            result = &source->content->value;
    }
    if (!result) {
        BadCast error;
        raise_bad_cast(&error);
    }
    return result;
}
