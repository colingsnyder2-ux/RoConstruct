// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
#include <string>
struct lua_State;
extern "C" void lua_pushstring(lua_State* L, const char* s);
namespace RBX {
class Name { int dictionaryIndex; public: const std::string name; };
namespace Reflection {
class Descriptor { public: virtual ~Descriptor(); const Name& name; };
class SignalDescriptor : public Descriptor {};
class SignalInstance { void* source; public: const SignalDescriptor& descriptor; virtual ~SignalInstance(); };
}
}
namespace boost { template<class T> class shared_ptr { public: T* operator->() const { return px; } T* px; long* pn; }; }
namespace RBX { namespace Lua {
template<class T> struct SharedPtrBridge { static int on_tostring(const boost::shared_ptr<T>& object, lua_State* L); };
template<> int SharedPtrBridge<Reflection::SignalInstance>::on_tostring(const boost::shared_ptr<Reflection::SignalInstance>& object, lua_State* L)
{
    std::string name = "Signal ";
    name += object->descriptor.name.name;
    lua_pushstring(L, name.c_str());
    return 1;
}
}}
