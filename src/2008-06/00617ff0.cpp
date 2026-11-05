// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_3a2a88493eb183e6.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
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
#include "v8datamodel/MouseCommand.h"
#define render3dAdorn(x) render3dAdorn(x); float exeDistance(const G3D::Vector3&); bool exeBlocked()
#include "tool/NullTool.h"
#undef render3dAdorn
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/UserController.h"
#include "Network/Players.h"

namespace RBX
{
	bool exeTestTarget(PartInstance* part, float distance, bool enabled);

	MouseCommand* NewNullTool::onMouseDown(const UIEvent& uiEvent)
	{
		G3D::Vector3 hitPoint;

		PartInstance* part = getPartByLocalCharacter(uiEvent, hitPoint);
		if (exeTestTarget(part, exeDistance(hitPoint), true))
			return this;

		if (part && characterCanReach(hitPoint) && !exeBlocked())
		{
			ModelInstance* character = Network::Players::findLocalCharacter(workspace);
			if (character && !character->contains(part))
			{
				if (Humanoid* humanoid = Humanoid::modelIsCharacter(character))
					humanoid->moveTo(hitPoint, part);
			}
		}

		return this;
	}
}
