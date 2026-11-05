// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_8e513eb37a095b0d.cpp

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
#include "v8datamodel/GuiBuilder.h"
#include "v8datamodel/Accoutrement.h"
namespace RBX
{
	void Accoutrement::setAttachmentForward(const G3D::Vector3& v)
	{
		G3D::CoordinateFrame c = attachmentPoint;
		G3D::Vector3 col1 = c.rotation.getColumn(1);
		G3D::Vector3 oldZ = c.rotation.getColumn(2);

		G3D::Vector3 x = v.direction();
		G3D::Vector3 xc = x;
		G3D::Vector3 oldY = col1;

		G3D::Vector3 z = xc.cross(oldY);
		z.unitize();

		G3D::Vector3 xx = x;
		G3D::Vector3 zc = z;
		G3D::Vector3 y = zc.cross(xx);
		y.unitize();
		
		c.rotation.setColumn(0, x);
		c.rotation.setColumn(1, y);
		c.rotation.setColumn(2, z);

		setAttachmentPoint(c);
	}
}
