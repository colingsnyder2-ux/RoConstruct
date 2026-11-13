#include "gui/HealthHud.h"

#include "humanoid/Humanoid.h"
#include "rbxgraphics/Adorn.h"
#include "util/Color.h"
#include "util/Rect.h"
#include "util/object.h"
#include "v8datamodel/Visit.h"
#include "v8tree/Service.h"

namespace RBX {

// FUNCTION: ROBLOX 0x0065f040
HealthHud::HealthHud()
{
	setGuiSize(G3D::Vector2(10, 100));
}

// FUNCTION: ROBLOX 0x0065f3b0
void HealthHud::render2d(Adorn* adorn)
{
	G3D::Rect2D viewport = adorn->getViewport();
	float height = viewport.height() * 0.125f;
	setGuiSize(G3D::Vector2(0.1f * height, height));
	int fontSize = (int) (height * 0.18f);

	if (!visit) {
		visit = shared_from(ServiceProvider::find<Visit>(this));
		if (!visit) {
			return;
		}
	}

	Humanoid* humanoid = Humanoid::getLocalHumanoidFromContext(this);
	if (humanoid == NULL) {
		return;
	}

	Rect rect = getMyRect();
	Rect healthRect = rect;
	Rect damageRect = rect;
	// PORT: 2008 relativeHealth() reads health and max health through their descriptors.
	float healthY = rect.high.y - humanoid->relativeHealth() * (rect.high.y - rect.low.y);
	healthRect.low.y = healthY;
	damageRect.high.y = healthY;

	adorn->rect2d(healthRect.toRect2D(), Color::lightGreen());
	adorn->rect2d(damageRect.toRect2D(), G3D::Color3::red());
	adorn->drawFont2D(
		"Health",
		rect.positionPoint(Rect::CENTER, Rect::BOTTOM),
		fontSize,
		G3D::Color3::blue(),
		G3D::Color4::clear(),
		Adorn::XALIGN_CENTER,
		Adorn::YALIGN_TOP,
		Adorn::PROPORTIONAL_SPACING
	);
}

} // namespace RBX
