// Inactive 2008-06 native recovery: the Lua yielding-thread queue (YieldingThreads unit 00620970..006217e2).
// Declarations in LuaBridge2008/LuaYieldingThreads2008.h (2008 double layout); the std::vector<WaitingThread> and
// shared_ptr<ThreadRef> instances are emitted by this unit. Counted rows are proven by
// tests/record_native_lua_bridge2008.py.
// >>> native-status (generated) -- do not edit >>>
// LuaBridge2008Yield | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 56a83c3d | roc native-status --write
#include "LuaBridge2008/LuaYieldingThreads2008.h"

namespace RBX
{
    namespace Lua
    {
        YieldingThreads2008::YieldingThreads2008(ScriptContext* context)
            : context(context)
        {
        }

        void YieldingThreads2008::queueWaiter(lua_State* L)
        {
            queueWaiter(L, 0.0);
        }

        void YieldingThreads2008::queueWaiter(lua_State* L, double delay)
        {
            RobloxExtraSpace::get(L)->yieldCaptured = true;
            waitingThreads.push_back(WaitingThread(L, delay));
        }

        void YieldingThreads2008::resume(Heartbeat heartbeat)
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

                it->elapsedTime += heartbeat.step;

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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::Lua::ThreadRef>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Lua::YieldingThreads2008::WaitingThread> >;
template class std::_Vector_const_iterator<RBX::Lua::YieldingThreads2008::WaitingThread,std::allocator<RBX::Lua::YieldingThreads2008::WaitingThread> >;
template class std::_Vector_iterator<RBX::Lua::YieldingThreads2008::WaitingThread,std::allocator<RBX::Lua::YieldingThreads2008::WaitingThread> >;
