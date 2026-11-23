#include "util/Rect.h"

namespace RBX
{
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

#include "../../../../../../tools/rbxgs/Client/App/include/util/Rect.h"

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
