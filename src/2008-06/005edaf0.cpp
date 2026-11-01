// from server: 100% by king_originala
namespace std {
    class type_info {
    public:
        bool __thiscall operator==(const type_info&) const;
    };
}

extern bool (__thiscall *type_equal)(
    const std::type_info*, const std::type_info&);
extern void (__thiscall *construct_bad_cast)(void*, const char*);
extern void (__thiscall *destroy_bad_cast)(void*);

extern const std::type_info empty_type;
extern const std::type_info surface_type;
extern const void* bad_cast_vtable[];

struct Placeholder {
    virtual ~Placeholder();
    virtual const std::type_info& type() const;
};

struct Any {
    Placeholder* content;
};

struct BadCast {
    const void* vtable;
    int data[2];

    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    construct_bad_cast(this, "bad cast");
    vtable = bad_cast_vtable;
}

inline BadCast::~BadCast()
{
    destroy_bad_cast(this);
}

__declspec(noreturn) void __cdecl raise_bad_cast(const void* source);

int* __cdecl cast_surface(Any* value)
{
    if (value) {
        const std::type_info& type =
            value->content ? value->content->type() : empty_type;
        if (type_equal(&type, surface_type)) {
            int* result = reinterpret_cast<int*>(
                reinterpret_cast<char*>(value->content) + 4);
            if (result)
                return result;
        }
    }

    BadCast error;
    raise_bad_cast(&error);
}
