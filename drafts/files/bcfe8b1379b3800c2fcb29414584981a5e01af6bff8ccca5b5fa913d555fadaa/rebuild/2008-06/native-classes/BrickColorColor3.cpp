// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// BrickColor::color3 (005b6270) - native 2008-06.
// >>> native-status (generated) -- do not edit >>>
// BrickColorColor3 | 2008-06 | draft (byte proof at 005b6270)
// 1/1 mapped addresses byte-exact | no mapped strings | by colin
// <<< native-status | src fcd2c7f1 | roc native-status --write
#include "v8datamodel/BrickColor.h"

namespace RBX {
	G3D::Color3 BrickColor::color3() const
	{
		G3D::Color4 color = color4();
		return G3D::Color3(color.r, color.g, color.b);
	}
}
