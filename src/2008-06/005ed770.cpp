// from server: 100% by king_originala
class type_info {
public:
    bool operator==(const type_info&) const;
};

extern const type_info empty_type;
extern const type_info surface_type;

extern bool (__thiscall* const compare_type)(
    const type_info*, const type_info&);

struct bad_any_cast {
    const void* vtable;
    const char* message;
    int owned;

    bad_any_cast();
    ~bad_any_cast();
};

extern void (__thiscall* const construct_bad_cast)(
    bad_any_cast*, const char*);
extern const void* const bad_any_cast_vtable[];

inline bad_any_cast::bad_any_cast()
{
    construct_bad_cast(this, "bad cast");
    vtable = bad_any_cast_vtable;
}

__declspec(noreturn) void __cdecl throw_exception(const bad_any_cast&);

enum SurfaceType {
    SurfaceType_Default = 0
};

struct placeholder {
    virtual ~placeholder();
    virtual const type_info& type() const = 0;
};

struct holder : placeholder {
    SurfaceType held;
};

struct any {
    placeholder* content;
};

SurfaceType& __cdecl cast_surface(any& operand)
{
    SurfaceType* result = 0;

    if (&operand) {
        const type_info& t = operand.content
            ? operand.content->type()
            : empty_type;

        if (compare_type(&t, surface_type))
            result = &static_cast<holder*>(operand.content)->held;
    }

    if (!result)
        throw_exception(bad_any_cast());

    return *result;
}
