// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_2f907b0c71fe1b5c.cpp

// Candidate translation unit (score above; library headers required).
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
#define AbstractFactoryProduct GuidItem<Instance>, public AbstractFactoryProduct
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
#include "v8tree/Verb.h"
#include "script/Script.h"
#include "v8world/IMoving.h"
#include "gui/GuiEvent.h"
#include "util/RunStateOwner.h"
#include "util/ContentProvider.h"
#include "util/Profiling.h"
#include "util/UIEvent.h"
#define render3dSelect(a, b) render3dSelect(a, b) { return; } void exeCheckCamera(); void exeUnusedSelect(a, b)
#include "v8datamodel/Workspace.h"
#undef render3dSelect
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Selection.h"

namespace RBX
{
	static void DrawAdorn(boost::shared_ptr<Instance> wsi, Adorn* adorn, SelectState selectState, Workspace* workspace)
	{
		if (IRenderable* ir = dynamic_cast<IRenderable*>(wsi.get()))
		{
			if (workspace->contains(wsi.get()))
			{
				ir->render3dSelect(adorn, selectState);
			}
		}
	}

	void Workspace::render3dAdorn(Adorn* adorn)
	{
		exeCheckCamera();
		viewPort = adorn->getViewport();
		ServiceClient<Selection> sel(this);

		if (sel)
			std::for_each(sel->getSelection()->begin(), sel->getSelection()->end(), boost::bind(&DrawAdorn, _1, adorn, SELECT_NORMAL, this));

		render3dAdornItems(adorn);
		if (showWorldCoord)
		{
			adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());
			adorn->axes(G3D::Color3::red(), G3D::Color3::green(), G3D::Color3::blue(), 50.0f);
		}

		if (showHashGrid)
		{
			adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());
			adorn->box(G3D::AABox(G3D::Vector3(28, 4, 12), G3D::Vector3(32, 8, 16)), G3D::Color4(1.0, 0.2, 0.2, 0.5), G3D::Color4::clear());
		}
	}
}
