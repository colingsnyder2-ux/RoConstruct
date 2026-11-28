// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>
#include <ctype.h>
#include <boost/shared_ptr.hpp>
#include "LuaBridge2008/LuaSignalBridge2008.h"
#include "LuaBridge2008/LuaEnumBridge2008.h"
#include "LuaBridge2008/LuaArguments2008.h"
#include "v8tree/Instance.h"

using namespace RBX;
using namespace RBX::Reflection;
using namespace RBX::Lua;

// INFERRED: local declaration of G3D::format to avoid depending on an unknown header path
namespace G3D {
    std::string format(const char* fmt, ...);
}

// INFERRED: unknown callees, declared with the fixed fn_ convention
extern "C" int fn_006124f0(int a1, int a2);
extern "C" int fn_00611e00(int a1, int a2);
extern "C" int fn_00612350(int a1, int a2, int a3);
extern "C" int fn_00611dd0(int a1, int a2);
extern "C" int fn_00612680(int a1, int a2);
extern "C" int __fastcall fn_0056bd10(void* self, int unusedEdx, int a1);
extern "C" const RBX::Name* fn_00554180(const std::string* s);
extern "C" int fn_0061c0e0(lua_State* L);

// INFERRED: raw reflection iterator / property layouts (headers not visible)
struct RawIter3 { void* a; void* b; void* c; };
struct RawPair  { void* a; void* b; };
struct RawProp  { int a; int b; };
struct SignalHolder98 { int a; int b; };

// INFERRED: reflection helper functions declared with fn_ convention
extern "C" RawPair* __fastcall fn_0061ba10(void* container, int unusedEdx, RawIter3* out, const Name* n);
extern "C" int* __fastcall fn_004174b0(void* it, int unusedEdx, void* out);
extern "C" RawIter3* __fastcall fn_0061bb30(void* self, int unusedEdx, RawIter3* out, const Name* n);
extern "C" RawIter3* __fastcall fn_0061bb00(void* self, int unusedEdx, RawIter3* out);
// INFERRED: pushLuaValue is a static function in another TU
extern "C" void fn_0061abe0(RawProp p, lua_State* L);

typedef void* (__thiscall *GetDescriptorFn)(void*);

// INFERRED: ObjectBridge::on_index is not declared in visible headers; using fixed fn_ naming
extern "C" int fn_0061c2c0(const boost::shared_ptr<DescribedBase>& object, const char* name, lua_State* L)
{
    if (!object.get())
        throw std::runtime_error(std::string("The object has been deleted"));

    const Name& n = Name::lookup(name);
    char* obj = (char*)object.get();

    // instance properties
    {
        char* desc = *(char**)(obj + 8);
        void* end = *(void**)(desc + 0x18);
        RawIter3 tmp;
        RawPair* r = fn_0061ba10(desc + 8, 0, &tmp, &n);
        RawIter3 it;
        it.a = obj;
        it.b = r->a;
        it.c = r->b;
        if (it.c != end)
        {
            RawIter3 tmp2;
            int* v = fn_004174b0(&it, 0, &tmp2);
            RawProp p;
            p.a = v[0];
            p.b = v[1];
            fn_0061abe0(p, L);
            return 1;
        }
    }

    // class-level (static) properties
    {
        char* desc = *(char**)(obj + 8);
        void* end = *(void**)(desc + 0x80);
        RawIter3 tmp;
        RawPair* r = fn_0061ba10(desc + 0x70, 0, &tmp, &n);
        RawIter3 it;
        it.a = obj;
        it.b = r->a;
        it.c = r->b;
        if (it.c != end)
        {
            RawIter3 tmp2;
            int* v = fn_004174b0(&it, 0, &tmp2);
            void* key = (void*)v[0];
            lua_pushlightuserdata(L, key);
            fn_006124f0((int)L, -10001);
            if (fn_00611e00((int)L, -1))
                return 1;
            lua_settop(L, -2);
            lua_pushlightuserdata(L, key);
            fn_00612350((int)L, (int)&fn_0061c0e0, 1);
            lua_pushlightuserdata(L, key);
            fn_00611dd0((int)L, -2);
            fn_00612680((int)L, -10001);
            return 1;
        }
    }

    // signals
    {
        RawIter3 it;
        RawIter3 e;
        fn_0061bb30(obj, 0, &it, &n);
        fn_0061bb00(obj, 0, &e);
        if (it.c != e.c)
        {
            RawIter3 tmp2;
            int* v = fn_004174b0(&it, 0, &tmp2);
            int copy[2];
            copy[0] = v[0];
            copy[1] = v[1];
            SignalHolder98 h;
            fn_0056bd10(&h, 0, (int)copy);
            SharedPtrBridge<DescribedBase>::push(L, *(boost::shared_ptr<DescribedBase>*)&h);
            return 1;
        }
    }

    // children
    Instance* instance = dynamic_cast<Instance*>(object.get());
    if (instance)
    {
        Instance* child = instance->findFirstChildByName(std::string(name));
        if (child)
        {
            // INFERRED: original instantiates shared_from<PartInstance> (identical code)
            boost::shared_ptr<DescribedBase> p(shared_from<Instance>(child));
            SharedPtrBridge<DescribedBase>::push(L, p);
            return 1;
        }
    }

    if (&Name::getNullName() == &n)
    {
        std::string s(name);
        s[0] = (char)toupper(name[0]);
        if (s[0] != name[0] && !fn_00554180(&s)->empty())
        {
            return fn_0061c2c0(object, s.c_str(), L);
        }
    }

    // INFERRED: class name lookup through virtual getDescriptor on Instance sub-object
    void* sub = (char*)instance + 0x10;
    GetDescriptorFn f = *(GetDescriptorFn*)(*(char**)sub + 4);
    void* r = f(sub);
    std::string* cname = (std::string*)((char*)r + 8);
    throw std::runtime_error(
        G3D::format("%s is not a valid member of %s", name, cname->c_str()));
}
