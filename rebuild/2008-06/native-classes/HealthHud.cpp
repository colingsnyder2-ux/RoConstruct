// 2008-06 native RBX::HealthHud unit (inactive): 00656490..00656940.
// Layout and addresses in native-headers/gui/HealthHud.h; verified by tests/record_native_widget.py.
#include "gui/HealthHud.h"
#include "v8datamodel/Visit.h"
#include "humanoid/Humanoid2008.h"
#include "util/Color.h"

namespace RBX
{
	HealthHud::HealthHud()
	{
		setGuiSize(G3D::Vector2(10.0f, 100.0f));
	}

	// 00656690
	void HealthHud::render2d(Adorn* adorn)
	{
		G3D::Rect2D viewport = adorn->getViewport();
		float height = viewport.height() * 0.125f;
		setGuiSize(G3D::Vector2(height * 0.1f, height));

		int textSize = (int)(height * 0.18f);

		if (!visit)
			visit = shared_from(ServiceProvider::find<Visit>(this));

		if (visit)
		{
			if (Humanoid* humanoid = Humanoid::getLocalHumanoidFromContext(this))
			{
				Rect rect = getMyRect();
				Rect greenBarRect = rect;
				Rect redBarRect = rect;

				greenBarRect.low.y = rect.high.y - (rect.high.y - rect.low.y) * (humanoid->getHealth() / humanoid->getMaxHealth());
				redBarRect.high.y = greenBarRect.low.y;

				adorn->rect2d(greenBarRect.toRect2D(), G3D::Color4(Color::lightGreen(), 1.0f));
				adorn->rect2d(redBarRect.toRect2D(), G3D::Color4(G3D::Color3::red(), 1.0f));

				G3D::Color4 textColor(G3D::Color3::blue(), 1.0f);
				adorn->drawFont2D("Health", rect.positionPoint(Rect::CENTER, Rect::BOTTOM), textSize, textColor,
					G3D::Color4::clear(), Adorn::XALIGN_CENTER,
					Adorn::YALIGN_TOP, Adorn::PROPORTIONAL_SPACING);
			}
		}
	}
}
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
