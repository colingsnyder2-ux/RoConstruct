// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_15596c7eee2d8aca.cpp

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
#include "v8datamodel/JointsService.h"
#include "v8datamodel/JointInstance.h"
#include "v8world/Joint.h"
namespace RBX
{
	void JointsService::onEvent(const World* source, AutoJoin event)
	{
		Joint* joint = event.joint;
		boost::shared_ptr<JointInstance> ji;
		
		switch (joint->getJointType())
		{
		case Joint::SNAP_JOINT:
			ji = Creatable::create<Snap>(joint);
			break;
		case Joint::WELD_JOINT:
			ji = Creatable::create<Weld>(joint);
			break;
		case Joint::GLUE_JOINT:
			ji = Creatable::create<Glue>(joint);
			break;
		case Joint::ROTATE_JOINT:
			ji = Creatable::create<Rotate>(joint);
			break;
		case Joint::ROTATE_P_JOINT:
			ji = Creatable::create<RotateP>(joint);
			break;
		case Joint::ROTATE_V_JOINT:
			ji = Creatable::create<RotateV>(joint);
			break;
		}
		ji->setParent(this);
	}
}
