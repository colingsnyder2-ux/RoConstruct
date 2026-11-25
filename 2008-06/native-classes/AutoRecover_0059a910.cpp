// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the two MSVCR90 imports are called through function-pointer slots
// (0x802878 = type_info::operator==, 0x802864 = std::bad_cast ctor), as in the analog.
extern void (__thiscall *construct_bad_cast)(void *, const char *);
extern bool (__thiscall *type_info_equal)(const void *, const void *);

// INFERRED: the constants in the disassembly are relocated data addresses, so they are
// declared as extern symbols instead of literal integers.
// 0x929614: type_info of the empty any placeholder
extern "C" char g_00929614[];
// 0x92bef8: type_info of the requested type
extern "C" char g_00946364[];
// 0x80ba2c: vtable of bad_any_cast
extern "C" char g_0080ba2c[];

// boost::throw_exception<boost::bad_any_cast>(const bad_any_cast&) at 0x0040a3f0
extern "C" __declspec(noreturn) void __cdecl fn_0040a3f0(const void *);

struct Holder
{
    virtual ~Holder();
    virtual const void *type() const;
};

// INFERRED: stands in for boost::bad_any_cast (derived from std::bad_cast)
struct BadCast
{
    unsigned long storage[3];
    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    construct_bad_cast(this, "bad cast");
    storage[0] = reinterpret_cast<unsigned long>(g_0080ba2c);
}

extern "C" void *__cdecl fn_0059a910(Holder **operand)
{
    if (operand)
    {
        const void *type = *operand
            ? (*operand)->type()
            : static_cast<const void *>(g_00929614);

        if (type_info_equal(type, static_cast<const void *>(g_00946364)))
        {
            void *result = reinterpret_cast<char *>(*operand) + 4;
            if (result)
                return result;
        }
    }

    BadCast error;
    fn_0040a3f0(&error);
}
