// native-flags: /O2 /GS- /EHsc /MD /fp:fast /D_AFXDLL /GS-
#include "../../../tools/rbxgs/Client/App/include/util/Rect.h"

namespace RBX {
G3D::Vector2 Rect::positionPoint(Location xLocation, Location yLocation) const
{
	G3D::Vector2 result = (high + low) * 0.5f;
	switch (xLocation)
	{
	case LEFT:
		result.x = low.x;
		break;
	case RIGHT:
		result.x = high.x;
		break;
	}
	switch (yLocation)
	{
	case TOP:
		result.y = low.y;
		return result;
	case BOTTOM:
		result.y = high.y;
		return result;
	case CENTER:
		return result;
	}
	return result;
}
}
