// 2008-06 native rows of the v8datamodel/Lighting.cpp unit inside the application range 005e0000..005e4000
// (inactive). Verified by tests/record_native_app_unit5e0.py (receipt app-unit5e0-working.json). Built against the
// committed native v8datamodel/Lighting2008.h and reflection/*.h, all read-only; the Lighting constructor, destructor,
// child notifications and event_LightingChanged are Lighting2008.cpp's (record_native_lighting2008.py).
//
// Evidence: the static initializers 007f69d0..007f6c40 of this unit construct one reflection descriptor each, with the
// member-function addresses as immediates (functionality flag 5 on the properties):
//   "TimeOfDay" (Data)          PropDescriptor<Lighting, std::string> 005e1170   get 005e0be0  set 005e2730
//   "GeographicLatitude" (Data) PropDescriptor<Lighting, float> 005e1220         get 005df490  set 005e2670
//   "GetMoonPhase"              BoundFuncDesc<Lighting, float(), 0> 005e1560     005df480
//   "GetMoonDirection"          BoundFuncDesc<Lighting, Vector3(), 0> 005e1690  getMoonPosition 005df4d0
//   "GetSunDirection"           (same instantiation)                             getSunPosition 005df500
//   "GetMinutesAfterMidnight"   BoundFuncDesc<Lighting, double(), 0> 005e1780    005e0610
//   "SetMinutesAfterMidnight" ("minutes") BoundFuncDesc<Lighting, void(double), 1> 005e18c0   005e26e0
//   "ShadowColor" (Appearance)  PropDescriptor<Lighting, Color3> 005e12d0        get 005df4a0  set 005e2540
//   "Brightness" (Appearance)   PropDescriptor<Lighting, float>                  get 004d6fe0  set 005e2420
//   "ColorShift_Top" / "ColorShift_Bottom" / "Ambient" (Appearance) PropDescriptor<Lighting, Color3>
//                                get 004d6f80 / 004d6fb0 / 004d6ff0, set 005e22c0 / 005e2370 / 005e2490
// The getter / setter types are the ones the GetSetImpl RTTI names (vtables 0083dc28 / 0083dc3c / 0083dc50):
// std::string () const with void (const std::string&), float () const with void (float), Color3 () const with
// void (Color3). Lighting has two non-virtual bases, so every member pointer is 8 bytes (GetSetImpl is new(0x18) with
// stores at +8..+0x14; BoundFuncDesc keeps it at +0x38/+0x3c).
// The descriptor objects themselves need the Lighting getters / setters that Lighting2008.h does not declare yet
// (proposal in the receipt); only the template instances, getTimeStr and the boost formatter it calls are built here.
#include "v8datamodel/Lighting2008.h"
#include <boost/date_time/posix_time/time_formatters.hpp>
#ifdef NATIVE_APPUNIT5E0_PENDING
#include "util/RunStateOwner.h"
#endif

namespace RBX
{
	// @005e0be0: time_duration timeOfDay (+0x268) copied by value to to_simple_string 005e0ba0
	std::string Lighting::getTimeStr() const
	{
		return boost::posix_time::to_simple_string(timeOfDay);
	}

#ifdef NATIVE_APPUNIT5E0_PENDING
	// Needs the Lighting getters / setters proposed for Lighting2008.h (pending-build-only; never counted). The
	// descriptor objects are the ones the static initializers 007f69d0..007f6c40 construct (addresses in comments).
	static Reflection::PropDescriptor<Lighting, std::string> prop_Time("TimeOfDay", "Data", &Lighting::getTimeStr, &Lighting::setTimeStr, Reflection::PropertyDescriptor::STANDARD);                                        // 0097a91c
	static Reflection::PropDescriptor<Lighting, float> prop_GeographicLatitude("GeographicLatitude", "Data", &Lighting::getGeographicLatitude, &Lighting::setGeographicLatitude, Reflection::PropertyDescriptor::STANDARD); // 0097a9f8
	static Reflection::BoundFuncDesc<Lighting, float(), 0> func_GetMoonPhase(&Lighting::getMoonPhase, "GetMoonPhase", Reflection::FunctionDescriptor::AnyCaller);                       // 0097a8c0
	static Reflection::BoundFuncDesc<Lighting, G3D::Vector3(), 0> func_GetMoonDirection(&Lighting::getMoonPosition, "GetMoonDirection", Reflection::FunctionDescriptor::AnyCaller);    // 0097aa18
	static Reflection::BoundFuncDesc<Lighting, G3D::Vector3(), 0> func_GetSunDirection(&Lighting::getSunPosition, "GetSunDirection", Reflection::FunctionDescriptor::AnyCaller);       // 0097a9b8
	static Reflection::BoundFuncDesc<Lighting, double(), 0> func_GetMinutesAfterMidnight(&Lighting::getMinutesAfterMidnight, "GetMinutesAfterMidnight", Reflection::FunctionDescriptor::AnyCaller); // 0097aa90
	static Reflection::BoundFuncDesc<Lighting, void(double), 1> func_SetMinutesAfterMidnight(&Lighting::setMinutesAfterMidnight, "SetMinutesAfterMidnight", "minutes", Reflection::FunctionDescriptor::AnyCaller); // 0097a938
	static Reflection::PropDescriptor<Lighting, G3D::Color3> prop_ShadowColor("ShadowColor", "Appearance", &Lighting::getShadowColor3, &Lighting::setShadowColor3, Reflection::PropertyDescriptor::STANDARD);       // 0097aa58
	static Reflection::PropDescriptor<Lighting, float> prop_Brightness("Brightness", "Appearance", &Lighting::getBrightness, &Lighting::setBrightness, Reflection::PropertyDescriptor::STANDARD);                    // 0097a980
	static Reflection::PropDescriptor<Lighting, G3D::Color3> prop_ColorShiftTop("ColorShift_Top", "Appearance", &Lighting::getColorShiftTop, &Lighting::setColorShiftTop, Reflection::PropertyDescriptor::STANDARD);  // 0097a900
	static Reflection::PropDescriptor<Lighting, G3D::Color3> prop_ColorShiftBottom("ColorShift_Bottom", "Appearance", &Lighting::getColorShiftBottom, &Lighting::setColorShiftBottom, Reflection::PropertyDescriptor::STANDARD); // 0097a99c
	static Reflection::PropDescriptor<Lighting, G3D::Color3> prop_Ambient("Ambient", "Appearance", &Lighting::getAmbient, &Lighting::setAmbient, Reflection::PropertyDescriptor::STANDARD);                          // 0097aa74

