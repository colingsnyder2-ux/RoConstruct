// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>
#include <exception>

// INFERRED: this is boost::any_cast<T&>(any*) for some held type T (unknown
// from the disassembly; typeid at 0x935398). It throws boost::bad_any_cast.

namespace boost {

class bad_any_cast : public std::bad_cast {
public:
    bad_any_cast() {}
};

template <class E>
__declspec(noreturn) void throw_exception(const E& e);

class any {
public:
    class placeholder {
    public:
        virtual ~placeholder() {}
        virtual const std::type_info& type() const = 0;
    };

    placeholder* content;
};

}

// INFERRED: held value type (BrickColor-like); layout: vptr then value at +4.
struct HeldType {
    int value;
};

struct HolderT : public boost::any::placeholder {
    const std::type_info& type() const { return typeid(HeldType); }
    HeldType held;
};

extern "C" HeldType* fn_0048b690(boost::any* operand)
{
    HeldType* result = 0;
    if (operand) {
        const std::type_info& t = operand->content
            ? operand->content->type()
            : typeid(void);
        if (t == typeid(HeldType))
            result = &static_cast<HolderT*>(operand->content)->held;
    }

    if (!result) {
        boost::throw_exception(boost::bad_any_cast());
    }

    return result;
}
