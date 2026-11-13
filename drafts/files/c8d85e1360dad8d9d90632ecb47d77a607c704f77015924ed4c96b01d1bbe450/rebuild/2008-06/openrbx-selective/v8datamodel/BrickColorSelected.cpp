#include "v8datamodel/BrickColor.h"

#include <G3D/g3dmath.h>
#include <cmath>
#include <map>

namespace RBX {

// PORT: selective unit; remaining functions use the 2008 object.

void BrickColor::BrickMap::insert(Number number, unsigned char r, unsigned char g, unsigned char b, std::string name)
{
	G3D::Color4uint8 c;
	c.r = r;
	c.g = g;
	c.b = b;

	allColors.push_back(BrickColor(number));

	map1.insert(std::pair<Number, G3D::Color4uint8>(number, c));

	std::pair<Number, G3D::Color4> p2(number, c);
	map2.insert(p2);

	std::pair<Number, std::string> p3(number, name);
	map3.insert(p3);
}

} // namespace RBX
