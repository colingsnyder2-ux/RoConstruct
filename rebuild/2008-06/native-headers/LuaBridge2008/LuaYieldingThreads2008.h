#pragma once
// >>> native-status (generated) -- do not edit >>>
// LuaYieldingThreads2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 22b13a52 | roc native-status --write
// 2008-06 Lua yielding-thread queue (the YieldingThreads / ScriptEvent unit 00620970..006217e2), inactive.
// The read-only donor script/ScriptEvent.h (reached through native script/ScriptContext.h) declares
// RBX::Lua::YieldingThreads with float delays; the 2008-06 bytes prove double fields and a double queueWaiter
// argument, so this recovery declares the 2008 shape under the non-colliding name YieldingThreads2008 (a codegen
// analog of RBX::Lua::YieldingThreads; nothing is declared at a donor path). Evidence:
//   YieldingThreads(ScriptContext*) 00621330: context at +0, std::vector<WaitingThread> at +4 (its _Myfirst..._Myend
//     at +0x10..+0x18, allocator at +0xc);
//   WaitingThread is 0x18 bytes (vector stride: imul 0x2aaaaaab / sar 2 in push_back 00621440, erase 00620e80, ...):
//     shared_ptr<ThreadRef> thread +0 (+4 count), double requestedDelay +8, double elapsedTime +0x10
//     (fld/fstp qword copies in the WaitingThread copy 00620990 and the copy loops 00620a80 / 00620b10 / 00620ba0);
//   WaitingThread(lua_State*, double) 00620cd0: new ThreadRef (0x20, ThreadRef(lua_State*) 00593e40),
//     requestedDelay = fld qword [esp+0x30], elapsedTime = fldz;
//   queueWaiter(lua_State*, double) 006214e0: RobloxExtraSpace::get(L)->yieldCaptured (L-0xc, +8) = true, then
//     push_back(WaitingThread(L, delay)); queueWaiter(lua_State*) 006217d0 passes fldz as a qword;
//   resume(Heartbeat) 00621590: elapsedTime += heartbeat.step (fld dword [ebp+0xc]); a thread still waiting is pushed
//     back; otherwise lua_pushnumber(elapsedTime), lua_pushnumber(heartbeat.time) and ScriptContext::resume(L, 2).
#include "lua.h"
#include "script/ScriptContext.h"
#include "script/ThreadRef.h"
#include "util/RunStateOwner.h"
#include "boost/shared_ptr.hpp"
#include <vector>

namespace RBX
{
    class ScriptContext;

    namespace Lua
    {
        class YieldingThreads2008
        {
        private:
            struct WaitingThread
            {
            public:
                boost::shared_ptr<ThreadRef> thread;
                double requestedDelay;
                double elapsedTime;

            public:
                WaitingThread(lua_State* L, double requestedDelay)
                    : thread(new ThreadRef(L)),
                      requestedDelay(requestedDelay),
                      elapsedTime(0.0)
                {
                }
            };

        private:
            ScriptContext* context;
            std::vector<WaitingThread> waitingThreads;

        public:
            YieldingThreads2008(ScriptContext* context);
            void queueWaiter(lua_State* L, double delay);
            void queueWaiter(lua_State* L);
            void resume(Heartbeat heartbeat);
        };
    }
}
