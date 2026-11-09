// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_b6bbefe7dee2c832.cpp

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
#include "v8datamodel/Hopper.h"
#include "util/IRenderable.h"
#include "v8datamodel/IEquipable.h"
#include "v8datamodel/Accoutrement.h"
namespace RBX
{
	class ExeChildSignal
	{
	public:
		boost::signals::connection connect(Reflection::SignalSource* source, const boost::slot<boost::function<void(boost::shared_ptr<Instance>)> >& slot, int priority);
	};

	void Accoutrement::upTo_InCharacter()
	{
		characterChildAdded = reinterpret_cast<ExeChildSignal&>(Instance::event_childAdded).connect(getParent(), boost::bind(&Accoutrement::onEvent_AddedBackend, this, _1), 10);
		characterChildRemoved = reinterpret_cast<ExeChildSignal&>(Instance::event_childRemoved).connect(getParent(), boost::bind(&Accoutrement::onEvent_RemovedBackend, this, _1), 10);
	}
}
