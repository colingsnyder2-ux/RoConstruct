// from server: 100% by king_originala
struct TypeInfo {};
extern const TypeInfo placeholderType;
extern const TypeInfo requestedType;
extern bool (__thiscall *typeEqual)(const TypeInfo*, const TypeInfo&);

struct Placeholder {
    virtual ~Placeholder();
    virtual const TypeInfo& type() const;
};

struct Any {
    Placeholder* content;
};

extern void (__thiscall *construct_bad_cast)(void*, const char*);
extern const char badCastMessage[];
__declspec(noreturn) void __cdecl raise_bad_cast(const void*);

struct BadCast {
    unsigned long table;
    unsigned long data[2];

    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    construct_bad_cast(this, badCastMessage);
    table = 0x0080BA2CUL;
}

void* __cdecl cast_value(Any* value)
{
    if (value) {
        const TypeInfo& type = value->content
            ? value->content->type()
            : placeholderType;
        if (typeEqual(&type, requestedType)) {
            void* result = reinterpret_cast<char*>(value->content) + 4;
            if (result)
                return result;
        }
    }

    BadCast error;
    raise_bad_cast(&error);
}
