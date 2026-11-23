// =============================================================================
// HealthHud.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/gui/HealthHud.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
