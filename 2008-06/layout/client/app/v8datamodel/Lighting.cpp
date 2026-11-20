#include "v8datamodel/Lighting2008.h"
#include "util/Name.h"

namespace RBX {

G3D::Color3 Lighting::getAmbient() const
{
	return ambient;
}

}

#include "v8datamodel/Sky.h"
#include "util/RunStateOwner.h"

namespace RBX
{
	// INFERRED: descriptor names and the "Appearance" category follow the donor Lighting pattern; the binary's
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_ColorShiftTop("ColorShift_Top", "Appearance", &Lighting::getColorShiftTop, &Lighting::setColorShiftTop, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_ColorShiftBottom("ColorShift_Bottom", "Appearance", &Lighting::getColorShiftBottom, &Lighting::setColorShiftBottom, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_Ambient("Ambient", "Appearance", &Lighting::getAmbient, &Lighting::setAmbient, Reflection::PropertyDescriptor::STANDARD);

	void Lighting::setColorShiftTop(G3D::Color3 value)
	{
		if (value != colorShiftTop)
		{
			colorShiftTop = value;

			raisePropertyChanged(desc_ColorShiftTop);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setColorShiftBottom(G3D::Color3 value)
	{
		if (value != colorShiftBottom)
		{
			colorShiftBottom = value;

			raisePropertyChanged(desc_ColorShiftBottom);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setAmbient(G3D::Color3 value)
	{
		if (value != ambient)
		{
			ambient = value;

			raisePropertyChanged(desc_Ambient);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}
}

#include <boost/date_time/posix_time/time_formatters.hpp>

namespace RBX {
std::string Lighting::getTimeStr() const
	{
		return boost::posix_time::to_simple_string(timeOfDay);
	}
}
