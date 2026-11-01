// from server: 100% by king_originala
namespace std {
    class type_info {
        unsigned long data[2];
    };
}

struct Placeholder {
    virtual void destroy();
    virtual const std::type_info &type() const;
};

struct Any {
    Placeholder *content;
};

struct Vector3 {
    float x, y, z;
};

extern bool (__thiscall *equal_type)(const std::type_info *,
                                    const std::type_info *);
extern void (__thiscall *construct_bad_cast)(void *, const char *);
extern __declspec(noreturn) void __cdecl raise_bad_cast(const void *);

struct BadCast {
    unsigned long data[3];
    BadCast(const char *);
    ~BadCast();
};

__forceinline BadCast::BadCast(const char *message)
{
    construct_bad_cast(this, message);
    data[0] = 0x0080BA2CUL;
}

Vector3 *__cdecl cast_vector(Any *value)
{
    if (value) {
        const std::type_info *type =
            value->content ? &value->content->type()
                           : reinterpret_cast<const std::type_info *>(0x00929614UL);
        if (equal_type(type,
                       reinterpret_cast<const std::type_info *>(0x00946364UL))) {
            Vector3 *result =
                reinterpret_cast<Vector3 *>(value->content + 1);
            if (result)
                return result;
        }
    }

    BadCast error("bad cast");
    raise_bad_cast(&error);
}
