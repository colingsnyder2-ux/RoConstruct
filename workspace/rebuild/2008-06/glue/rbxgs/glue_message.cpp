// Rebuild glue: Message and RefPropertyDescriptor members rbxgs declares but never defines.
// RefPropertyDescriptor string access follows OpenRBX reflection/property.h (2008-verified: empty
// string, setting fails). Message::renderPersonalMsg is a behavioural reconstruction in the style of
// rbxgs Message::renderFullScreen (a personal message is a banner at the top, not a screen overlay).
#include "v8datamodel/Message.h"
#include "reflection/property.h"
#include <G3D/Rect2D.h>

namespace RBX
{

	// a Hint is a dark bar along the bottom of the screen with its text in it

	namespace Reflection
	{
	}
}
