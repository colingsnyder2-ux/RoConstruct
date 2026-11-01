// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct lua_State;
extern "C" void* luaL_checkudata(lua_State* L, int ud, const char* tname);
namespace G3D {
class Vector2 {
public:
    float x, y;
    Vector2(float _x, float _y) : x(_x), y(_y) {}
    Vector2(const Vector2& v) : x(v.x), y(v.y) {}
    Vector2 operator-(const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
};
}
using G3D::Vector2;
template<class T> class Bridge {
public:
    static const char* className;
    static void pushNewObject(lua_State* L, T value);
    static int on_sub(lua_State* L);
};
template<class T> int Bridge<T>::on_sub(lua_State* L)
{
    T* a = (T*)luaL_checkudata(L, 1, className);
    T* b = (T*)luaL_checkudata(L, 2, className);
    pushNewObject(L, *a - *b);
    return 1;
}
template int Bridge<Vector2>::on_sub(lua_State* L);
