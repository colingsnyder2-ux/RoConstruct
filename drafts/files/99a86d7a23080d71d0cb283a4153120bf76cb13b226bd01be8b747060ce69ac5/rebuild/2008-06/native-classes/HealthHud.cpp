// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::HealthHud unit (inactive): 00656490..00656940.
// Layout and addresses in native-headers/gui/HealthHud.h; verified by tests/record_native_widget.py.
// >>> native-status (generated) -- do not edit >>>
// HealthHud | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by EspClaude (roc repair)
// <<< native-status | src 2ea2df9b | roc native-status --write
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

	// 00656690 (?render2d@HealthHud@RBX@@EAEXPAVAdorn@2@@Z, slot 24). Adorn::getViewport (slot 0x10); guiSize
	// (0.1f 0081e704, 1) * viewport.height() * 0.125f (008378a8); font size (int)(height * 0.18f 0084be30);
	// visit filled once from ServiceProvider::find<Visit> 00656640 / shared_from 00618a40; Humanoid lookup
	// 005d9bb0; getMyRect 00573310; health +0x1a8 / maxHealth +0x1ac; rect2d (slot 0x2c) with Color::lightGreen
	// 005d7560 and Color3::red (ICF-folded with Vector3::unitX 005148b0), alpha 1; drawFont2D (slot 0x34) of
	// "Health" (0083d884) in Color3::blue 00514910 over Color4::clear (ICF zero 007baf10), positionPoint 005ceea0.
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
