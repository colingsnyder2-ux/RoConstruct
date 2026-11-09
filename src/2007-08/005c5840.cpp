// from server: 72% by tajop
struct lua_State;
void lua_settop(lua_State* L, int idx);

namespace std {
class exception {
public:
    exception();
    virtual ~exception();
    virtual const char* what() const;
private:
    const char* _m_what;
    int _m_doFree;
};
}

struct LuaGuard {
    int a;
    int b;
    int active;
};

class lua_exception : public std::exception {
public:
    virtual ~lua_exception();
    lua_State* L;
    LuaGuard* guard;
    bool handled;
};

lua_exception::~lua_exception()
{
    if (!handled) {
        guard->active = 0;
        lua_settop(L, -2);
    }
}
