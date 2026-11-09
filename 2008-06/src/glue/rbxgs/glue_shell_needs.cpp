// Engine members the native 2008 shell links against that no named rbxgs source defines yet.
// Bodies are the mined 2007 units (tools/rbxgs/Client/App/roc_unit_3ec6397cb9dfa2ae.cpp, roc_espeon_aug2007_brick_color_bytes_*).
#include "v8datamodel/Selection.h"
#include "v8datamodel/BrickColor.h"

namespace RBX
{
	std::vector<boost::shared_ptr<Instance> >::const_iterator Selection::end() const
	{
		return selection->end();
	}

	G3D::Color3uint8 BrickColor::color3uint8() const
	{
		G3D::Color4uint8 c = color4uint8();
		return G3D::Color3uint8(c.r, c.g, c.b);
	}
}
