// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <memory>
#include <typeinfo>
extern unsigned char g_assertEnabled;
extern char (__cdecl *g_assertHook)(const char*, const char*, int);
void __cdecl g_assertFail(unsigned char, const char*);
#define FILE_ "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\reflection/property.h"
#define ASSERT_(cond, cs, line, lines) if (g_assertEnabled && !(cond)) { if (!g_assertHook || !g_assertHook(cs, FILE_, line)) g_assertFail(g_assertEnabled, cs " file: " FILE_ " line: " lines); }
namespace RBX {
namespace Reflection {
class ClassDescriptor;
class PropertyDescriptor {
public:
    struct Functionality { int a; int b; int c; };
    virtual ~PropertyDescriptor();
    char pad[0x24];
};
template<class PropType>
class TypedPropertyDescriptor : public PropertyDescriptor {
public:
    class GetSet {
    public:
        virtual bool isReadOnly() const = 0;
        virtual bool isWriteOnly() const = 0;
        virtual PropType getValue(const void* object) const = 0;
        virtual void setValue(void* object, const PropType& value) const = 0;
    };
    std::auto_ptr<GetSet> getset;
    TypedPropertyDescriptor(ClassDescriptor& classDescriptor, const char* name, const char* category, std::auto_ptr<GetSet> getset, Functionality flags, int security);
    virtual ~TypedPropertyDescriptor();
};
template<class PropType, int N>
class BoundProp : public TypedPropertyDescriptor<PropType> {
    typedef typename TypedPropertyDescriptor<PropType>::GetSet GetSet;
    template<class Class>
    class BoundPropGetSet : public GetSet {
    public:
        BoundProp* desc;
        PropType Class::*member;
        int pad;
        void (Class::*changed)(const PropertyDescriptor&);
        typedef void (Class::*Changed)(const PropertyDescriptor&); BoundPropGetSet(BoundProp* desc, PropType Class::*member, Changed changed = 0) : desc(desc), member(member), changed(changed) {}
        virtual bool isReadOnly() const;
        virtual bool isWriteOnly() const;
        virtual PropType getValue(const void* object) const;
        virtual void setValue(void* object, const PropType& value) const;
    };
public:
    template<class Class>
    BoundProp(const char* name, const char* category, PropType Class::*member, PropertyDescriptor::Functionality flags, int security)
        : TypedPropertyDescriptor<PropType>(Class::classDescriptor(), name, category, std::auto_ptr<GetSet>(), flags, security)
    {
        ASSERT_(Class::classType()==typeid(Class), "Class::classType()==typeid(Class)", 0x1b0, "432")
        this->getset.reset(new BoundPropGetSet<Class>(this, member));
    }
    virtual ~BoundProp();
};
}
class B1 { public: int x; };
class B2 { public: int y; };
namespace Network {
}}
using namespace RBX; using namespace RBX::Network;
namespace RBX { 
class ClickDetector : public B1, public B2 {
public:
    static const std::type_info& classType() { return typeid(ClickDetector); }
    static Reflection::ClassDescriptor& classDescriptor();
    float f;
};
}
namespace RBX { namespace Network { 

}
}
template RBX::Reflection::BoundProp<float, 1>::BoundProp(const char*, const char*, float ::RBX::ClickDetector::*, RBX::Reflection::PropertyDescriptor::Functionality, int);

