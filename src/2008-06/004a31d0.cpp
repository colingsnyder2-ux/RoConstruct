// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_6abdbefd3adf2a5b.cpp

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
#undef Guid
#undef AbstractFactoryProduct
#include "script/Script.h"
#include <set>
namespace RBX { namespace Network {
class ClientProxyX
{
public:
	char pad[0x164];
	std::set<std::string> scripts;
	void onScript(boost::shared_ptr<Instance> instance);
};
void ClientProxyX::onScript(boost::shared_ptr<Instance> instance)
{
	if (Script* script = dynamic_cast<Script*>(instance.get()))
	{
		if (script->getScriptId().isNull())
			scripts.insert(script->getEmbeddedCode());
		else
			scripts.insert(script->getScriptId().toString());
	}
}
} }
