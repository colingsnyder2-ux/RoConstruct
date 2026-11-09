// from server: 100% by king_originala
extern void (__thiscall *construct_bad_cast)(void *, const char *);
extern bool (__thiscall *type_info_equal)(const void *, const void *);
__declspec(noreturn) void __cdecl raise_bad_cast(const void *);

struct Holder
{
    virtual ~Holder();
    virtual const void *type() const;
};

struct BadCast
{
    unsigned long storage[3];
    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    construct_bad_cast(this, "bad cast");
    storage[0] = 0x0080BA2CUL;
}

void *__cdecl func_00434470(Holder **operand)
{
    if (operand)
    {
        const void *type = *operand
            ? (*operand)->type()
            : reinterpret_cast<const void *>(0x00929614UL);

        if (type_info_equal(type, reinterpret_cast<const void *>(0x0092BEF8UL)))
        {
            void *result = reinterpret_cast<char *>(*operand) + 4;
            if (result)
                return result;
        }
    }

    BadCast error;
    raise_bad_cast(&error);
}
