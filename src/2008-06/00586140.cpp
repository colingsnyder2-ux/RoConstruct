// from server: 100% by king_originala
class type_info {};

extern bool (__thiscall *equal_type)(const type_info *, const type_info &);
extern void (__thiscall *construct_bad_cast)(void *, const char *);
extern unsigned long bad_any_cast_vtable[];

struct BadAnyCast {
    unsigned long data[3];
    BadAnyCast();
    ~BadAnyCast();
};

BadAnyCast::BadAnyCast()
{
    construct_bad_cast(this, "bad cast");
    data[0] = reinterpret_cast<unsigned long>(bad_any_cast_vtable);
}

struct Placeholder {
    virtual ~Placeholder();
    virtual const type_info &type() const = 0;
};

struct Any {
    Placeholder *content;
};

struct ContentId {};

struct Holder : Placeholder {
    ContentId value;
};

extern const type_info empty_type;
extern const type_info content_id_type;
extern __declspec(noreturn) void __cdecl raise_bad_cast(const void *);

ContentId &__cdecl cast_content_id(Any *operand)
{
    ContentId *result = 0;
    if (operand) {
        const type_info &actual =
            operand->content ? operand->content->type() : empty_type;
        if (equal_type(&actual, content_id_type))
            result = &static_cast<Holder *>(operand->content)->value;
    }
    if (!result) {
        BadAnyCast error;
        raise_bad_cast(&error);
    }
    return *result;
}
