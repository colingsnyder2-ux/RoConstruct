// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll util/Rect.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Rect.h"

namespace RBX
{
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
