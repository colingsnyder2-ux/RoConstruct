// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/widget-rect-2008
// 2008-06 native RBX::Rect positioning bodies (inactive): the original util/Rect.cpp unit 005cef00..005cf000, apart
// from the GUI.cpp panels (00573480..00574130) that call them. Moved out of GuiPanels.cpp (batch 36) so the panel
// callers no longer see these bodies (flags copied from GuiPanels.cpp).
#include "util/Rect.h"
#include <algorithm>

namespace RBX
{
	// 005ceea0 (registry func_005ceea0; caller HealthHud::render2d 006568e8). Statement shape from the 2007
	// openrbx Client/App/util/Rect.cpp positionPoint(Location, Location): center, then the two switches; the
	// y switch's `case CENTER: return point;` is the dead `sub edx, 3` compare before the shared ret (005ceee5).
	// Retires the donor-header copy in OgreAuto_RBX_Rect.cpp (no /Ob2 /Oy /GF flags, rbxgs util/Rect.h).
	G3D::Vector2 Rect::positionPoint(Location xLocation, Location yLocation) const
	{
		G3D::Vector2 point = center();

		switch (xLocation)
		{
		case LEFT:
			point.x = low.x;
			break;
		case RIGHT:
			point.x = high.x;
			break;
		}

		switch (yLocation)
		{
		case TOP:
			point.y = low.y;
			break;
		case BOTTOM:
			point.y = high.y;
			break;
		case CENTER:
			return point;
		}

		return point;
	}

	// 005cef00
	G3D::Vector2 Rect::positionPoint(const G3D::Vector2& point, Location xLocation, Location yLocation) const
	{
		G3D::Vector2 answer;

		switch (xLocation)
		{
		case LEFT:
			answer.x = point.x + low.x;
			break;
		case RIGHT:
			answer.x = high.x - point.x;
			break;
		}

		switch (yLocation)
		{
		case TOP:
			answer.y = point.y + low.y;
			break;
		case BOTTOM:
			answer.y = high.y - point.y;
			break;
		}

		return answer;
	}

	// 005cef60
	Rect Rect::positionChild(const RBX::Rect& child, Location xLocation, Location yLocation) const
	{
		G3D::Vector2 newLow;
		G3D::Vector2 childSize = child.size();

		switch (xLocation)
		{
		case LEFT:
			newLow.x = low.x;
			break;
		case RIGHT:
			newLow.x = high.x - childSize.x;
			break;
		case CENTER:
			newLow.x = (high.x - childSize.x) * 0.5f;
			break;
		}

		switch (yLocation)
		{
		case TOP:
			newLow.y = low.y;
			break;
		case BOTTOM:
			newLow.y = high.y - childSize.y;
			break;
		case CENTER:
			newLow.y = (high.y - childSize.y) * 0.5f;
			break;
		}

		return fromLowSize(newLow, childSize);
	}

	// 005cf000 (registry func_005cf000; caller 0046a010). openrbx Client/App/util/Rect.cpp unionWith(const Rect&):
	// std::min/std::max select by reference (the target picks a pointer, then loads it).
	void Rect::unionWith(const Rect& other)
	{
		low.x = std::min(low.x, other.low.x);
		low.y = std::min(low.y, other.low.y);
		high.x = std::max(high.x, other.high.x);
		high.y = std::max(high.y, other.high.y);
	}
}
