// Rebuild glue: Humanoid statics and overrides rbxgs declares (humanoid/Humanoid.h) but never defines.
// Names are the 2008-06 Roblox.exe strings after "Strafe": "Health" (category "Game"), "MaxHealth",
// "Died", "Running" (speed), "Jumping" (active), "GettingUp", "FallingDown", "Seated".
// Behavioural reconstruction (overhead name and health bar for other players), not byte-verified.
#include "humanoid/Humanoid.h"
#include "v8datamodel/PartInstance.h"
#include <G3D/GCamera.h>
#include <G3D/Rect2D.h>

namespace RBX
{
	Reflection::BoundProp<float, 1> Humanoid::propHealth("Health", "Game", &Humanoid::health, Reflection::PropertyDescriptor::STANDARD);
	Reflection::SignalDesc<Humanoid, void(void)> Humanoid::event_Died("Died");

	// through the property so Changed fires and onChangedHealth sees it
	void Humanoid::setHealth(float value)
	{
		propHealth.setValue(this, value);
	}

	Reflection::SignalDesc<Humanoid, void(float)> Humanoid::event_Running("Running", "speed");
	Reflection::SignalDesc<Humanoid, void(bool)> Humanoid::event_Jumping("Jumping", "active");
	Reflection::SignalDesc<Humanoid, void(bool)> Humanoid::event_GettingUp("GettingUp", "active");
	Reflection::SignalDesc<Humanoid, void(bool)> Humanoid::event_FallingDown("FallingDown", "active");
	Reflection::SignalDesc<Humanoid, void(bool)> Humanoid::event_Seated("Seated", "active");

	bool Humanoid::askSetParent(const Instance* instance) const
	{
		return true;
	}

	bool Humanoid::isControllable() const
	{
		return !imDead;
	}

	bool Humanoid::shouldRender2d() const
	{
		return true;
	}

	bool Humanoid::shouldRender3dAdorn() const
	{
		return true;
	}

	// the character's name with a health bar under it, above the head
	void Humanoid::renderMultiplayer(Adorn* adorn, const G3D::GCamera& camera)
	{
		PartInstance* head = getHead();
		if (!head || !getParent())
			return;

		G3D::Vector3 above = head->getCoordinateFrame().translation + G3D::Vector3(0.0f, 1.5f, 0.0f);
		G3D::Vector3 screen = camera.project(above, adorn->getViewport());
		if (screen == G3D::Vector3::inf())
			return;

		G3D::Vector2 at(screen.x, screen.y);
		adorn->drawFont2D(getParent()->getName(), at, 12.0, G3D::Color4(1, 1, 1, 1), G3D::Color4(0, 0, 0, 1),
						  Adorn::XALIGN_CENTER, Adorn::YALIGN_BOTTOM, Adorn::PROPORTIONAL_SPACING);

		const float width = 40.0f, height = 4.0f;
		float fraction = G3D::clamp(relativeHealth(), 0.0f, 1.0f);
		adorn->rect2d(G3D::Rect2D::xywh(at.x - width / 2, at.y + 2, width, height), G3D::Color4(1, 0, 0, 1));
		adorn->rect2d(G3D::Rect2D::xywh(at.x - width / 2, at.y + 2, width * fraction, height), G3D::Color4(0, 1, 0, 1));
	}
}
