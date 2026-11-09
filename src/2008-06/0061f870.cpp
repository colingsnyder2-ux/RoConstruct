// from server: 100% by king_originala
class type_info {
public:
    virtual ~type_info();
    bool __thiscall operator==(const type_info&) const;
};

extern bool (__thiscall *type_info_equal)(
    const type_info*, const type_info&);

inline bool type_info::operator==(const type_info& other) const
{
    return type_info_equal(this, other);
}

namespace std {
    typedef ::type_info type_info;

    class exception {
    public:
        virtual ~exception() throw();
        virtual const char* what() const throw();

    private:
        const char* message;
        bool owned;
    };

    class bad_cast : public exception {
    public:
        explicit bad_cast(const char* = "bad cast") throw();
        virtual ~bad_cast() throw();
    };
}

namespace boost {
    struct placeholder {
        virtual ~placeholder();
        virtual const std::type_info& type() const = 0;
    };

    struct any {
        placeholder* content;
    };

    struct descriptor_holder : placeholder {
        const char* held;
    };

    class bad_any_cast : public std::bad_cast {
    public:
        virtual const char* what() const throw();
    };

    __declspec(noreturn)
    void __cdecl throw_exception(const bad_any_cast&);

    const char* __cdecl any_cast(const any*);
}

extern void* bad_any_cast_vtable[];
extern void (__thiscall *bad_cast_construct)(void*, const char*);

struct cast_exception {
    void* vtable;
    const char* message;
    int owned;

    cast_exception();
    ~cast_exception();
};

inline cast_exception::cast_exception()
{
    bad_cast_construct(this, "bad cast");
    vtable = bad_any_cast_vtable;
}

inline cast_exception::~cast_exception()
{
    reinterpret_cast<boost::bad_any_cast*>(this)->boost::bad_any_cast::~bad_any_cast();
}

const char* __cdecl boost::any_cast(const boost::any* operand)
{
    const char* const* value =
        operand &&
        (operand->content ? operand->content->type() : typeid(void)) ==
            typeid(const char*)
        ? &static_cast<const boost::descriptor_holder*>(operand->content)->held
        : 0;

    if (!value)
        boost::throw_exception(
            reinterpret_cast<const boost::bad_any_cast&>(cast_exception()));

    return *value;
}
