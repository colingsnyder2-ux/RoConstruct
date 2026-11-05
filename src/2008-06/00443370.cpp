// from server: 100% by king_originala
struct TypeInfo {};

extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo &);
extern void (__thiscall *construct_bad_cast)(void *, const char *);
extern __declspec(noreturn) void __cdecl raise_bad_cast(const void *);

struct BadCast {
    unsigned long data[3];
    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    construct_bad_cast(this, reinterpret_cast<const char *>(0x0080BA34UL));
    data[0] = 0x0080BA2CUL;
}

struct Placeholder {
    virtual ~Placeholder();
    virtual const TypeInfo &type() const;
};

struct Any {
    Placeholder *content;
};

void *__cdecl checked_cast(Any *operand)
{
    void *result = 0;
    if (operand) {
        const TypeInfo &actual = operand->content
            ? operand->content->type()
            : *reinterpret_cast<const TypeInfo *>(0x00929614UL);
        if (type_equal(&actual,
                       *reinterpret_cast<const TypeInfo *>(0x0092BED0UL)))
            result = reinterpret_cast<char *>(operand->content) + 4;
    }
    if (!result) {
        BadCast error;
        raise_bad_cast(&error);
    }
    return result;
}
