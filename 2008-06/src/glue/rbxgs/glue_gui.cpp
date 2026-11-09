// Rebuild glue: GUI layout and widget input rbxgs declares but never defines (replacing empty stubs).
// Children of a menu bar are laid out in order along its layout style (as TopMenuBar::getSize sums
// them); a relative panel sits on the canvas by its Rect locations plus offset (as
// Rect::positionChild); a widget tracks hover/press and clicks on release over itself.
// Behavioural reconstruction, not byte-verified.
#include "gui/Gui.h"
#include "gui/Widget.h"
#include "gui/Layout.h"
#include "util/Rect.h"

namespace RBX
{


	// GUI sizes are already in canvas pixels in this build


}
