// from server: 100% by tajop

struct lua_State;
void lua_pushvalue(lua_State* L, int idx);
int luaL_ref(lua_State* L, int t);

struct WeakThreadRef {
    WeakThreadRef(lua_State* thread);
    virtual ~WeakThreadRef();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct WeakFunctionRef : public WeakThreadRef {
    WeakFunctionRef(lua_State* thread, int index);
    virtual ~WeakFunctionRef();
    int functionId;
};

WeakFunctionRef::WeakFunctionRef(lua_State* thread, int index)
    : WeakThreadRef(thread)
{
    lua_pushvalue(thread, index);
    functionId = luaL_ref(thread, -10000);
}
