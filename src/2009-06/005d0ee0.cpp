// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
namespace boost {
class any {
public:
    any() : content(0) {}
    template<typename ValueType> any(const ValueType& value) : content(new holder<ValueType>(value)) {}
    any(const any& other) : content(other.content ? other.content->clone() : 0) {}
    ~any() { delete content; }
    any& swap(any& rhs) { std::swap(content, rhs.content); return *this; }
    template<typename ValueType> any& operator=(const ValueType& rhs) { any(rhs).swap(*this); return *this; }
    any& operator=(const any& rhs) { any(rhs).swap(*this); return *this; }
    class placeholder {
    public:
        virtual ~placeholder() {}
        virtual const std::type_info& type() const = 0;
        virtual placeholder* clone() const = 0;
    };
    template<typename ValueType> class holder : public placeholder {
    public:
        holder(const ValueType& value) : held(value) {}
        virtual const std::type_info& type() const { return typeid(ValueType); }
        virtual placeholder* clone() const { return new holder(held); }
        ValueType held;
    };
    placeholder* content;
};
template<> any::any(const std::string& value);
}
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
typedef std::vector<boost::any> Arguments;
class SlotWrapper {
public:
    virtual ~SlotWrapper();
    virtual void call(const Arguments& args);
    void operator()(const Reflection::PropertyDescriptor* a1);
};
void SlotWrapper::operator()(const Reflection::PropertyDescriptor* a1)
{
    Arguments args(1);
    args[0] = a1;
    call(args);
}
}
