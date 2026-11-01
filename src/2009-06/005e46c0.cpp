// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <typeinfo>
namespace boost { template<class T> class shared_ptr { T* px; void* pn; }; }
namespace RBX {
class Instance;
extern bool exeDescriptorHookFlag;
void exeDescriptorHook();
class Name {
public:
    static const Name& declare(const char* name);
    static const Name& lookup(const char* name);
};
namespace Reflection {
class Descriptor {
public:
    virtual ~Descriptor() {}
    const Name& name;
    Descriptor(const char* n) : name(Name::declare(n)) { if (exeDescriptorHookFlag) exeDescriptorHook(); }
};
class Type : public Descriptor {
public:
    const std::type_info& type;
    const Name& tag;
    bool b0;
    bool b1;
    template<class T> Type(const char* name, T* dummy);
};
template<class T> Type::Type(const char* name, T*)
    : Descriptor(name), type(typeid(T)), tag(Name::lookup(name)), b0(false), b1(false)
{
}
template Type::Type(const char*, boost::shared_ptr<Instance>*);
}
}
