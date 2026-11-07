// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::PercentPanel::getPosition trial (inactive): 005738e0..00573958.
// Hypothesis reconstructed from the decoded frame layout: a canvasSize copy, a GuiRoot::toPixelSize call on
// this->position (+0x164), and Rect::positionPoint(size, xLocation +0x15c, yLocation +0x160) on a
// Rect(Vector2::zero(), canvas) temporary. Verified by
// work/2008-06/shared-layouts/panel-getposition-batch.json.
#include "gui/Gui.h"

namespace RBX
{
	G3D::Vector2 RelativePanel::getPosition() const
	{
		G3D::Vector2 canvas = GuiRoot::getCanvasSize();
		G3D::Vector2 size = getSize();
		G3D::Vector2 at = G3D::Vector2::zero();
		at.x += (float)offset.x;
		at.y += (float)offset.y;
		return Rect(at, canvas - at - size).positionPoint(size, xLocation, yLocation);
	}
}
