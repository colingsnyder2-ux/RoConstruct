// from server: 100% by king_originala
struct TypeInfo
{
    unsigned char storage[8];
};

extern TypeInfo emptyType;
extern TypeInfo textureType;
extern bool (__thiscall *equalType)(const TypeInfo *, const TypeInfo &);

struct Holder
{
    virtual ~Holder();
    virtual const TypeInfo &type() const;
};

struct Any
{
    Holder *content;
};

struct TextureId;

extern void (__thiscall *constructBadCast)(void *, const char *);

struct BadCast
{
    unsigned long storage[3];
    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    constructBadCast(this, "bad cast");
    storage[0] = 0x0080BA2CUL;
}

extern __declspec(noreturn) void __cdecl raise_bad_cast(const void *);

TextureId *__cdecl castTexture(Any *value)
{
    TextureId *result = 0;
    if (value)
    {
        const TypeInfo &type = value->content
            ? value->content->type()
            : emptyType;
        if (equalType(&type, textureType))
            result = reinterpret_cast<TextureId *>(
                reinterpret_cast<unsigned char *>(value->content) + 4);
    }

    if (!result)
    {
        BadCast error;
        raise_bad_cast(&error);
    }

    return result;
}
