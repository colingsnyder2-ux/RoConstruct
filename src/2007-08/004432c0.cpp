// from server: 100% by EspClaude
// roc 2007-08 004432c0  RBX::Instance::findFirstChildOfType<Reflection::Metadata::Events>
// roc-flags: /O2 /GS /EHsc /MD
#include <vector>
namespace boost {
template<class T> class shared_ptr {
    typedef shared_ptr<T> this_type;
    T* px; void* pn;
public:
    T* get() const { return px; }
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    typedef T* this_type::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &this_type::px; }
};
}
namespace RBX {
template<class T> class CopyOnWrite {
    boost::shared_ptr<T> object;
public:
    const T& operator*() const { return *object; }
    const T* operator->() const { return object.get(); }
    operator bool() const { return object; }
};
class Instance {
public:
    virtual ~Instance();
    char pad[0xbc];
    CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > children;  // exe +0xc0
    template<class T> T* findFirstChildOfType() const
    {
        if (children) {
            std::vector<boost::shared_ptr<Instance> >::const_iterator end = children->end();
            std::vector<boost::shared_ptr<Instance> >::const_iterator iter = children->begin();
            for (; iter != end; iter++) {
                if (T* result = dynamic_cast<T*>((*iter).get()))
                    return result;
            }
        }
        return 0;
    }
};
namespace Reflection { namespace Metadata {
class Classes : public Instance {};
class Properties : public Instance {};
class Events : public Instance {};
class Functions : public Instance {};
}}
}
template RBX::Reflection::Metadata::Events* RBX::Instance::findFirstChildOfType<RBX::Reflection::Metadata::Events>() const;
