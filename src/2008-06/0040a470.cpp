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
    unsigned long words[3];
    BadCast();
    ~BadCast();
};

extern bool (__thiscall *type_equal)(const TypeInfo*, const TypeInfo&);
extern void (__thiscall *construct_bad_cast)(void*, const char*);
__declspec(noreturn) void __cdecl raise_bad_cast(const void*);

__forceinline BadCast::BadCast()
{
    construct_bad_cast(this, reinterpret_cast<const char*>(0x0080BA34UL));
    words[0] = 0x0080BA2CUL;
}

void* __cdecl any_cast(Any* value)
{
    void* result = 0;

    if (value)
    {
        const TypeInfo* type = value->content
            ? &value->content->type()
            : reinterpret_cast<const TypeInfo*>(0x00929614UL);

        if (type_equal(type, *reinterpret_cast<const TypeInfo*>(0x00929644UL)))
            result = reinterpret_cast<char*>(value->content) + 4;
    }

    if (!result)
    {
        BadCast error;
        raise_bad_cast(&error);
    }

    return result;
}
