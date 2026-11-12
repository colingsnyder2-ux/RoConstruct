// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Lighting.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Lighting.h"

#include "util/RunStateOwner.h"
#include "v8datamodel/Sky.h"

#include <boost/date_time/posix_time/time_formatters.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>
#include <boost/date_time/time_parsing.hpp>

namespace RBX {

char sLighting[] = "Lighting";

Reflection::SignalDesc<Lighting, void(bool)> Lighting::event_LightingChanged("LightingChanged", "skyboxChanged");

} // namespace RBX

static RBX::Reflection::PropDescriptor<RBX::Lighting, G3D::Color3> desc_AmbientTop(
	"TopAmbientV9", "Appearance", &RBX::Lighting::getAmbientTop, &RBX::Lighting::setAmbientTop
);

static RBX::Reflection::PropDescriptor<RBX::Lighting, G3D::Color3> desc_AmbientBottom(
	"BottomAmbientV9", "Appearance", &RBX::Lighting::getAmbientBottom, &RBX::Lighting::setAmbientBottom
);

static RBX::Reflection::PropDescriptor<RBX::Lighting, G3D::Color3> desc_LightColor(
	"SpotLightV9", "Appearance", &RBX::Lighting::getLightColor, &RBX::Lighting::setLightColor
);

static RBX::Reflection::PropDescriptor<RBX::Lighting, G3D::Color3> desc_ClearColor(
	"ClearColor", "Appearance", &RBX::Lighting::getClearColor3, &RBX::Lighting::setClearColor3
);

static RBX::Reflection::PropDescriptor<RBX::Lighting, std::string> prop_Time(
	"TimeOfDay", "Data", &RBX::Lighting::getTimeStr, &RBX::Lighting::setTimeStr
);

static RBX::Reflection::PropDescriptor<RBX::Lighting, float> prop_GeographicLatitude(
	"GeographicLatitude", "Data", &RBX::Lighting::getGeographicLatitude, &RBX::Lighting::setGeographicLatitude
);

static RBX::Reflection::BoundFuncDesc<RBX::Lighting, float(), 0> prop_GetMoonPhase(
	&RBX::Lighting::getMoonPhase, "GetMoonPhase", RBX::Reflection::FunctionDescriptor::AnyCaller
);

static RBX::Reflection::BoundFuncDesc<RBX::Lighting, G3D::Vector3(), 0> prop_GetMoonPosition(
	&RBX::Lighting::getMoonPosition, "GetMoonDirection", RBX::Reflection::FunctionDescriptor::AnyCaller
);

static RBX::Reflection::BoundFuncDesc<RBX::Lighting, G3D::Vector3(), 0> prop_GetSunPosition(
	&RBX::Lighting::getSunPosition, "GetSunDirection", RBX::Reflection::FunctionDescriptor::AnyCaller
);

static RBX::Reflection::BoundFuncDesc<RBX::Lighting, double(), 0> func_GetMinutesAfterMidnight(
	&RBX::Lighting::getMinutesAfterMidnight, "GetMinutesAfterMidnight", RBX::Reflection::FunctionDescriptor::AnyCaller
);

static RBX::Reflection::BoundFuncDesc<RBX::Lighting, void(double), 1> func_SetMinutesAfterMidnight(
	&RBX::Lighting::setMinutesAfterMidnight,
	"SetMinutesAfterMidnight",
	"minutes",
	RBX::Reflection::FunctionDescriptor::AnyCaller
);

