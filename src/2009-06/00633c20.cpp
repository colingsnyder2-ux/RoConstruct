// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct lua_State;
extern "C" void lua_pushstring(lua_State* L, const char* s);
namespace boost { template<class T> class shared_ptr { public: T* px; void* pn; T* get() const { return px; } T* operator->() const { return px; } }; }
namespace RBX {
class Name { public: std::string str; const std::string& toString() const { return str; } };
namespace Reflection {
class ClassDescriptor { public: virtual ~ClassDescriptor(); const Name& name; };
class DescribedBase { public: virtual ~DescribedBase(); const ClassDescriptor* descriptor; const ClassDescriptor& getDescriptor() const { return *descriptor; } };
}
class Instance : public Reflection::DescribedBase {
public:
	char pad[0x54 - 8];
	std::string name;
	const std::string& getName() const { return name; }
};
namespace Lua {
int exe_on_tostring(const boost::shared_ptr<Reflection::DescribedBase>& object, lua_State* L)
{
    Instance* instance = dynamic_cast<Instance*>(object.get());

    if (instance)
        lua_pushstring(L, instance->getName().c_str());
    else
        lua_pushstring(L, object->getDescriptor().name.toString().c_str());

    return 1;
}
} }
