// from server: 100% by king_originala
struct TypeInfo {};

extern const TypeInfo empty_type;
extern const TypeInfo float_type;
extern const char bad_cast_message[];
extern unsigned long bad_cast_vtable[];

extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo &);
extern void (__thiscall *construct_bad_cast)(void *, const char *);

struct BadCast
{
    unsigned long words[3];
    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    construct_bad_cast(this, bad_cast_message);
    words[0] = reinterpret_cast<unsigned long>(bad_cast_vtable);
}

__declspec(noreturn) void __cdecl raise_bad_cast(const void *);

struct Placeholder
{
    virtual ~Placeholder();
    virtual const TypeInfo &type() const;
};

struct FloatHolder : Placeholder
{
    float value;
};

struct Any
{
    Placeholder *content;
};

float __cdecl extract_float(const Any *source)
{
    float *value = 0;

    if (source)
    {
        const TypeInfo &type = source->content
            ? source->content->type()
            : empty_type;

        if (type_equal(&type, float_type))
            value = &static_cast<FloatHolder *>(source->content)->value;
    }

    if (!value)
    {
        BadCast error;
        raise_bad_cast(&error);
    }

    return *value;
}
