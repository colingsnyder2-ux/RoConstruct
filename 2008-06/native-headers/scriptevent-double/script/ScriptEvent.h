#pragma once
// Include profile (/I{headers}/scriptevent-double): the donor tools/rbxgs script/ScriptEvent.h with the 2008-06 double
// delays. Evidence (see LuaBridge2008/LuaYieldingThreads2008.h): WaitingThread is 0x18 bytes with double
// requestedDelay +8 / elapsedTime +0x10 (fld/fstp qword copies in 00620990), WaitingThread(lua_State*, double)
// 00620cd0, and queueWaiter(lua_State*, double) 006214e0 receives the lua_Number of ScriptContext::wait 005a9260 /
// delay 005a9140 as a qword (fstp qword ptr [esp]). Everything else is the donor declaration unchanged.
#include "script/ScriptContext.h"
#include "script/ThreadRef.h"
#include "util/RunStateOwner.h"
#include "lua.h"

namespace RBX
{
    class ScriptContext;

    namespace Lua
    {
        class YieldingThreads
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
            YieldingThreads(ScriptContext* context);
            void queueWaiter(lua_State* L, double delay);
            void queueWaiter(lua_State* L);
            void resume(Heartbeat heartbeat);
  
        private:
            void clearAllSinks();
        };
    }
}
