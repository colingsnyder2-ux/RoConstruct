// from server: 100% by king_originala
struct TypeInfo {};

extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo &);
extern void (__thiscall *construct_bad_cast)(void *, const char *);

struct BadCast {
    unsigned long table;
    unsigned long data[2];

    BadCast(const char *);
    ~BadCast();
};

inline BadCast::BadCast(const char *message)
{
    construct_bad_cast(this, message);
    table = 0x0080BA2CUL;
}

__declspec(noreturn) void __cdecl raise_bad_cast(const void *);

struct Placeholder {
    virtual void destroy();
    virtual const TypeInfo &type() const;
};

struct Any {
    Placeholder *content;
};

void *__cdecl cast_color(Any *value)
{
    if (value) {
        const TypeInfo &actual = value->content
            ? value->content->type()
            : *reinterpret_cast<const TypeInfo *>(0x00929614UL);

        if (type_equal(&actual,
                       *reinterpret_cast<const TypeInfo *>(0x009463A4UL))) {
            void *result = reinterpret_cast<char *>(value->content) + 4;
            if (result)
                return result;
        }
    }

    BadCast error("bad cast");
    raise_bad_cast(&error);
}