	// @005e0610: timeOfDay ticks / 1000 (__alldiv) times 1/60000 (0083dc60)
	double Lighting::getMinutesAfterMidnight()
	{
		return timeOfDay.total_milliseconds() / 60000.0;
	}

	// @005e2030
	void Lighting::setShadowColor(G3D::Color4 value)
	{
		if (value != shadowColor)
		{
			shadowColor = value;

			raisePropertyChanged(prop_ShadowColor);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	// @005e22c0
	void Lighting::setColorShiftTop(G3D::Color3 value)
	{
		if (value != colorShiftTop)
		{
			colorShiftTop = value;

			raisePropertyChanged(prop_ColorShiftTop);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	// @005e2370
	void Lighting::setColorShiftBottom(G3D::Color3 value)
	{
		if (value != colorShiftBottom)
		{
			colorShiftBottom = value;

			raisePropertyChanged(prop_ColorShiftBottom);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	// @005e2420
	void Lighting::setBrightness(float value)
	{
		if (value != brightness)
		{
			brightness = value;

			raisePropertyChanged(prop_Brightness);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	// @005e2490
	void Lighting::setAmbient(G3D::Color3 value)
	{
		if (value != ambient)
		{
			ambient = value;

			raisePropertyChanged(prop_Ambient);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	// @005e2540: Color4(value, 1)
	void Lighting::setShadowColor3(G3D::Color3 value)
	{
		setShadowColor(G3D::Color4(value));
	}

	// @005e2570
	void Lighting::setTime(const boost::posix_time::time_duration& value)
	{
		int totalSeconds = value.total_seconds();
		totalSeconds -= (totalSeconds / 86400) * 86400;

		if (timeOfDay.total_seconds() != totalSeconds)
		{
			timeOfDay = boost::posix_time::seconds(totalSeconds);
			skyParameters.setTime(timeOfDay.total_seconds());

			raisePropertyChanged(prop_Time);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	// @005e2670: skyParameters.geoLatitude (+0x224)
	void Lighting::setGeographicLatitude(float value)
	{
		if (value != skyParameters.geoLatitude)
		{
			skyParameters.geoLatitude = value;

			raisePropertyChanged(prop_GeographicLatitude);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	// @005e26e0: seconds(value * 60.0) (60.0 at 0083df30, _ftol2)
	void Lighting::setMinutesAfterMidnight(double value)
	{
		setTime(boost::posix_time::seconds(value * 60.0));
	}

	// @005e2730
	void Lighting::setTimeStr(const std::string& value)
	{
		setTime(boost::posix_time::duration_from_string(value));
	}
#endif
}

namespace R = RBX::Reflection;
typedef R::PropertyDescriptor::Functionality F;

// PropDescriptor constructors 005e1170 / 005e1220 / 005e12d0; they call the getset factories 005e02d0 / 005e0320 /
// 005e0370 (GetSetImpl vtables 0083dc28 / 0083dc3c / 0083dc50)
template R::PropDescriptor<RBX::Lighting, std::string>::PropDescriptor(const char*, const char*,
	std::string (RBX::Lighting::*)() const, void (RBX::Lighting::*)(const std::string&), F);
template R::PropDescriptor<RBX::Lighting, float>::PropDescriptor(const char*, const char*,
	float (RBX::Lighting::*)() const, void (RBX::Lighting::*)(float), F);
template R::PropDescriptor<RBX::Lighting, G3D::Color3>::PropDescriptor(const char*, const char*,
	G3D::Color3 (RBX::Lighting::*)() const, void (RBX::Lighting::*)(G3D::Color3), F);

// BoundFuncDesc constructors / execute / call (vtables 0083de00 / 0083de0c / 0083de18 / 0083de24)
template class R::BoundFuncDesc<RBX::Lighting, float(), 0>;
template class R::BoundFuncDesc<RBX::Lighting, G3D::Vector3(), 0>;
template class R::BoundFuncDesc<RBX::Lighting, double(), 0>;
template class R::BoundFuncDesc<RBX::Lighting, void(double), 1>;
