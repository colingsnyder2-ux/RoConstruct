// 2008-06 native RBX::Mouse (inactive); evidence in native-headers/v8datamodel/Mouse.h. Verified by
// tests/record_native_mouse.py. Original Mouse bodies 0064df60..0064e80f with their descriptor template instances
// 0064e1e0..0064e5f0, dynamic initializers 007f8c40..007f8f30 and atexit rows 008010c0..008013c0. The class-template
// instances the original emits in the Tool unit (constructor chain 005fd5c0 / 005ff240 / 005ff3b0, classDescriptor
// 005fe7f0, ~Mouse 005ff520, create<Mouse> 005ff600) come out of this unit as COMDATs: this file is a codegen
// analog for them, not their original translation unit.
// Unit profile: document-swap flags plus /fp:fast (getOrigin 0064e050 keeps ray.origin + ray.direction in x87
// registers). cacheUIEvent is the inline donor member: defined out of line in this file it is compiled before update,
// whose register allocation then relies on it preserving ecx, unlike the original 0064e660.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
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

	// Dynamic initializers 007f8c40..007f8f30 (in this order).
	static Reflection::SignalDesc<Mouse, void(void)> event_Move("Move");
	static Reflection::SignalDesc<Mouse, void(void)> event_Idle("Idle");
	static Reflection::SignalDesc<Mouse, void(void)> event_Button1Down("Button1Down");
	static Reflection::SignalDesc<Mouse, void(void)> event_Button2Down("Button2Down");
	static Reflection::SignalDesc<Mouse, void(void)> event_Button1Up("Button1Up");
	static Reflection::SignalDesc<Mouse, void(void)> event_Button2Up("Button2Up");
	static Reflection::SignalDesc<Mouse, void(void)> event_WheelForward("WheelForward");
	static Reflection::SignalDesc<Mouse, void(void)> event_WheelBackward("WheelBackward");
	static Reflection::SignalDesc<Mouse, void(std::string)> event_KeyDown("KeyDown", "Key");
	static Reflection::PropDescriptor<Mouse, G3D::CoordinateFrame> prop_Hit("Hit", "Data", &Mouse::getHit, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, G3D::CoordinateFrame> prop_Origin("Origin", "Data", &Mouse::getOrigin, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::RefPropDescriptor<Mouse, PartInstance> prop_Target("Target", "Data", &Mouse::getTarget, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, int> prop_X("X", "Data", &Mouse::getX, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, int> prop_Y("Y", "Data", &Mouse::getY, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, int> prop_ViewSizeX("ViewSizeX", "Data", &Mouse::getViewSizeX, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, int> prop_ViewSizeY("ViewSizeY", "Data", &Mouse::getViewSizeY, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Mouse, TextureId> prop_Icon("Icon", "Data", &Mouse::getIcon, &Mouse::setIcon, Reflection::PropertyDescriptor::STANDARD);

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

	// The factory Tool::getMouse 005ff680 and ScriptMouseCommand's constructor call (005ff600); explicitly
	// instantiated here so the constructor chain, ~Mouse and the shared_ptr instances come out of this unit.
	template boost::shared_ptr<Mouse> Creatable<Instance>::create<Mouse>();
}

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sMouse>();
