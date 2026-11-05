// from server: 100% by king_originala
struct TypeInfo {};

extern bool (__thiscall *same_type)(const TypeInfo*, const TypeInfo&);
extern void (__thiscall *construct_bad_cast)(void*, const char*);
extern __declspec(noreturn) void __cdecl raise_bad_cast(const void*);

struct BadCast {
    unsigned long words[3];
    BadCast(const char* message) {
        construct_bad_cast(this, message);
        words[0] = 0x0080BA2CUL;
    }
    ~BadCast();
};

struct Placeholder {
    virtual ~Placeholder();
    virtual const TypeInfo& type() const;
    unsigned long value;
};

struct Any {
    Placeholder* content;
};

unsigned long __cdecl cast_value(const Any* source)
{
    unsigned long* result = 0;
    if (source) {
        const TypeInfo& type = source->content
            ? source->content->type()
            : *reinterpret_cast<const TypeInfo*>(0x00929614UL);
        if (same_type(&type,
                      *reinterpret_cast<const TypeInfo*>(0x0092BED0UL)))
            result = &source->content->value;
    }
    if (!result) {
        BadCast error(reinterpret_cast<const char*>(0x0080BA34UL));
        raise_bad_cast(&error);
    }
    return *result;
}
