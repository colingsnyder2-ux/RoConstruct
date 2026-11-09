// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_ae23b208edf49e74.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Object.h"
#define hasListeners() hasListeners() const { return listeners.size() > 0; } bool hasListenersEmpty()
#include "util/Events.h"
#undef hasListeners
namespace RBX { template<class T> class GuidItem { public: virtual ~GuidItem() {} char guidPad[0xc]; }; }
#define AbstractFactoryProduct GuidItem<Instance>, public AbstractFactoryProduct
#include "util/Guid.h"
namespace RBX { class GuidStub { public: typedef Guid::Data Data; void assign(const Data&) {} operator const Guid&() const { return *(const Guid*)0; } }; }
#define Guid GuidStub
#include "v8tree/Instance.h"
#undef Guid
#undef AbstractFactoryProduct
namespace RBX
{
	void Instance::onDescendentAdded(Instance* instance)
	{
		if (Notifier<Instance, DescendentAdded>::hasListeners())
			Notifier<Instance, DescendentAdded>::raise(DescendentAdded(instance, instance->getParent()));

		event_descendentAdded.fire(this, shared_from(instance));
	}
}
