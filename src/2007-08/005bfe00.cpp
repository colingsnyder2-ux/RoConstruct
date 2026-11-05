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

namespace boost { template<class T> class shared_ptr { public: shared_ptr(); shared_ptr(const shared_ptr&); ~shared_ptr(); T* px; void* pn; }; }
namespace RBX { namespace Reflection { class DescribedBase; } }

template<class T, class B>
inline const T& checked_cast(const B& b)
{
    const T* p = dynamic_cast<const T*>(&b);
    if (!p)
        throw std::bad_cast("bad cast");
    return *p;
}
struct LuaArguments {
    const RBX::Reflection::PropertyDescriptor* descriptor;
    void* instance;
    void setProperty(const boost::shared_ptr<RBX::Reflection::DescribedBase>& value);
};

void LuaArguments::setProperty(const boost::shared_ptr<RBX::Reflection::DescribedBase>& value)
{
    typedef RBX::Reflection::TypedPropertyDescriptor<boost::shared_ptr<RBX::Reflection::DescribedBase> > Desc;
    checked_cast<Desc >(*descriptor).getset->set(instance, value);
}
