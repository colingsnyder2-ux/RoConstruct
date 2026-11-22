// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/widget-rect-2008
// 2008-06 native RBX::Rect positioning bodies (inactive): the original util/Rect.cpp unit 005cef00..005cf000, apart
// from the GUI.cpp panels (00573480..00574130) that call them. Moved out of GuiPanels.cpp (batch 36) so the panel
// callers no longer see these bodies (flags copied from GuiPanels.cpp).
#include "util/Rect.h"

namespace RBX
{
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
}

