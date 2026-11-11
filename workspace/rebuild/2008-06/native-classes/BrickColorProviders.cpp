// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// BrickColorProviders | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 69a27bbb | roc native-status --write
#include "v8datamodel/BrickColor.h"

namespace RBX {
	const std::vector<BrickColor>& BrickColor::colorPalette()
	{
		return BrickMap::singleton().colorPalette;
	}

	unsigned BrickColor::getClosestPaletteIndex() const
	{
		return BrickMap::singleton().paletteMap[number];
	}

	BrickColor BrickColor::parse(const char* name)
	{
		std::map<enum Number, std::string>::const_iterator iter = BrickMap::singleton().map3.begin();
		std::map<enum Number, std::string>::const_iterator end = BrickMap::singleton().map3.end();

		for (; iter != end; iter++)
		{
			if (iter->second == name)
				return BrickColor(iter->first);
		}

		return BrickColor(lego_194);
	}

	BrickColor BrickColor::random()
	{
		int index = G3D::iRandom(0, (int)BrickMap::singleton().colorPalette.size() - 1);
		return BrickMap::singleton().colorPalette[index];
	}

	BrickColor BrickColor::closest(G3D::Color3 color)
	{
		G3D::Color4 c4;
		c4.r = color.r;
		c4.g = color.g;
		c4.b = color.b;

		return closest(c4);
	}

	BrickColor BrickColor::closest(G3D::Color4 color)
	{
		float closestDistance = 10000.0f;
		Number number = lego_194;

		std::map<enum Number, G3D::Color4>::iterator iter = BrickMap::singleton().map2.begin();
		std::map<enum Number, G3D::Color4>::iterator end = BrickMap::singleton().map2.end();

		for (; iter != end; iter++)
		{
			float distance = fabs(iter->second.r - color.r);
			distance += fabs(iter->second.g - color.g);
			distance += fabs(iter->second.b - color.b);

			if (distance < closestDistance)
			{
				number = iter->first;
				if (distance == 0.0f)
					break;
				closestDistance = distance;
			}
		}

		return BrickColor(number);
	}

	BrickColor::BrickColor(int number)
	{
		std::map<enum Number, G3D::Color4uint8>::iterator it = BrickMap::singleton().map1.find((Number)number);
		if (it != BrickMap::singleton().map1.end())
			this->number = it->first;
		else
			this->number = lego_194;
	}

	const std::string& BrickColor::name() const
	{
		return BrickMap::singleton().map3.find(number)->second;
	}

	G3D::Color4 BrickColor::color4() const
	{
		return BrickMap::singleton().map2.find(number)->second;
	}

}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Tree<std::_Tmap_traits<enum RBX::BrickColor::Number,G3D::Color4,std::less<enum RBX::BrickColor::Number>,std::allocator<std::pair<enum RBX::BrickColor::Number const ,G3D::Color4> >,0> >;
template class std::_Tree<std::_Tmap_traits<enum RBX::BrickColor::Number,G3D::Color4uint8,std::less<enum RBX::BrickColor::Number>,std::allocator<std::pair<enum RBX::BrickColor::Number const ,G3D::Color4uint8> >,0> >;
template class std::_Tree<std::_Tmap_traits<enum RBX::BrickColor::Number,int,std::less<enum RBX::BrickColor::Number>,std::allocator<std::pair<enum RBX::BrickColor::Number const ,int> >,0> >;
template class std::_Tree<std::_Tmap_traits<enum RBX::BrickColor::Number,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<enum RBX::BrickColor::Number>,std::allocator<std::pair<enum RBX::BrickColor::Number const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,0> >;
template class std::allocator<std::pair<enum RBX::BrickColor::Number const ,int> >;
template class std::vector<RBX::BrickColor,std::allocator<RBX::BrickColor> >;
