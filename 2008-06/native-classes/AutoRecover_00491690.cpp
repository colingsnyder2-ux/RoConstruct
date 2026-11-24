// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout/names follow the server-verified analog; globals use g_<address> names.
struct TypeInfo
{
    unsigned long data;
};

extern "C" TypeInfo g_00929614;   // empty type (typeid(void))
extern "C" TypeInfo g_00937010;   // expected held type
extern "C" bool (__thiscall *g_00802878)(const TypeInfo *, const TypeInfo &);  // type_info::operator== import
extern "C" void (__thiscall *g_00802864)(void *, const char *);                // std::bad_cast ctor import

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
    g_00802864(this, text);
    vtable = 0x0080BA2CUL;
}

// boost::throw_exception<boost::bad_any_cast>
extern "C" __declspec(noreturn) void __cdecl fn_0040a3f0(const void *);

struct Placeholder
{
    virtual ~Placeholder();
    virtual const TypeInfo &type() const;
};

struct Any
{
    Placeholder *content;
};

extern "C" void *__cdecl fn_00491690(Any *value)
{
    if (value)
    {
        const TypeInfo &type =
            value->content ? value->content->type() : g_00929614;
        if (g_00802878(&type, g_00937010))
        {
            void *result = reinterpret_cast<char *>(value->content) + 4;
            if (result)
                return result;
        }
    }

    fn_0040a3f0(&BadCast("bad cast"));
}
