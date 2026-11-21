#pragma once
// 2008-06 RBX::UIEvent (inactive). Shape after the donor tools/rbxgs util/UIEvent.h; layout read from the 2008-06
// binary: DxUserInput builds 0x14-byte events (eventType +0, userInput +4, then a 12-byte union: Short2 position +8,
// Short2 delta +0xc, Short2 windowSize +0x10 for mouse events, or SDLKey +8, SDLMod +0xc and a zeroed windowSize +0x10
// for key events). Separate file name so the donor header is not shadowed.
#include "util/UserInputBase.h"
#include <SDL.h>
#include <G3D/Vector2int16.h>

namespace RBX
{
	class UIEvent
	{
	public:
		enum EventType
		{
			NO_EVENT,
			MOUSE_RIGHT_BUTTON_DOWN,
			MOUSE_RIGHT_BUTTON_UP,
			MOUSE_LEFT_BUTTON_DOWN,
			MOUSE_LEFT_BUTTON_UP,
			MOUSE_MOVE,
			MOUSE_DELTA,
			MOUSE_IDLE,
			MOUSE_WHEEL_FORWARD,
			MOUSE_WHEEL_BACKWARD,
			KEY_DOWN,
			KEY_UP,
			// INFERRED: 0xc and 0xd are built by DxUserInput 00468b90 for WM_MOUSELEAVE-style/non-client messages
			EVENT_12,
			EVENT_13
		};

		EventType eventType;
		UserInputBase* userInput;
		union
		{
			struct
			{
				G3D::Vector2int16 mousePosition;
				G3D::Vector2int16 mouseDelta;
			};
			struct
			{
				SDLKey key;
				SDLMod mod;
			};
		};
		G3D::Vector2int16 windowSize;

		// 004672a0 (out of line): position and delta zero, windowSize = argument
		UIEvent(UserInputBase* userInput, EventType eventType, G3D::Vector2int16 windowSize);

		// inlined by DxUserInput 004684a0: all three vectors given
		UIEvent(UserInputBase* userInput, EventType eventType, const G3D::Vector2int16& mousePosition,
				const G3D::Vector2int16& mouseDelta, const G3D::Vector2int16& windowSize)
			: eventType(eventType),
			  userInput(userInput),
			  mousePosition(mousePosition),
			  mouseDelta(mouseDelta),
			  windowSize(windowSize)
		{
		}

		// inlined by DxUserInput 004681b0: key events carry a zero windowSize
		UIEvent(UserInputBase* userInput, EventType eventType, SDLKey key, SDLMod mod)
			: eventType(eventType),
			  userInput(userInput),
			  key(key),
			  mod(mod),
			  windowSize(0, 0)
		{
		}
	};
}
