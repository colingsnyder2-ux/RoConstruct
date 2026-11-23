#pragma once
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
                float requestedDelay;
                float elapsedTime;
  
            public: 
                WaitingThread(lua_State* L, float requestedDelay)
                    : thread(new ThreadRef(L)),
                      requestedDelay(requestedDelay),
                      elapsedTime(0.0f)
                {
                }
            };

        private:
            ScriptContext* context;
            std::vector<WaitingThread> waitingThreads;

        public:
            YieldingThreads(ScriptContext* context);
            void queueWaiter(lua_State* L, float delay);
            void queueWaiter(lua_State* L);
            void resume(Heartbeat heartbeat);
  
        private:
            void clearAllSinks();
        };
    }
}
// 2008-06 native header port of rbxgs App/include/script/ScriptEvent.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
