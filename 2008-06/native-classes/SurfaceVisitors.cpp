#include "../native-headers/v8datamodel/PartInstance.h"
#include "../native-headers/v8datamodel/Surfaces.h"
#include <boost/bind.hpp>
#include <algorithm>

namespace RBX {

void weldInstance(boost::shared_ptr<Instance> value) {
	PartInstance* part = dynamic_cast<PartInstance*>(value.get());
	if (part) {
		Surfaces& surfaces = part->getSurfaces();
		for (int i = 0; i < 6; ++i)
			if (surfaces[static_cast<NormalId>(i)].getSurfaceType() == GLUE)
				surfaces[static_cast<NormalId>(i)].setSurfaceType(WELD);
	}
	if (value->children)
		std::for_each(value->children->begin(), value->children->end(), boost::bind(weldInstance, _1));
}

void snapInstance(boost::shared_ptr<Instance> value) {
	PartInstance* part = dynamic_cast<PartInstance*>(value.get());
	if (part) {
		Surfaces& surfaces = part->getSurfaces();
		for (int i = 0; i < 6; ++i)
			if (surfaces[static_cast<NormalId>(i)].getSurfaceType() == WELD)
				surfaces[static_cast<NormalId>(i)].setSurfaceType(STUDS);
	}
	if (value->children)
		std::for_each(value->children->begin(), value->children->end(), boost::bind(snapInstance, _1));
}

}
