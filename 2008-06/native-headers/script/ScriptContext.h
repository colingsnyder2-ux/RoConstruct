#pragma once
// onHook is declared below: enables the guarded onHook/scriptHook bodies of the ScriptContext units.
#define SCRIPTCONTEXT_HEADER_DECLARES_ONHOOK
#include "script/Script.h"
#include "script/ScriptEvent.h"
#include "script/LuaMemory.h"
#include "script/ThreadRef.h"
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "v8datamodel/Stats.h"
#include "util/Events.h"
#include "util/RunStateOwner.h"
#include "security/SecurityContext.h"
#include "boost/shared_ptr.hpp"
#include "boost/date_time.hpp"
#include <set>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/thread.hpp>
#include "lua.h"

// TODO: where do these numbers actually come from? i don't think
// they were actually defined like this
#define RBX_LUA_GLOBAL_SCRIPTCONTEXT (void*)0x43 // 'C'
#define RBX_LUA_GLOBAL_THREADREFNODE (void*)0x4E // 'N'
#define RBX_LUA_GLOBAL_IDENTITY (void*)0x54 // 'T'

namespace RBX
{
    class Script;

    namespace Lua
    {
        class YieldingThreads;
        // INFERRED: 0061c790 RBX::Lua::LuaArguments — lua_tolstring(thread, index, 0); on NULL falls back to
        // the char* global at 0x95b1cc (called once by resume 005aeb80 in the error path)
        const char* LuaArguments(lua_State* thread, int index);
    }

    extern char sScriptContext[];
    class ScriptContext : public DescribedCreatable<ScriptContext, Instance, sScriptContext>,
                          public Service,
                          public Listener<RunService, RunTransition>,
                          public Listener<RunService, Heartbeat>
    {
    public:
        typedef boost::function1<size_t, lua_State*> PushArgumentsClosure;
        typedef boost::function2<void, lua_State*, size_t> ReadResultsClosure;

    public:
        enum Result
        {
            Success,
            Yield,
            Error
        };

    public:
        class ScriptImpersonator : public Security::Impersonator
        {
        public:
            ScriptImpersonator(lua_State* thread);
        };

    private:
        lua_State* globalState;
        Lua::ThreadRef commandLineSandbox;
        std::set<Script*> scripts;
        boost::posix_time::ptime nextPendingScripts;
        std::vector<boost::shared_ptr<Script>> pendingScripts;
        boost::shared_ptr<RunService> runService;
        boost::scoped_ptr<Lua::YieldingThreads> yieldEvent;
        bool scriptsDisabled;
        boost::shared_ptr<Stats::Item> statsItem;
        // Provisional member types; 005ae490/005ae730 establish offsets, not full ABI.
        double exeTime0;
        double exeTime1;
        int exeState;
        boost::scoped_ptr<boost::thread> exeThread;
        boost::mutex exeMutex;
        boost::condition exeCondition;
    
    public:
        boost::scoped_ptr<LuaAllocator> allocator;
        static Reflection::BoundProp<bool, true> propScriptsDisabled;
    
    public:
        ScriptContext();
        virtual ~ScriptContext();

        std::auto_ptr<Reflection::ValueCollection> call(const Lua::FunctionRef&, const Reflection::ValueCollection&);
        void call(const Lua::FunctionRef&);
        void call(const Lua::FunctionRef&, PushArgumentsClosure, ReadResultsClosure);
        std::auto_ptr<Reflection::ValueCollection> executeInNewThread(Security::Identities, const char*, const char*, const Reflection::ValueCollection&);
        void executeInNewThread(Security::Identities, const char*, const char*);
        void executeInNewThread(Security::Identities, const char*, const char*, PushArgumentsClosure pushArguments, ReadResultsClosure readResults);
        Result resume(lua_State* thread, int narg);
        void resume(lua_State* thread, PushArgumentsClosure pushArguments, ReadResultsClosure readResults);
        __declspec(noinline) void gc()
        {
            if (globalState)
                lua_gc(globalState, LUA_GCCOLLECT, 0);
        }
        size_t getThreadCount() const;
        bool hasState() const;
        lua_State* state();
        virtual XmlElement* write();
    
    protected:
        virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
        virtual void onEvent(const RunService* source, Heartbeat event);
        virtual void onEvent(const RunService* source, RunTransition event);
      
    private:
        void onChangedScriptEnabled(const Reflection::PropertyDescriptor&);
        // INFERRED name: 005adbf0 (112 B, ret 8), called by the static lua_Hook scriptHook 005ae230 on getContext(L)
        // while the timed-out counter 00976b78 is > 0; throws "Game script timout" for GameScript identity.
        void onHook(lua_State* L, lua_Debug* ar);
        // INFERRED name: 005ab4b0 (528 B), the "ScriptContext Timeout" watchdog thread body bound by setTimeout
        // 005ae8f0 (mov edi,0x5ab4b0; boost::bind(&ScriptContext::<mf0>, shared_ptr<ScriptContext>)).
        void watchdog();

    public:
        // INFERRED name: 005ae8f0 (506 B), the reflected function "SetTimeout"("seconds") (BoundFuncDesc<ScriptContext,
        // void(double), 1> 00976b98 built by the static initializer 007f4f80).
        void setTimeout(double seconds);
      
    public:
        void closeState();
        void addScript(Script* script);
        void removeScript(Script* script);
      
    private:
        void disassociateState(Script* script);
        void openState();
        void startScript(boost::shared_ptr<Script> script);
        void startPendingScripts();
    
    public: 
        static ScriptContext& getContext(lua_State* thread);

    private:
        static void sandboxThread(lua_State* thread);
        static void setThreadIdentity(lua_State* thread, Security::Identities identity);
        static Security::Identities getThreadIdentity(lua_State* thread)
        {
            lua_pushlightuserdata(thread, RBX_LUA_GLOBAL_IDENTITY);
            lua_gettable(thread, LUA_GLOBALSINDEX);
        
            if (!lua_isnumber(thread, -1))
            {
                return Security::Anonymous;
            }
            else
            {
                int identity = lua_tointeger(thread, -1);
                lua_pop(thread, 1);
                return static_cast<Security::Identities>(identity);
            }
        }
        static int print(lua_State* L);
        static int tick(lua_State* L);
        static int wait(lua_State* thread);
        static int delay(lua_State* thread);
        static int trustedThread(lua_State* thread);
        static void scriptHook(lua_State* L, lua_Debug* ar); // INFERRED: 005ae230 (71 B) lua_Hook passed to lua_sethook(count 1000) by openState 005aefa0
        static int time(lua_State* L);          // INFERRED: 005a92d0 registered as global 'time' by openState 005aefa0 (name from the global)
        static int printidentity(lua_State* L); // INFERRED: 005add30 registered as global 'printidentity' by openState 005aefa0
        static int loadfile(lua_State* L);
        static int dofile(lua_State* L);
        static int settings(lua_State* thread);
        static int stats(lua_State* L);
        static int statsitemvalue(lua_State*);
        static int onError(lua_State*);
        static void reportError(lua_State* thread);
    };
    // INFERRED: 005a8720 (39 B) registered as global 'version' by ScriptContext::openState 005aefa0
    int getVersion(lua_State* L);
}
