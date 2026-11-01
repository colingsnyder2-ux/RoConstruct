// from server: 100% by king_originala
struct TypeInfo {};

extern TypeInfo empty_type;
extern TypeInfo string_type;
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo &);

struct Holder
{
    virtual ~Holder();
    virtual const TypeInfo &type() const;
};

struct Any
{
    Holder *content;
};

extern void (__thiscall *construct_bad_cast)(void *, const char *);
extern void (__thiscall *destroy_bad_cast)(void *);
extern unsigned long bad_any_cast_vtable;
extern const char bad_cast_message[];
__declspec(noreturn) void __cdecl raise_bad_cast(const void *);

struct BadAnyCast
{
    unsigned long data[3];
    BadAnyCast();
    ~BadAnyCast();
};

inline BadAnyCast::BadAnyCast()
{
    construct_bad_cast(this, bad_cast_message);
    data[0] = reinterpret_cast<unsigned long>(&bad_any_cast_vtable);
}

inline BadAnyCast::~BadAnyCast()
{
    destroy_bad_cast(this);
}

void *__cdecl func_00563f60(Any *value)
{
    void *result;
    if (value &&
        type_equal(value->content ? &value->content->type() : &empty_type,
                   string_type) &&
        (result = reinterpret_cast<char *>(value->content) + 8) != 0)
        return result;

    BadAnyCast error;
    raise_bad_cast(&error);
}
