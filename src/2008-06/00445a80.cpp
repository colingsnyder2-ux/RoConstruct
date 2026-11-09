// from server: 100% by king_originala
namespace std {
    class type_info {
    public:
        bool __thiscall operator==(const type_info &) const;
    };
}

extern const std::type_info empty_type;
extern const std::type_info requested_type;
extern bool (__thiscall *type_equal)(const std::type_info *, const std::type_info &);

struct BadCast {
    unsigned long vtable;
    const char *message;
    int owned;

    BadCast(const char *);
    ~BadCast();
};

extern void (__thiscall *construct_bad_cast)(BadCast *, const char *);
extern unsigned long bad_cast_vtable[];
extern __declspec(noreturn) void __cdecl raise_bad_cast(const void *);

inline BadCast::BadCast(const char *text)
{
    construct_bad_cast(this, text);
    vtable = reinterpret_cast<unsigned long>(bad_cast_vtable);
}

struct Placeholder {
    virtual ~Placeholder();
    virtual const std::type_info &type() const = 0;
};

struct Any {
    Placeholder *content;
};

void *__cdecl checked_cast(Any *operand)
{
    if (operand) {
        const std::type_info &actual =
            operand->content ? operand->content->type() : empty_type;
        if (type_equal(&actual, requested_type)) {
            void *result = reinterpret_cast<char *>(operand->content) + 4;
            if (result)
                return result;
        }
    }

    BadCast error("bad cast");
    raise_bad_cast(&error);
}
