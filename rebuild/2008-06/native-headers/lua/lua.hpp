#pragma once
#include "lua.h"

namespace RBX
{
    namespace Lua
    {
        class ScopedPopper 
        {
        private:
            int popCount;
            lua_State* thread;
        
        public:
            ScopedPopper(lua_State* thread, int popCount)
                : popCount(popCount),
                  thread(thread)
            {
            }
            ScopedPopper& operator+=(int);
            ScopedPopper& operator-=(int);
            ~ScopedPopper()
            {
                lua_pop(thread, popCount);
            }
        };
    }
}
// 2008-06 native header port of rbxgs App/include/lua/lua.hpp (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
