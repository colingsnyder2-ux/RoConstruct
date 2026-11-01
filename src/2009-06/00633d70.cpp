// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
struct lua_State;
extern "C" void* lua_newuserdata(lua_State* L, unsigned int sz);
extern "C" void lua_getfield(lua_State* L, int idx, const char* k);
extern "C" int lua_setmetatable(lua_State* L, int objindex);
namespace G3D {
class Vector2 {
public:
    float x, y;
    Vector2(const Vector2& o) : x(o.x), y(o.y) {}
};
}
namespace RBX { namespace Lua {
class Vector2Bridge {
public:
    static const char* className;
    static void pushVector2(lua_State* L, G3D::Vector2 v);
};
template<class T>
inline void pushNew(lua_State* L, T value)
{
    new (lua_newuserdata(L, sizeof(T))) T(value);
    lua_getfield(L, -10000, Vector2Bridge::className);
    lua_setmetatable(L, -2);
}
void Vector2Bridge::pushVector2(lua_State* L, G3D::Vector2 v)
{
    pushNew(L, v);
}
}}
