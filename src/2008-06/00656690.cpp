// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_0fe2b93c580135b5.cpp

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
#include "gui/HealthHud.h"
#define relativeHealth() relativeHealth() const { return health / maxHealth; } float relativeHealthRbx()
#define DIRECTION_MOVE DIRECTION_MOVE }; int exeHumanoidPad; enum ExeHumanoidDummy { EXE_HUMANOID_DUMMY
#include "humanoid/Humanoid.h"
#undef DIRECTION_MOVE
#undef relativeHealth
#include "v8datamodel/Visit.h"
#include "util/Color.h"

namespace RBX
{
	HealthHud::HealthHud()
	{
		setGuiSize(G3D::Vector2(10.0f, 100.0f));
	}

	void HealthHud::render2d(Adorn* adorn)
	{
		G3D::Rect2D viewport = adorn->getViewport();
		G3D::Vector2 size = G3D::Vector2(0.1f, 1.0f) * (viewport.height() * 0.125f);
		setGuiSize(size);

		int textSize = (int)(size.y * 0.18f);

		if (!visit)
			visit = RBX::shared_from(ServiceProvider::find<Visit>(this));

		if (visit)
		{
			if (Humanoid* humanoid = Humanoid::getLocalHumanoidFromContext(this))
			{

				Rect rect = getMyRect();

				Rect greenBarRect = rect;
				Rect redBarRect = rect;

				greenBarRect.low.y = rect.high.y - humanoid->relativeHealth() * rect.size().y;
				redBarRect.high.y = greenBarRect.low.y;

				adorn->rect2d(greenBarRect.toRect2D(), Color::lightGreen());
				adorn->rect2d(redBarRect.toRect2D(), G3D::Color3::red());

				adorn->drawFont2D(
					"Health",
					rect.positionPoint(Rect::CENTER, Rect::BOTTOM),
					textSize,
					G3D::Color3::blue(),
					G3D::Color4::clear(),
					Adorn::XALIGN_CENTER,
					Adorn::YALIGN_TOP,
					Adorn::PROPORTIONAL_SPACING
				);
			}
		}
	}
}
