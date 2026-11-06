#pragma once
// 2008-06 Lua signal bridge (SignalBridge, SignalConnectionBridge, FunctionScriptSlot, WaitScriptSlot), inactive.
// Range 0061f180..00620a60 inside the bridge range documented in LuaBridge2008.h. These declarations replace the
// read-only donor script/LuaSignalBridge.h for this recovery (that header is no longer included here; nothing is
// declared at the donor path): the bridge classes and the two on_tostring specializations are the donor shapes, bound to
// 2008-06 by byte-exact bodies with verified targets; FunctionScriptSlot carries the 2008 layout below.
//   FunctionScriptSlot: ~FunctionScriptSlot 0061f2c0; WaitScriptSlot: ctor 00620190, copy ctor 0061f410, dtor 0061f350;
//   TGenericSlotWrapper<WaitScriptSlot>/<FunctionScriptSlot> vtables compared slot by slot (RTTI names).
#include "LuaBridge2008/LuaBridge2008.h"
#include "script/Script.h"
#include "script/ScriptContext.h"
#include "script/ThreadRef.h"
#include "reflection/reflection.h"
#include "boost/signals.hpp"

namespace RBX
{
    namespace Lua
    {
        template<>
        int SharedPtrBridge<Reflection::SignalInstance>::on_tostring(const boost::shared_ptr<Reflection::SignalInstance>& object, lua_State* L)
        {
            std::string name = "Signal ";
            name += object->descriptor.name.name;
            lua_pushstring(L, name.c_str());
            return 1;
        }

        class SignalBridge : public SharedPtrBridge<Reflection::SignalInstance>
        {
        public:
            static int connect(lua_State* L);
            static int wait(lua_State* L);
        };

        class SignalConnectionBridge : public Bridge<boost::signals::connection, true>
        {
            friend class Bridge<boost::signals::connection, true>;

        private:
            static int disconnect(lua_State* L);
        };

        template<>
        int SignalConnectionBridge::on_tostring(const boost::signals::connection& object, lua_State* L)
        {
            lua_pushstring(L, "Connection");
            return 1;
        }

        // Saves an int and assigns a new value on construction, writes the saved value back on destruction.
        // FunctionScriptSlot::operator() 0061ff70 keeps one on the stack ({&callDepth, old value}, EH state 0): it stores
        // old+1 into +0x50 before the depth test, and every exit path stores the saved value back (00620013 / 0062003e /
        // 0062017d). The 2008 name of this helper is not in the image (it is fully inlined).
        class ScopedAssign2008
        {
            int& value;
            int saved;
        public:
            ScopedAssign2008(int& v, int newValue) : value(v), saved(v) { value = newValue; }
            ~ScopedAssign2008() { value = saved; }
        };
    }
}

// 2008-06 layout (constructor 0061fea0, copy constructor 0061f960, destructor 0061f2c0):
//   +0x00 Script::Slot (shared_ptr<connection> cnction, 8 bytes)   +0x08 ScriptContext& context (getContext 005a86e0)
//   +0x0c FunctionRef function (FunctionRef ctor 00594400; copy 005944e0)
//   +0x30 ThreadRef cachedSlotThread (vtable 0080ebc8, ThreadRef copy 00593f70)
//   +0x50 int callDepth: zeroed by the constructor (0061ff55), copied by the copy constructor (0061f9c7), and the
//         re-entrancy depth of operator() 0061ff70: it is incremented on entry, restored on exit, a call deeper than 6
//         prints "maximum event re-entrancy depth exceeded", and a re-entrant call (depth > 0 on entry) neither uses nor
//         resets the cached thread.
class FunctionScriptSlot : public RBX::Script::Slot
{
private:
    RBX::ScriptContext& context;
    RBX::Lua::FunctionRef function;
    RBX::Lua::ThreadRef cachedSlotThread;
    int callDepth;

public:
    FunctionScriptSlot(lua_State* thread, int functionIndex);
    void operator()(const RBX::Reflection::Arguments& arguments);
};

class WaitScriptSlot : public RBX::Script::Slot
{
private:
    RBX::Lua::ThreadRef waitThread;

public:
    WaitScriptSlot(lua_State* thread);
    void operator()(const RBX::Reflection::Arguments& arguments);
};
