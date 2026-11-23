// =============================================================================
// Mouse.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Mouse.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Mouse.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/PartInstance.h"
#include <G3D/Ray.h>

namespace RBX
{
	const char sMouse[] = "Mouse"; // 0084b260 (classDescriptor 005fe7f0)

	// Template members the shared headers only declare (same definitions as Feature.cpp).
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::getClassName() const { return className(); }

	static Reflection::SignalDesc<Mouse, void(void)> event_Move("Move");
	static Reflection::SignalDesc<Mouse, void(void)> event_Idle("Idle");
	static Reflection::SignalDesc<Mouse, void(void)> event_Button1Down("Button1Down");
	static Reflection::SignalDesc<Mouse, void(void)> event_Button2Down("Button2Down");
	static Reflection::SignalDesc<Mouse, void(void)> event_Button1Up("Button1Up");
	static Reflection::SignalDesc<Mouse, void(void)> event_Button2Up("Button2Up");
	static Reflection::SignalDesc<Mouse, void(void)> event_WheelForward("WheelForward");
	static Reflection::SignalDesc<Mouse, void(void)> event_WheelBackward("WheelBackward");
	static Reflection::SignalDesc<Mouse, void(std::string)> event_KeyDown("KeyDown", "Key");
	static Reflection::PropDescriptor<Mouse, G3D::CoordinateFrame> prop_Hit(
		"Hit",
		"Data",
		&Mouse::getHit,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, G3D::CoordinateFrame> prop_Origin(
		"Origin",
		"Data",
		&Mouse::getOrigin,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::RefPropDescriptor<Mouse, PartInstance> prop_Target(
		"Target",
		"Data",
		&Mouse::getTarget,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, int> prop_X("X", "Data", &Mouse::getX, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, int> prop_Y("Y", "Data", &Mouse::getY, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, int> prop_ViewSizeX(
		"ViewSizeX",
		"Data",
		&Mouse::getViewSizeX,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, int> prop_ViewSizeY(
		"ViewSizeY",
		"Data",
		&Mouse::getViewSizeY,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, TextureId> prop_Icon(
		"Icon",
		"Data",
		&Mouse::getIcon,
		&Mouse::setIcon,
		Reflection::PropertyDescriptor::STANDARD);

	PartInstance* Mouse::getTarget() const
	{
		checkActive();

		if (command)
			return command->getPart(lastEvent, NULL);
		else
			return NULL;
	}

	G3D::CoordinateFrame Mouse::getOrigin() const
	{
		checkActive();

		G3D::Ray ray;

		if (command)
			ray = command->getUnitMouseRay(lastEvent);

		G3D::CoordinateFrame origin(ray.origin);
		origin.lookAt(ray.origin + ray.direction);

		return origin;
	}

	G3D::CoordinateFrame Mouse::getHit() const
	{
		checkActive();

		G3D::CoordinateFrame origin = getOrigin();

		if (command)
			command->getPartByLocalCharacter(lastEvent, origin.translation);

		return origin;
	}

	void Mouse::update(const UIEvent& uiEvent)
	{
		switch (uiEvent.eventType)
		{
		case UIEvent::MOUSE_MOVE:
			cacheUIEvent(uiEvent);
			event_Move.fire(this);
			break;
		case UIEvent::MOUSE_IDLE:
			cacheUIEvent(uiEvent);
			event_Idle.fire(this);
			break;
		case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
			cacheUIEvent(uiEvent);
			event_Button1Down.fire(this);
			break;
		case UIEvent::MOUSE_LEFT_BUTTON_UP:
			cacheUIEvent(uiEvent);
			event_Button1Up.fire(this);
			break;
		case UIEvent::MOUSE_RIGHT_BUTTON_DOWN:
			cacheUIEvent(uiEvent);
			event_Button2Down.fire(this);
			break;
		case UIEvent::MOUSE_RIGHT_BUTTON_UP:
			cacheUIEvent(uiEvent);
			event_Button2Up.fire(this);
			break;
		case UIEvent::MOUSE_WHEEL_FORWARD:
			event_WheelForward.fire(this);
			break;
		case UIEvent::MOUSE_WHEEL_BACKWARD:
			event_WheelBackward.fire(this);
			break;
		case UIEvent::KEY_DOWN:
			event_KeyDown.fire(this, std::string(1, (char)uiEvent.key));
			break;
		}
	}

	template boost::shared_ptr<Mouse> Creatable<Instance>::create<Mouse>();
}

template void RBX::Name::callDoDeclare<RBX::sMouse>();
