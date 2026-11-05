// from server: 100% by king_originala
class type_info {
public:
    bool operator==(const type_info&) const;
};

namespace std {
    class __declspec(novtable) bad_cast {
        char* message;
        int owns;
    public:
        bad_cast();
        virtual ~bad_cast();
        virtual const char* what() const;
    };
}

extern void (__thiscall *construct_bad_cast)(void*, const char*);
extern bool (__thiscall *compare_type_info)(
    const type_info*, const type_info&);
__declspec(noreturn) void __cdecl raise_bad_cast(const void*);

std::bad_cast::bad_cast()
{
    construct_bad_cast(this, "bad cast");
}

struct BadAnyCast : std::bad_cast {
    virtual const char* what() const;
};

const char* BadAnyCast::what() const
{
    return "boost::bad_any_cast: failed conversion using boost::any_cast";
}

struct Placeholder {
    virtual ~Placeholder();
    virtual const type_info& type() const = 0;
};

struct Any {
    Placeholder* content;
};

double __cdecl get_double(const Any* value)
{
    double* result = 0;
    if (value) {
        const type_info& type =
            value->content ? value->content->type() : typeid(void);
        if (compare_type_info(&type, typeid(double)))
            result = reinterpret_cast<double*>(
                reinterpret_cast<char*>(value->content) + 8);
    }
    if (!result) {
        BadAnyCast error;
        raise_bad_cast(&error);
    }
    return *result;
}
