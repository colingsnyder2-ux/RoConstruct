// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_032a4906dcd22147.cpp

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
#define candidatePrimaryPart candidatePrimaryPart; std::vector<boost::shared_ptr<PartInstance> > exeModelVector
#include "v8datamodel/ModelInstance.h"
#undef candidatePrimaryPart
namespace RBX { struct ExePad8 { virtual void exePadV(); char exePad[0x2c]; }; }
#include "v8datamodel/Tool.h"
#include "v8datamodel/JointInstance.h"
#include "humanoid/Humanoid.h"
namespace RBX
{
	void Tool::downFrom_Equipped()
	{
		ModelInstance* character = NULL;
		if (weld)
		{
			if (PartInstance* part0 = weld->getPart0())
				character = dynamic_cast<ModelInstance*>(part0->getParent());
			weld->setParent(NULL);
			weld.reset();
		}

		if (PartInstance* handle = getHandle())
		{
			handle->setCanCollide(true);
			if (Humanoid::modelIsCharacter(character))
			{
				G3D::CoordinateFrame location = character->getLocation();
				G3D::Vector3 pos = location.translation;
				pos.y += 4;
				G3D::Vector3 dest = location.lookVector() * 8 + pos;
				handle->moveToPoint(dest);
				handle->setRotationalVelocity(G3D::Vector3(1, 1, 1));
			}
		}

		onUnequipped();
	}
}
