// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_unit_00fd3441d97d4838.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Lighting.h"
#include "util/RunStateOwner.h"

namespace RBX
{
	const char* sLighting = "Lighting";

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

	Lighting::Lighting()
		: Base(),
		  ambientTop(209/255.0f, 208/255.0f, 217/255.0f),
		  ambientBottom(122/255.0f, 134/255.0f, 120/255.0f),
		  hasSky(true),
		  clearColor(G3D::Color3::white()),
		  timeOfDay(boost::posix_time::duration_from_string("14:00:00"))
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
		if (value != (*reinterpret_cast<G3D::Color4*>(reinterpret_cast<char*>(this) + 0x254)))
		{
			(*reinterpret_cast<G3D::Color4*>(reinterpret_cast<char*>(this) + 0x254)) = value;

			raisePropertyChanged(desc_ClearColor);
			event_LightingChanged.fire(this ? reinterpret_cast<Reflection::SignalSource*>(reinterpret_cast<char*>(this) + 0x14) : 0, false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setLightColor(G3D::Color3 value)
	{
		if (value != (*reinterpret_cast<G3D::Color3*>(reinterpret_cast<char*>(this) + 0x28c)))
		{
			(*reinterpret_cast<G3D::Color3*>(reinterpret_cast<char*>(this) + 0x28c)) = value;

			raisePropertyChanged(desc_LightColor);
			event_LightingChanged.fire(this ? reinterpret_cast<Reflection::SignalSource*>(reinterpret_cast<char*>(this) + 0x14) : 0, false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setAmbientBottom(G3D::Color3 value)
	{
		if (value != (*reinterpret_cast<G3D::Color3*>(reinterpret_cast<char*>(this) + 0x27c)))
		{
			(*reinterpret_cast<G3D::Color3*>(reinterpret_cast<char*>(this) + 0x27c)) = value;

			raisePropertyChanged(desc_AmbientBottom);
			event_LightingChanged.fire(this ? reinterpret_cast<Reflection::SignalSource*>(reinterpret_cast<char*>(this) + 0x14) : 0, false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::setAmbientTop(G3D::Color3 value)
	{
		if (value != (*reinterpret_cast<G3D::Color3*>(reinterpret_cast<char*>(this) + 0x270)))
		{
			(*reinterpret_cast<G3D::Color3*>(reinterpret_cast<char*>(this) + 0x270)) = value;

			raisePropertyChanged(desc_AmbientTop);
			event_LightingChanged.fire(this ? reinterpret_cast<Reflection::SignalSource*>(reinterpret_cast<char*>(this) + 0x14) : 0, false);
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

		if ((*reinterpret_cast<boost::posix_time::time_duration*>(reinterpret_cast<char*>(this) + 0x268)).total_seconds() != totalSeconds)
		{
			(*reinterpret_cast<boost::posix_time::time_duration*>(reinterpret_cast<char*>(this) + 0x268)) = boost::posix_time::seconds(totalSeconds);
			(*reinterpret_cast<G3D::LightingParameters*>(reinterpret_cast<char*>(this) + 0x130)).setTime((*reinterpret_cast<boost::posix_time::time_duration*>(reinterpret_cast<char*>(this) + 0x268)).total_seconds());

			raisePropertyChanged(prop_Time);
			event_LightingChanged.fire(this ? reinterpret_cast<Reflection::SignalSource*>(reinterpret_cast<char*>(this) + 0x14) : 0, false);
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
			(*reinterpret_cast<boost::shared_ptr<Sky>*>(reinterpret_cast<char*>(this) + 0x2d4)) = shared_from(newSky);

			event_LightingChanged.fire(this ? reinterpret_cast<Reflection::SignalSource*>(reinterpret_cast<char*>(this) + 0x14) : 0, true);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::onChildRemoving(Instance* child)
	{
		if ((*reinterpret_cast<boost::shared_ptr<Sky>*>(reinterpret_cast<char*>(this) + 0x2d4)).get() == child)
		{
			(*reinterpret_cast<boost::shared_ptr<Sky>*>(reinterpret_cast<char*>(this) + 0x2d4)).reset();

			event_LightingChanged.fire(this ? reinterpret_cast<Reflection::SignalSource*>(reinterpret_cast<char*>(this) + 0x14) : 0, true);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	void Lighting::onChildChanged(Instance* instance, const PropertyChanged& event)
	{
		Instance::onChildChanged(instance, event);
		if ((*reinterpret_cast<boost::shared_ptr<Sky>*>(reinterpret_cast<char*>(this) + 0x2d4)).get() == instance)
		{
			event_LightingChanged.fire(this ? reinterpret_cast<Reflection::SignalSource*>(reinterpret_cast<char*>(this) + 0x14) : 0, true);

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
