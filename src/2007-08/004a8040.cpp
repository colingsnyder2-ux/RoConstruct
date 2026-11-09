// from server: 100% by tajop
#include <typeinfo>

namespace RBX {
namespace Reflection {

class PropertyDescriptor {
public:
    virtual ~PropertyDescriptor();
    char pad[0x14];
};

template<class T>
class TypedPropertyDescriptor : public PropertyDescriptor {
public:
    class GetSet {
    public:
        virtual ~GetSet();
        virtual T get(const void* instance) const = 0;
        virtual void set(void* instance, const T& value) const = 0;
    };
    GetSet* getset;
};

}
}

template<class T, class B>
inline const T& checked_cast(const B& b)
{
    const T* p = dynamic_cast<const T*>(&b);
    if (!p)
        throw std::bad_cast("bad cast");
    return *p;
}
struct ChangePropertyItem {
    const RBX::Reflection::PropertyDescriptor* descriptor;
    void* instance;
    void ChangeProperty(const bool& value);
};

void ChangePropertyItem::ChangeProperty(const bool& value)
{
    checked_cast<RBX::Reflection::TypedPropertyDescriptor<bool> >(*descriptor).getset->set(instance, value);
}
