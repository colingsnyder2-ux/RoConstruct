// from server: 100% by king_originala
struct TypeInfo {};

extern bool (__thiscall *type_info_equal)(const TypeInfo *, const TypeInfo *);
extern void (__thiscall *construct_bad_cast)(void *, const char *);
extern __declspec(noreturn) void __cdecl raise_bad_cast(const void *);

struct BadCast {
    unsigned long words[3];
    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    construct_bad_cast(this, reinterpret_cast<const char *>(0x0080BA34UL));
    words[0] = 0x0080BA2CUL;
}

struct Placeholder {
    virtual ~Placeholder();
    virtual const TypeInfo &type() const = 0;
};

struct Any {
    Placeholder *content;
};

void *__cdecl cast_coordinate_frame(Any *value)
{
    if (value) {
        const TypeInfo *type = value->content
            ? &value->content->type()
            : reinterpret_cast<const TypeInfo *>(0x00929614UL);

        if (type_info_equal(type,
                reinterpret_cast<const TypeInfo *>(0x00946380UL))) {
            void *result = reinterpret_cast<char *>(value->content) + 4;
            if (result)
                return result;
        }
    }

    BadCast error;
    raise_bad_cast(&error);
}
