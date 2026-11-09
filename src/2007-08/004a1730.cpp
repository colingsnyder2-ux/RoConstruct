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

namespace RBX { class BrickColor { public: BrickColor(); BrickColor(const BrickColor&); int number; }; }

template<class T, class B>
inline const T& checked_cast(const B& b)
{
    const T* p = dynamic_cast<const T*>(&b);
    if (!p)
        throw std::bad_cast("bad cast");
    return *p;
}

struct BoundFuncDesc {
    const RBX::Reflection::PropertyDescriptor* descriptor;
    void* instance;
    RBX::BrickColor getProperty() const;
};

RBX::BrickColor BoundFuncDesc::getProperty() const
{
    return checked_cast<RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor> >(*descriptor).getset->get(instance);
}
