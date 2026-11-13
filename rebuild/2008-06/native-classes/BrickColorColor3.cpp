// >>> native-status (generated) -- do not edit >>>
// BrickColorColor3 | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (gpt-6.1-sol)
// <<< native-status | src fcd2c7f1 | roc native-status --write
#include "v8datamodel/BrickColor.h"

namespace RBX {
	G3D::Color3 BrickColor::color3() const
	{
		G3D::Color4 color = color4();
		return G3D::Color3(color.r, color.g, color.b);
	}
}
