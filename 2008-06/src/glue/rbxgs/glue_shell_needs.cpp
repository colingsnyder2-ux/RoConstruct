// Engine members the native 2008 shell links against that no named rbxgs source defines yet.
// Bodies are the mined 2007 units (tools/rbxgs/Client/App/roc_unit_3ec6397cb9dfa2ae.cpp, roc_espeon_aug2007_brick_color_bytes_*, roc_espeon_aug2007_instance_*, roc_espeon_aug2007_signals133_app_*, roc_espeon_imagefileprivatecontext*, roc_espclaude_37e59a7671edc08f.cpp).
#include "v8datamodel/Selection.h"
#include "v8datamodel/BrickColor.h"
#include "v8tree/Instance.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/GlobalSettings.h"
#include "util/ContentProvider.h"

namespace RBX
{
	const double cameraRadiansToDegrees = 180.0 / 3.14159265358979323846;

	void GlobalSettings::saveState() {}
	void GlobalSettings::eraseSettingsStore() {}

	std::vector<boost::shared_ptr<Instance> >::const_iterator Selection::begin() const
	{
		return selection->begin();
	}

	std::vector<boost::shared_ptr<Instance> >::const_iterator Selection::end() const
	{
		return selection->end();
	}

	G3D::Color4uint8 BrickColor::color4uint8() const
	{
		return BrickMap::singleton().map1.find(number)->second;
	}

	G3D::Color3uint8 BrickColor::color3uint8() const
	{
		G3D::Color4uint8 c = color4uint8();
		return G3D::Color3uint8(c.r, c.g, c.b);
	}

	BrickColor BrickColor::closest(G3D::Color4uint8 color)
	{
		Number number = lego_194;
		int closestDistance = 10000;

		std::map<enum Number, G3D::Color4uint8>::iterator iter = BrickMap::singleton().map1.begin();
		std::map<enum Number, G3D::Color4uint8>::iterator end = BrickMap::singleton().map1.end();

		for (; iter != end; iter++)
		{
			int distance = abs(iter->second.r - color.r);
			distance += abs(iter->second.g - color.g);
			distance += abs(iter->second.b - color.b);

			if (distance < closestDistance)
			{
				number = iter->first;
				if (distance == 0)
					break;
				closestDistance = distance;
			}
		}

		return BrickColor(number);
	}

	const Name& getMimeType(const char* filename)
	{
		return Name::declare(filename, -1);
	}
}
