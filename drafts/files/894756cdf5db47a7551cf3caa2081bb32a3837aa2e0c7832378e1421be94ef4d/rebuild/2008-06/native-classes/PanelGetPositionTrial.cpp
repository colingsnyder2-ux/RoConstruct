// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::RelativePanel::getPosition trial (inactive): 005737e0..005738d0 (241 B).
// New evidence from the byte-aligned instruction diff of the previous candidate (190 B): the ORIGINAL spends
// both Vector2::zero() results to frame slots 0x18/0x20/0x28/0x2c and then computes the four Rect floats as ONE
// fused x87 expression (fld/fadd st(1)/fsubrp st(4)/fsubrp st(2)/fxch), whereas a form with separate += / -=
// statements keeps them on the register stack. This candidate fuses the arithmetic so both zero results stay live
// across the canvas and size loads, matching that liveness.
#include "gui/Gui.h"

namespace RBX
{
	G3D::Vector2 RelativePanel::getPosition() const
	{
		G3D::Vector2 canvas = GuiRoot::getCanvasSize();
		G3D::Vector2 at = G3D::Vector2::zero();
		G3D::Vector2 size = getSize();
		G3D::Vector2 high = G3D::Vector2::zero();
		at.x += (float)offset.x;
		at.y += (float)offset.y;
		high.x += canvas.x - size.x;
		high.y += canvas.y - size.y;
		return Rect(at, high).positionPoint(size, xLocation, yLocation);
	}
}
