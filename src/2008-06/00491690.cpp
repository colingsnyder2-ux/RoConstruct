// from server: 100% by king_originala
struct TypeInfo
{
    unsigned long data;
};

extern TypeInfo empty_type;
extern TypeInfo shared_type;
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo &);
extern void (__thiscall *construct_bad_cast)(void *, const char *);

struct BadCast
{
    unsigned long vtable;
    unsigned long message;
    unsigned long owned;

    BadCast(const char *);
    ~BadCast();
};

__forceinline BadCast::BadCast(const char *text)
{
    construct_bad_cast(this, text);
    vtable = 0x0080BA2CUL;
}

__declspec(noreturn) void __cdecl raise_bad_cast(const void *);

struct Placeholder
{
    virtual ~Placeholder();
    virtual const TypeInfo &type() const;
};

struct Any
{
    Placeholder *content;
};

void *__cdecl func_00491690(Any *value)
{
    if (value)
    {
        const TypeInfo &type =
            value->content ? value->content->type() : empty_type;
        if (type_equal(&type, shared_type))
        {
            void *result = reinterpret_cast<char *>(value->content) + 4;
            if (result)
                return result;
        }
    }

    raise_bad_cast(&BadCast("bad cast"));
}
