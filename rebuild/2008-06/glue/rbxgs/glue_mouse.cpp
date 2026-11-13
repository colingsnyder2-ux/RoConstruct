// Rebuild glue: Mouse::update and the script-facing Mouse events. rbxgs declares update but defines
// no Mouse events; names are the 2008-06 Roblox.exe strings next to the Mouse members ("Move", "Idle",
// "Button1Down", "Button2Down", "Button1Up", "Button2Up", "WheelForward", "WheelBackward", "KeyDown"
// with argument "key"). Behavioural reconstruction, not byte-verified.
#include "v8datamodel/Mouse.h"
#include "reflection/signal.h"

namespace RBX
{
	namespace
	{
		Reflection::SignalDesc<Mouse, void(void)> event_Move("Move");
		Reflection::SignalDesc<Mouse, void(void)> event_Idle("Idle");
		Reflection::SignalDesc<Mouse, void(void)> event_Button1Down("Button1Down");
		Reflection::SignalDesc<Mouse, void(void)> event_Button2Down("Button2Down");
		Reflection::SignalDesc<Mouse, void(void)> event_Button1Up("Button1Up");
		Reflection::SignalDesc<Mouse, void(void)> event_Button2Up("Button2Up");
		Reflection::SignalDesc<Mouse, void(void)> event_WheelForward("WheelForward");
		Reflection::SignalDesc<Mouse, void(void)> event_WheelBackward("WheelBackward");
		Reflection::SignalDesc<Mouse, void(std::string)> event_KeyDown("KeyDown", "key");

		// printable keys as their lower-case character, others unnamed
		std::string keyName(SDLKey key)
		{
			if (key >= 32 && key < 127)
				return std::string(1, (char)tolower(key));
			return std::string();
		}
	}

}
