// from server: 100% by king_originala
struct TypeInfo {};
extern const TypeInfo placeholder_type;
extern const TypeInfo vector_type;
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo *);

struct Placeholder {
    virtual void destroy() = 0;
    virtual const TypeInfo &type() const = 0;
};

struct Any {
    Placeholder *content;
};

extern void (__thiscall *construct_bad_cast)(void *, const char *);
__declspec(noreturn) void __cdecl raise_bad_cast(const void *);

struct BadCast {
    unsigned long data[3];
    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    construct_bad_cast(this, "bad cast");
    data[0] = 0x0080BA2CUL;
}

short *__cdecl cast_vector(Any *value)
{
    if (value) {
        const TypeInfo &type = value->content
            ? value->content->type()
            : placeholder_type;

        if (type_equal(&type, &vector_type)) {
            short *result = reinterpret_cast<short *>(
                reinterpret_cast<char *>(value->content) + 4);
            if (result)
                return result;
        }
    }

    BadCast error;
    raise_bad_cast(&error);
}
