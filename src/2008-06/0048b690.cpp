// from server: 100% by king_originala
class type_info {
public:
    virtual ~type_info();
    bool operator==(const type_info &) const;
};

namespace RBX {
    class BrickColor {};
}

struct Placeholder {
    virtual ~Placeholder();
    virtual const type_info &type() const = 0;
};

struct Any {
    Placeholder *content;
};

extern bool (__thiscall *type_equal)(
    const type_info *, const type_info &);

extern void (__thiscall *construct_bad_cast)(void *, const char *);

struct BadCast {
    unsigned long vtable;
    char *message;
    unsigned long owned;

    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    construct_bad_cast(this, "bad cast");
    vtable = 0x0080BA2CUL;
}

__declspec(noreturn) void __cdecl raise_bad_cast(const void *);

RBX::BrickColor &__cdecl cast_brick_color(Any *value)
{
    RBX::BrickColor *result = 0;
    if (value) {
        const type_info &type =
            value->content ? value->content->type() : typeid(void);
        if (type_equal(&type, typeid(RBX::BrickColor)))
            result = reinterpret_cast<RBX::BrickColor *>(value->content + 1);
    }

    if (!result) {
        BadCast error;
        raise_bad_cast(&error);
    }

    return *result;
}
