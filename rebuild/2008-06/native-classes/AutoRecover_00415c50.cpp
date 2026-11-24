// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: minimal boost::any layout (boost 1.34 style); vtable slot 1 = type(), held value at +8 (double alignment)
namespace boost {
class any {
public:
    class placeholder {
    public:
        virtual ~placeholder() {}
        virtual const std::type_info& type() const = 0;
    };
    template <typename T>
    class holder : public placeholder {
    public:
        virtual const std::type_info& type() const { return typeid(T); }
        T held;
    };

    const std::type_info& type() const { return content ? content->type() : typeid(void); }

    placeholder* content;
};

template <typename T>
T* any_cast(any* operand)
{
    return operand && operand->type() == typeid(T)
        ? &static_cast<any::holder<T>*>(operand->content)->held
        : 0;
}

template double* any_cast<double>(any*);
}
