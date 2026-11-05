// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_b6952b05a547a859.cpp

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
#define SurfacesNeedAdorn SurfacesNeedAdorn; char exePartPad[0x118]
#include "v8datamodel/PartInstance.h"
#undef SurfacesNeedAdorn
namespace RBX { struct ExePad8 { virtual void exePadV(); char exePad[0x2c]; }; }
#include "v8datamodel/Tool.h"
#include "humanoid/Humanoid.h"
namespace RBX
{
	class ExeChildSignal
	{
	public:
		boost::signals::connection connect(Reflection::SignalSource* source, const boost::slot<boost::function<void(boost::shared_ptr<Instance>)> >& slot, int priority);
	};

	void Tool::upTo_InCharacter()
	{
		characterChildAdded = reinterpret_cast<ExeChildSignal&>(Instance::event_childAdded).connect(getParent(), boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
		characterChildRemoved = reinterpret_cast<ExeChildSignal&>(Instance::event_childRemoved).connect(getParent(), boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
	}
}
