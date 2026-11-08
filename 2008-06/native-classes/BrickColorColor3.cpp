// >>> native-status (generated) -- do not edit >>>
// BrickColorColor3 | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src fcd2c7f1 | roc native-status --write
#include "v8datamodel/BrickColor.h"

namespace RBX {
	G3D::Color3 BrickColor::color3() const
	{
		G3D::Color4 color = color4();
		return G3D::Color3(color.r, color.g, color.b);
	}
}
