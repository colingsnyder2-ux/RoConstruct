// from server: 100% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_92b894da876d899a.cpp

// Candidate translation unit (score above; library headers required).
#define Heartbeat HeartbeatHdr
#define YieldingThreads YieldingThreadsHeader
#include "script/ScriptContext.h"
#include "script/ThreadRef.h"
#include "util/RunStateOwner.h"
#include "lua.h"
#undef YieldingThreads
#undef Heartbeat
namespace RBX { class Heartbeat { public: const double time; const double step; double exeExtra[2]; Heartbeat(double t, double s) : time(t), step(s) {} }; }

namespace RBX
{
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
            };

        private:
            ScriptContext* context;
            std::vector<WaitingThread> waitingThreads;

        public:
            void resume(Heartbeat heartbeat);
        };

        void YieldingThreads::resume(Heartbeat heartbeat)
        {
            if (waitingThreads.empty())
                return;

            std::vector<WaitingThread> copy = waitingThreads;
            waitingThreads.erase(waitingThreads.begin(), waitingThreads.end());

            std::vector<WaitingThread>::iterator it = copy.begin();
            for (; it != copy.end(); it++)
            {
                if (it->thread->empty())
                    continue;

                WaitingThread& w = *it; w.elapsedTime += heartbeat.step;

                if (it->elapsedTime < it->requestedDelay)
                {
                    waitingThreads.push_back(*it);
                    continue;
                }

                lua_State* L = it->thread->thread();
                const int oldTop = lua_gettop(L);
                lua_pushnumber(L, it->elapsedTime);
                lua_pushnumber(L, heartbeat.time);
                context->resume(L, 2);
                lua_settop(L, oldTop);
            }
        }
    }
}


