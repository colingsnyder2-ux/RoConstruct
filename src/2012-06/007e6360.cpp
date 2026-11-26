// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <memory>
#include <string>
#include <typeinfo>
extern unsigned char g_assertEnabled;
extern char (__cdecl *g_assertHook)(const char*, const char*, int);
void __cdecl g_assertFail(unsigned char, const char*);
#define FILE_ "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Reflection/Reflection.h"
#define ASSERT_(cond, cs, line, lines) if (g_assertEnabled && !(cond)) { if (!g_assertHook || !g_assertHook(cs, FILE_, line)) g_assertFail(g_assertEnabled, cs " file: " FILE_ " line: " lines); }
namespace RBX {
class BrickColor { public: int number; };
namespace Reflection {
class ClassDescriptor;
class PropertyDescriptor {
public:
    struct Functionality { int a; int b; int c; };
    virtual ~PropertyDescriptor();
};
template<class PropType>
class TypedPropertyDescriptor : public PropertyDescriptor {
public:
    class GetSet {
    public:
        int pad;
        virtual PropType getValue(const void* object) const = 0;
    };
    TypedPropertyDescriptor(ClassDescriptor& classDescriptor, const char* name, const char* category, std::auto_ptr<GetSet> getset, Functionality flags, int security);
    virtual ~TypedPropertyDescriptor();
};
template<class Class, class PropType>
class PropDescriptor : public TypedPropertyDescriptor<PropType> {
    typedef typename TypedPropertyDescriptor<PropType>::GetSet GetSet;
    template<typename GetFunc, typename SetFunc>
    static std::auto_ptr<GetSet> getset(GetFunc getFunc, SetFunc setFunc);
public:
    template<typename GetFunc, typename SetFunc>
    PropDescriptor(const char* name, const char* category, GetFunc getFunc, SetFunc setFunc, PropertyDescriptor::Functionality flags, int security)
        : TypedPropertyDescriptor<PropType>(Class::classDescriptor(), name, category, getset(getFunc, setFunc), flags, security)
    {
        ASSERT_(Class::classType()==typeid(Class), "Class::classType()==typeid(Class)", 0xae, "174")
    }
    virtual ~PropDescriptor();
};
}
class B1 { public: int x; };
class B2 { public: int y; };
class GuiBase : public B1, public B2 {
public:
    static const std::type_info& classType() { return typeid(GuiBase); }
    static Reflection::ClassDescriptor& classDescriptor();
    int get() const;
};
}
template RBX::Reflection::PropDescriptor<RBX::GuiBase, int>::PropDescriptor(const char*, const char*, int (RBX::GuiBase::*)() const, int, RBX::Reflection::PropertyDescriptor::Functionality, int);