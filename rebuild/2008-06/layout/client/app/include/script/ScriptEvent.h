// =============================================================================
// ScriptEvent.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/script/ScriptEvent.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
