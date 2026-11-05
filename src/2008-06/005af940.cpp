// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_scriptcontext_native_execute_a442f712664a5f94.cpp

// Candidate translation unit (score above; library headers required).
#include <script/ScriptContext.h>
#include <util/standardout.h>
#include <lua/lua.hpp>
#include <lauxlib.h>
#include <cstring>
namespace RBX { namespace Lua { const char* safe_lua_tostring(lua_State*, int); } }
using namespace RBX;
void ScriptContext::executeInNewThread(Security::Identities identity, const char* script, const char* name, PushArgumentsClosure pushArguments, ReadResultsClosure readResults)
{
    openState();

    lua_State* L;
    lua_State* newThread;

    if (identity == Security::CmdLine)
    {
        if ((*(Lua::ThreadRef*)((char*)this+0x13c)).empty())
        {
            {
                Lua::ThreadRef threadRef(lua_newthread((*(lua_State**)((char*)this+0x138))));
                (*(Lua::ThreadRef*)((char*)this+0x13c)) = threadRef;
            }

            if ((*(Lua::ThreadRef*)((char*)this+0x13c)).empty())
                throw std::runtime_error("Unable to create trusted sandbox thread");

            sandboxThread((*(Lua::ThreadRef*)((char*)this+0x13c)).thread());
            setThreadIdentity((*(Lua::ThreadRef*)((char*)this+0x13c)).thread(), Security::CmdLine);
            lua_pop((*(lua_State**)((char*)this+0x138)), 1);
        }

        L = (*(Lua::ThreadRef*)((char*)this+0x13c)).thread();
        newThread = lua_newthread(L);
    }
    else
    {
        L = (*(lua_State**)((char*)this+0x138));
        newThread = lua_newthread(L);
        sandboxThread(newThread);
        setThreadIdentity(newThread, identity);
    }

    if (!newThread)
    {
        StandardOut::singleton()->print(MESSAGE_ERROR, "ScriptContext::execute: Unable to create a new thread");
        throw std::runtime_error("Unable to create a new thread");
    }

    Lua::ScopedPopper popper(L, 1);

    std::string sName("=");

    if (name)
        sName += name;
    else
        sName += "Script";

    if (luaL_loadbuffer(newThread, script, strlen(script), sName.c_str()))
    {
        std::string err = Lua::safe_lua_tostring(newThread, -1);
        lua_pop(newThread, 1);

        StandardOut::singleton()->print(MESSAGE_ERROR, err.c_str());
        throw std::runtime_error(err);
    }

    resume(newThread, pushArguments, readResults);
}

