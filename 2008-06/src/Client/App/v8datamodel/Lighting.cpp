#pragma float_control(precise, off)
#include "v8datamodel/Lighting.h"
#include "util/RunStateOwner.h"

namespace RBX
{
	char* sLighting = "Lighting";

	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_AmbientTop("TopAmbientV9", "Appearance", &Lighting::getAmbientTop, &Lighting::setAmbientTop, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_AmbientBottom("BottomAmbientV9", "Appearance", &Lighting::getAmbientBottom, &Lighting::setAmbientBottom, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_LightColor("SpotLightV9", "Appearance", &Lighting::getLightColor, &Lighting::setLightColor, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_ClearColor("ClearColor", "Appearance", &Lighting::getClearColor3, &Lighting::setClearColor3, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, std::string> prop_Time("TimeOfDay", "Data", &Lighting::getTimeStr, &Lighting::setTimeStr, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, float> prop_GeographicLatitude("GeographicLatitude", "Data", &Lighting::getGeographicLatitude, &Lighting::setGeographicLatitude, Reflection::PropertyDescriptor::STANDARD);

	static Reflection::BoundFuncDesc<Lighting, float(void), 0> prop_GetMoonPhase(&Lighting::getMoonPhase, "GetMoonPhase", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<Lighting, G3D::Vector3(void), 0> prop_GetMoonPosition(&Lighting::getMoonPosition, "GetMoonDirection", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<Lighting, G3D::Vector3(void), 0> prop_GetSunPosition(&Lighting::getSunPosition, "GetSunDirection", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<Lighting, double(void), 0> prop_GetMinutesAfterMidnight(&Lighting::getMinutesAfterMidnight, "GetMinutesAfterMidnight", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<Lighting, void(double), 1> prop_SetMinutesAfterMidnight(&Lighting::setMinutesAfterMidnight, "SetMinutesAfterMidnight", "minutes", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::PropDescriptor<Lighting, float> prop_Brightness("Brightness", "Appearance", &Lighting::getBrightness, &Lighting::setBrightness, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> prop_ColorShift_Top("ColorShift_Top", "Appearance", &Lighting::getColorShift_Top, &Lighting::setColorShift_Top, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> prop_ColorShift_Bottom("ColorShift_Bottom", "Appearance", &Lighting::getColorShift_Bottom, &Lighting::setColorShift_Bottom, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> prop_Ambient("Ambient", "Appearance", &Lighting::getAmbient, &Lighting::setAmbient, Reflection::PropertyDescriptor::STANDARD);

	Reflection::SignalDesc<Lighting, void(bool)> Lighting::event_LightingChanged("LightingChanged", "skyboxChanged");

	Lighting::Lighting()
		: Base(),
		  ambientTop(209/255.0f, 208/255.0f, 217/255.0f),
		  ambientBottom(122/255.0f, 134/255.0f, 120/255.0f),
		  hasSky(true),
		  shadowColor(G3D::Color3::white()),
		  clearColor(0.7f, 0.7f, 0.72f),
		  timeOfDay(boost::posix_time::duration_from_string("14:00:00")),
		  v0(0.0f, 0.0f, 0.0f),
		  v1(0.0f, 0.0f, 0.0f),
		  f0(1.0f),
		  c0(0.5f, 0.5f, 0.5f),
		  c1(1.0f, 1.0f, 1.0f),
		  c2(1.0f, 1.0f, 1.0f),
		  c3(1.0f, 1.0f, 1.0f),
		  v2(0.0f, 0.0f, 0.0f),
		  v3(1.0f, 1.0f, 1.0f)
	{
		skyParameters.lightColor = G3D::Color3(152/255.0f, 137/255.0f, 102/255.0f);
		skyParameters.setTime(timeOfDay.total_seconds());
		setName("Lighting");
	}

	G3D::Vector3 Lighting::getMoonPosition()
	{
		return (skyParameters.physicallyCorrect) ? skyParameters.trueMoonPosition : skyParameters.moonPosition;
	}

	G3D::Vector3 Lighting::getSunPosition()
	{
		return (skyParameters.physicallyCorrect) ? skyParameters.trueSunPosition : skyParameters.sunPosition;
	}

	void Lighting::replaceSky(Sky* newSky)
	{
		while (Sky* currentSky = findFirstChildOfType<Sky>())
		{
			currentSky->setParent(NULL);
		}

		newSky->setParent(this);
	}

	std::string Lighting::getTimeStr() const
	{
		return boost::posix_time::to_simple_string(timeOfDay);
	}

	void Lighting::setTimeStr(const std::string& value)
	{
		setTime(boost::posix_time::duration_from_string(value));
	}

	void Lighting::setClearColor(G3D::Color4 value)
	{
		if (value != clearColor)
		{
			clearColor = value;

			raisePropertyChanged(desc_ClearColor);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setLightColor(G3D::Color3 value)
	{
		if (value != skyParameters.lightColor)
		{
			skyParameters.lightColor = value;

			raisePropertyChanged(desc_LightColor);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setAmbientBottom(G3D::Color3 value)
	{
		if (value != ambientBottom)
		{
			ambientBottom = value;

			raisePropertyChanged(desc_AmbientBottom);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setAmbientTop(G3D::Color3 value)
	{
		if (value != ambientTop)
		{
			ambientTop = value;

			raisePropertyChanged(desc_AmbientTop);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setColorShift_Top(G3D::Color3 value)
	{
		if (value != v0)
		{
			v0 = value;

			raisePropertyChanged(prop_ColorShift_Top);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setColorShift_Bottom(G3D::Color3 value)
	{
		if (value != v1)
		{
			v1 = value;

			raisePropertyChanged(prop_ColorShift_Bottom);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setBrightness(float value)
	{
		if (value != f0)
		{
			f0 = value;

			raisePropertyChanged(prop_Brightness);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setAmbient(G3D::Color3 value)
	{
		if (value != c0)
		{
			c0 = value;

			raisePropertyChanged(prop_Ambient);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

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

	double Lighting::getMinutesAfterMidnight()
	{
		return timeOfDay.total_milliseconds() / 60000.0;
	}

	void Lighting::setMinutesAfterMidnight(double value)
	{
		setTime(boost::posix_time::seconds(value * 60.0));
	}

	void Lighting::onChildAdded(Instance* child)
	{
		Sky* newSky = dynamic_cast<Sky*>(child);

		if (newSky)
		{
			sky = shared_from(newSky);

			fireLightingChanged(true);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::onChildRemoving(Instance* child)
	{
		if (sky.get() == child)
		{
			sky.reset();

			fireLightingChanged(true);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::onChildChanged(Instance* instance, const PropertyChanged& event)
	{
		Instance::onChildChanged(instance, event);
		if (sky.get() == instance)
		{
			fireLightingChanged(true);

			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	bool Lighting::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const Sky*>(instance) != NULL;
	}
}