namespace RBX {

void Lighting::fireLightingChanged(bool skyChanged)
{
	event_LightingChanged.fire(this, skyChanged);

	if (RunService* runService = ServiceProvider::find<RunService>(this)) {
		runService->invalidateRunViews();
	}
}

// FUNCTION: WEBSERVICE 0x10042670
// FUNCTION: ROBLOX 0x005d9310
G3D::Vector3 Lighting::getMoonPosition()
{
	return skyParameters.physicallyCorrect ? skyParameters.trueMoonPosition : skyParameters.moonPosition;
}

// FUNCTION: WEBSERVICE 0x100426a0
// FUNCTION: ROBLOX 0x005d9340
G3D::Vector3 Lighting::getSunPosition()
{
	return skyParameters.physicallyCorrect ? skyParameters.trueSunPosition : skyParameters.sunPosition;
}

// FUNCTION: WEBSERVICE 0x100426d0
// FUNCTION: ROBLOX 0x005d9370
bool Lighting::askAddChild(const Instance* instance) const
{
	return dynamic_cast<const Sky*>(instance) != NULL;
}

// FUNCTION: WEBSERVICE 0x100438e0
// FUNCTION: ROBLOX 0x005da4b0
void Lighting::replaceSky(Sky* newSky)
{
	while (Sky* oldSky = findFirstChildOfType<Sky>()) {
		oldSky->setParent(NULL);
	}

	newSky->setParent(this);
}

// FUNCTION: WEBSERVICE 0x10043c40
// FUNCTION: ROBLOX 0x005da5a0
double Lighting::getMinutesAfterMidnight()
{
	return timeOfDay.total_milliseconds() / 60000.0;
}

// FUNCTION: WEBSERVICE 0x10044080
// FUNCTION: ROBLOX 0x005dab00
std::string Lighting::getTimeStr() const
{
	return boost::posix_time::to_simple_string(timeOfDay);
}

// FUNCTION: WEBSERVICE 0x10046190
// FUNCTION: ROBLOX 0x005dbcb0
Lighting::Lighting()
	: ambientTop(209 / 255.0f, 208 / 255.0f, 217 / 255.0f), ambientBottom(122 / 255.0f, 134 / 255.0f, 120 / 255.0f),
	  hasSky(true), clearColor(G3D::Color3::white()),
	  timeOfDay(boost::date_time::parse_delimited_time_duration<boost::posix_time::time_duration>("14:00:00"))
{
	skyParameters.lightColor = G3D::Color3(152 / 255.0f, 137 / 255.0f, 102 / 255.0f);
	skyParameters.setTime(timeOfDay.total_seconds());
	setName("Lighting");
}

// FUNCTION: WEBSERVICE 0x10046a90
// FUNCTION: ROBLOX 0x005dc430
void Lighting::setClearColor(G3D::Color4 value)
{
	if (value != clearColor) {
		clearColor = value;
		raisePropertyChanged(desc_ClearColor);
		fireLightingChanged(false);
	}
}

// FUNCTION: WEBSERVICE 0x10046b60
// FUNCTION: ROBLOX 0x005dc500
void Lighting::setLightColor(G3D::Color3 value)
{
	if (value != skyParameters.lightColor) {
		skyParameters.lightColor = value;
		raisePropertyChanged(desc_LightColor);
		fireLightingChanged(false);
	}
}

// FUNCTION: WEBSERVICE 0x10046c10
// FUNCTION: ROBLOX 0x005dc5b0
void Lighting::setAmbientBottom(G3D::Color3 value)
{
	if (value != ambientBottom) {
		ambientBottom = value;
		raisePropertyChanged(desc_AmbientBottom);
		fireLightingChanged(false);
	}
}

// FUNCTION: WEBSERVICE 0x10046cc0
// FUNCTION: ROBLOX 0x005dc660
void Lighting::onChildRemoving(Instance* child)
{
	if (sky.get() == child) {
		sky.reset();
		fireLightingChanged(true);
	}
}

// FUNCTION: WEBSERVICE 0x10046d60
// FUNCTION: ROBLOX 0x005dc700
void Lighting::onChildAdded(Instance* child)
{
	if (Sky* s = dynamic_cast<Sky*>(child)) {
		sky = shared_from(s);
		fireLightingChanged(true);
	}
}

// FUNCTION: WEBSERVICE 0x10046e60
// FUNCTION: ROBLOX 0x005dc800
void Lighting::onChildChanged(Instance* instance, const PropertyChanged& event)
{
	Instance::onChildChanged(instance, event);
	if (sky.get() == instance) {
		fireLightingChanged(true);
	}
}

// FUNCTION: WEBSERVICE 0x10046f60
// FUNCTION: ROBLOX 0x005dc930
void Lighting::setTime(const boost::posix_time::time_duration& value)
{
	int seconds = value.total_seconds();
	seconds = seconds % 86400;

	if (timeOfDay.total_seconds() != seconds) {
		timeOfDay = boost::posix_time::seconds(seconds);

		skyParameters.setTime(timeOfDay.total_seconds());
		raisePropertyChanged(prop_Time);
		fireLightingChanged(false);
	}
}

// FUNCTION: WEBSERVICE 0x10047060
// FUNCTION: ROBLOX 0x005dca30
void Lighting::setAmbientTop(G3D::Color3 value)
{
	if (value != ambientTop) {
		ambientTop = value;
		raisePropertyChanged(desc_AmbientTop);
		fireLightingChanged(false);
	}
}

// FUNCTION: WEBSERVICE 0x10047110
// FUNCTION: ROBLOX 0x005dcae0
void Lighting::setGeographicLatitude(float value)
{
	if (value != skyParameters.geoLatitude) {
		skyParameters.geoLatitude = value;
		raisePropertyChanged(prop_GeographicLatitude);
		fireLightingChanged(false);
	}
}

// FUNCTION: WEBSERVICE 0x10047220
// FUNCTION: ROBLOX 0x005dcbf0
void Lighting::setMinutesAfterMidnight(double value)
{
	setTime(boost::posix_time::seconds(static_cast<long>(value * 60.0)));
}

// FUNCTION: WEBSERVICE 0x10047270
// FUNCTION: ROBLOX 0x005dcc40
void Lighting::setTimeStr(const std::string& value)
{
	setTime(boost::posix_time::duration_from_string(value));
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Lighting, RBX::Instance, RBX::sLighting>;
template class RBX::Reflection::
	Described<RBX::Lighting, RBX::sLighting, RBX::FactoryProduct<RBX::Lighting, RBX::Instance, RBX::sLighting> >;
template class RBX::DescribedCreatable<RBX::Lighting, RBX::Instance, RBX::sLighting>;
template const RBX::FactoryProduct<RBX::Sky, RBX::Instance, RBX::sSky>::Creator
	RBX::FactoryProduct<RBX::Sky, RBX::Instance, RBX::sSky>::creator;
