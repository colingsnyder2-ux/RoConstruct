// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_scriptprint_fdc2d92e125ff2a0.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <string>
#include <stdexcept>
#include <cstdio>
struct LuaState;

extern "C" int __cdecl lua_gettop(LuaState*);
extern "C" void __cdecl lua_settop(LuaState*, int);
extern "C" void __cdecl lua_pushvalue(LuaState*, int);
extern "C" const char* __cdecl lua_tolstring(LuaState*, int, unsigned long*);
extern "C" void __cdecl lua_getfield(LuaState*, int, const char*);
extern "C" void __cdecl lua_call(LuaState*, int, int);

struct Output;
typedef boost::shared_ptr<Output> OutputHandle;

OutputHandle __cdecl get_output();
void __cdecl write_output(Output*, int, const char*);

int __cdecl f(LuaState* state)
{
    std::string text;
    int count = lua_gettop(state);
    lua_getfield(state, -10002, "tostring");

    for (int i = 1; i <= count; ++i)
    {
        if (i > 1)
            text += ' ';

        lua_pushvalue(state, -1);
        lua_pushvalue(state, i);
        lua_call(state, 1, 1);

        const char* value = lua_tolstring(state, -1, 0);
        if (!value)
        {
            std::string error("'tostring' must return a string to 'print'");
            throw std::runtime_error(error);
        }

        text += value;

        if (i > 1)
            fputs("\t", stdout);

        lua_settop(state, -2);
    }

    write_output(get_output().get(), 0, text.c_str());
    return 0;
}
