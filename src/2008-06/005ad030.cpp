// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_959fc0376a92f2ed.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#undef _DEBUG
#define _DLL
#define private public
#include "util/IRenderable.h"
#undef private
#include "util/Object.h"
#define hasListeners() hasListeners() const { return listeners.size() > 0; } bool hasListenersEmpty()
#include "util/Events.h"
#undef hasListeners
namespace RBX { template<class T> class GuidItem { public: virtual ~GuidItem() {} char guidPad[0xc]; }; }
namespace RBX { template<class T> class GuidAFP : public AbstractFactoryProduct<T> { protected: virtual void onGuidChanged() {} }; }
#define AbstractFactoryProduct GuidItem<Instance>, public GuidAFP
#include "util/Guid.h"
namespace RBX { class GuidStub { public: typedef Guid::Data Data; void assign(const Data&) {} operator const Guid&() const { return *(const Guid*)0; } }; }
#define Guid GuidStub
#include "v8tree/Instance.h"
#include "script/ScriptContext.h"
#include "script/Script.h"
#include "script/LuaInstanceBridge.h"
#include "script/LuaAtomicClasses.h"
namespace RBX {
void ScriptContext::disassociateState(Script* script)
{
    Association<Instance>& assoc = script->association();

    if (assoc.contains<Lua::ThreadRef::NodePtr>())
    {
        assoc.get<Lua::ThreadRef::NodePtr>()->eraseAllRefs();
        assoc.remove<Lua::ThreadRef::NodePtr>();
    }
}

void ScriptContext::removeScript(Script* script)
{
    if (scripts.erase(script))
    {
        disassociateState(script);

        std::vector<boost::shared_ptr<Script>>::iterator it = std::find(pendingScripts.begin(), pendingScripts.end(), shared_from(script));
        if (it != pendingScripts.end())
            pendingScripts.erase(it);
    }
}
}
