#include "v8datamodel/BrickColor.h"

namespace RBX {
	G3D::Color3 BrickColor::color3() const
	{
		G3D::Color4 color = color4();
		return G3D::Color3(color.r, color.g, color.b);
	}
}
