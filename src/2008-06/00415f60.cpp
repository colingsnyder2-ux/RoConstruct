// from server: 100% by king_originala
struct TypeInfo;

struct Placeholder
{
    virtual ~Placeholder();
    virtual const TypeInfo& type() const;
};

struct Any
{
    Placeholder* content;
};

struct BadCast
{
    unsigned long data[3];
    BadCast(const char*);
    ~BadCast();
};

extern const TypeInfo void_type;
extern const TypeInfo bool_type;

extern bool (__thiscall *type_equal)(const TypeInfo*, const TypeInfo&);
extern void (__thiscall *construct_bad_cast)(BadCast*, const char*);

__declspec(noreturn) void __cdecl raise_bad_cast(const void* source);

__forceinline BadCast::BadCast(const char* message)
{
    construct_bad_cast(this, message);
    data[0] = 0x0080BA2CUL;
}

bool __cdecl read_bool(const Any* value)
{
    bool* result = 0;
    if (value)
    {
        const TypeInfo& type =
            value->content ? value->content->type() : void_type;
        if (type_equal(&type, bool_type))
            result = reinterpret_cast<bool*>(
                reinterpret_cast<char*>(value->content) + 4);
    }

    if (!result)
    {
        BadCast error("bad cast");
        raise_bad_cast(&error);
    }

    return *result;
}
