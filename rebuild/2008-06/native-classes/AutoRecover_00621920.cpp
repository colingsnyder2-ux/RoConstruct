// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <exception>

// INFERRED: minimal local view of lua_State; only errorJmp at +0x70 is used.
struct lua_longjmp;
struct lua_State {
    char pad[0x70];
    struct lua_longjmp *errorJmp;
};

typedef void (*Pfunc)(lua_State *L, void *ud);

struct lua_longjmp {
    struct lua_longjmp *previous;
    int b;                  // luai_jmpbuf dummy (C++ build)
    volatile int status;
};

// INFERRED: exception type thrown by the Lua error path; byte flag at +0x14.
struct lua_exception {
    char pad[0x14];
    bool handled;
};

extern "C" void luaG_runerror(lua_State *L, const char *fmt, ...);

// INFERRED: luaD_rawrunprotected with a C++ try/catch wrapper.
extern "C" int fn_00621920(lua_State *L, Pfunc f, void *ud)
{
    struct lua_longjmp lj;
    lj.status = 0;
    lj.previous = L->errorJmp;
    L->errorJmp = &lj;
    try {
        (*f)(L, ud);
    }
    catch (lua_exception &e) {
        e.handled = true;
        if (lj.status == 0) lj.status = -1;
    }
    catch (std::exception &e) {
        try {
            luaG_runerror(L, e.what());
        }
        catch (lua_exception &e2) {
            e2.handled = true;
            if (lj.status == 0) lj.status = -1;
        }
    }
    L->errorJmp = lj.previous;
    return lj.status;
}
