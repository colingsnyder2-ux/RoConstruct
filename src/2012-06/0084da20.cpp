// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct lua_State;
extern "C" {
void* lua_touserdata(lua_State* L, int idx);
int lua_getmetatable(lua_State* L, int idx);
void lua_getfield(lua_State* L, int idx, const char* k);
int lua_rawequal(lua_State* L, int a, int b);
void lua_settop(lua_State* L, int idx);
}
namespace RBX {
namespace Reflection {
class Type {
public:
    template<class T> static const Type& singleton();
};
struct Storage {
    template<class T> void assign(const T& v);
};
class Variant {
public:
    const Type* type;
    Storage value;
    template<class T> Variant& operator=(const T& v) { type = &Type::singleton<T>(); value.assign<T>(v); return *this; }
};
}
namespace Lua {
template<class T> struct Bridge {
    static const char* className;
    static T* getPtr(lua_State* L, int idx)
    {
        void* p = lua_touserdata(L, idx);
        if (p) {
            if (lua_getmetatable(L, idx)) {
                lua_getfield(L, -10000, className);
                if (lua_rawequal(L, -1, -2)) {
                    lua_settop(L, -3);
                    return (T*)p;
                }
                lua_settop(L, -3);
            }
        }
        return 0;
    }
};
class A;
template<class T> bool getValue(lua_State* L, int idx, Reflection::Variant& value)
{
    void* p = lua_touserdata(L, idx);
    if (p) {
        if (lua_getmetatable(L, idx)) {
            lua_getfield(L, -10000, Bridge<T>::className);
            if (lua_rawequal(L, -1, -2)) {
                lua_settop(L, -3);
                value = *(T*)p;
                return true;
            }
            lua_settop(L, -3);
        }
    }
    return false;
}
template bool getValue<A>(lua_State*, int, Reflection::Variant&);
}}

