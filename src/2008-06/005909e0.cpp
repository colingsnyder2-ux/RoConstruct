// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_4426afc6723b9299.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#undef _DEBUG
#define _DLL
#define lineSegment(a, b, c) lineSegment(a, b, c) = 0; virtual void exeAdornExtra()
#include "RbxGraphics/Adorn.h"
#undef lineSegment
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
#include "v8datamodel/PVInstance.h"
#define candidatePrimaryPart candidatePrimaryPart; std::vector<boost::shared_ptr<PartInstance> > exeModelVector
#include "v8datamodel/ModelInstance.h"
#undef candidatePrimaryPart
#include "v8datamodel/RootInstance.h"
#include "v8datamodel/Stats.h"
#include "tool/Dragger.h"
#include "tool/MegaDragger.h"
namespace RBX
{
	void RootInstance::moveToPoint(PVInstance* pv, G3D::Vector3 point)
	{
		if (this->contains(pv))
		{
			RBXASSERT(pv->getPrimaryPart());

			std::vector<PVInstance*> pvInstances;
			pvInstances.push_back(pv);

			G3D::Vector3 move = Dragger::toGrid(point - pv->getLocation().translation);

			MegaDragger megaDragger(pv->getPrimaryPart(), pvInstances, this);
			moveSafe(megaDragger, move, MOVE_NO_DROP);
		}
	}
}
