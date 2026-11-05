// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_3b63cd3bc5332e20.cpp

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
namespace RBX { struct ExePad8 { virtual void exePadV(); char exePad[0x2c]; }; }
#include "v8datamodel/Tool.h"
namespace RBX
{
	void Tool::setGripUp(const G3D::Vector3& v)
	{
		G3D::CoordinateFrame c = grip;
		G3D::Vector3 col0 = c.rotation.getColumn(0);
		G3D::Vector3 oldZ = c.rotation.getColumn(2);

		G3D::Vector3 y = v.direction();
		G3D::Vector3 yc = y;
		G3D::Vector3 oldX = col0;

		G3D::Vector3 z = oldX.cross(yc);
		z.unitize();

		
		G3D::Vector3 yy = y;
		G3D::Vector3 zc = z;
		G3D::Vector3 x = yy.cross(zc);
		x.unitize();
		
		c.rotation.setColumn(0, x);
		c.rotation.setColumn(1, y);
		c.rotation.setColumn(2, z);

		setGrip(c);
	}
}
