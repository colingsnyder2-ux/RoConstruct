// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::RelativePanel::getPosition trial (inactive): 005737e0..005738d0.
// BEST FORM ON DISK = 190 B against the original's 241 B. Two variants with the same size are recorded in
// work/2008-06/shared-layouts/panel-getposition-20261106.json; a third, with the high arithmetic fused
// (high.x += canvas.x - size.x), produced 188 B - further away - and showed why: the original keeps both
// fild-converted offsets AND both Vector2::zero() results live at once and accumulates with the non-popping
// "fadd st(1)" form, i.e. its source has one accumulator expression spanning the canvas and size loads.
// That liveness is the unresolved residual; see the receipt's relative_panel_decode.next_proof.
#include "gui/Gui.h"

namespace RBX
{
	G3D::Vector2 RelativePanel::getPosition() const
	{
		G3D::Vector2 canvas = GuiRoot::getCanvasSize();
		G3D::Vector2 at = G3D::Vector2::zero();
		G3D::Vector2 size = getSize();
		G3D::Vector2 high = G3D::Vector2::zero();
		high += canvas;
		high -= size;
		at.x += (float)offset.x;
		at.y += (float)offset.y;
		return Rect(at, high).positionPoint(size, xLocation, yLocation);
	}

	// Ported from the server-verified reference src/2008-06/005738e0.cpp (100% by king_originala), whose
	// placeholder names map to: scaleX/scaleY = GuiRoot::canvasSize, zeroVector = G3D::Vector2::zero(),
	// transformVector = GuiRoot::toPixelSize, and UserInputBase::getSteerThrottle = Rect::positionPoint.
	// The reference expresses it as: canvas copy, a const reference to zero(), a Rect(zero, canvas) temporary,
	// the toPixelSize result, then positionPoint - in that order.
	G3D::Vector2 PercentPanel::getPosition() const
	{
		G3D::Vector2 canvas = GuiRoot::getCanvasSize();
		const G3D::Vector2& zero = G3D::Vector2::zero();
		Rect rect(zero, canvas);
		G3D::Vector2 size = GuiRoot::toPixelSize(position);
		return rect.positionPoint(size, xLocation, yLocation);
	}
}
