// from server: 100% by king_originala
struct TypeInfo {};

struct Placeholder {
    virtual ~Placeholder();
    virtual const TypeInfo& type() const = 0;
};

struct Any {
    Placeholder* content;
};

extern const TypeInfo empty_type;
extern const TypeInfo mesh_type;
extern const char bad_cast_message[];
extern const unsigned long bad_cast_vtable[];

extern bool (__thiscall *type_info_equal)(const TypeInfo*, const TypeInfo*);
extern void (__thiscall *bad_cast_construct)(void*, const char*);
extern __declspec(noreturn) void __cdecl raise_bad_cast(const void*);

namespace std {
    struct bad_cast {
        unsigned long words[3];
        bad_cast();
        ~bad_cast();
    };
}

inline std::bad_cast::bad_cast()
{
    bad_cast_construct(this, bad_cast_message);
    words[0] = reinterpret_cast<unsigned long>(bad_cast_vtable);
}

void* __cdecl cast_value(Any* operand)
{
    void* result = 0;

    if (operand) {
        const TypeInfo* actual = operand->content
            ? &operand->content->type()
            : &empty_type;

        if (type_info_equal(actual, &mesh_type))
            result = reinterpret_cast<char*>(operand->content) + 4;
    }

    if (!result) {
        std::bad_cast error;
        raise_bad_cast(&error);
    }

    return result;
}
