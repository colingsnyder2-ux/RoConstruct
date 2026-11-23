// =============================================================================
// Lighting.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Lighting.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Lighting2008.h"
#include "v8datamodel/Sky.h"
#include "util/RunStateOwner.h"

namespace RBX
{
	char sLighting[] = "Lighting"; // 0095442c (doDeclare 004ab0f0, classDescriptor 005e1100)

	// Template members the shared headers only declare (same definitions as ClickDetector.cpp / Tool.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	Reflection::SignalDesc<Lighting, void(bool)> Lighting::event_LightingChanged("LightingChanged", "skyboxChanged");

	static Reflection::PropDescriptor<Lighting, std::string> prop_Time(
		"TimeOfDay",
		"Data",
		&Lighting::getTimeStr,
		&Lighting::setTimeStr,
		Reflection::PropertyDescriptor::STANDARD);

	// INFERRED: the object name (desc_ShadowColor) follows the donor desc_ClearColor pattern; the binary records none.
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_ShadowColor(
		"ShadowColor",
		"Appearance",
		&Lighting::getShadowColor3,
		&Lighting::setClearColor3,
		Reflection::PropertyDescriptor::STANDARD);

	Lighting::Lighting()
		: ambientTop(209/255.0f, 208/255.0f, 217/255.0f),
		  ambientBottom(122/255.0f, 134/255.0f, 120/255.0f),
		  hasSky(true),
		  clearColor(G3D::Color3::white()),
		  shadowColor(0.7f, 0.7f, 0.72f, 1.0f),
		  timeOfDay(boost::posix_time::duration_from_string("14:00:00")),
		  colorShiftTop(0.0f, 0.0f, 0.0f),
		  colorShiftBottom(0.0f, 0.0f, 0.0f),
		  brightness(1.0f),
		  ambient(0.5f, 0.5f, 0.5f),
		  mainDiffuse(1.0f, 1.0f, 1.0f),
		  mainSpecular(1.0f, 1.0f, 1.0f),
		  fillDiffuse(1.0f, 1.0f, 1.0f),
		  fillSpecular(0.0f, 0.0f, 0.0f),
		  fillScale(1.0f, 1.0f, 1.0f)
	{
		skyParameters.lightColor = G3D::Color3(152/255.0f, 137/255.0f, 102/255.0f);
		skyParameters.setTime(timeOfDay.total_seconds());
		setName("Lighting");
	}

	bool Lighting::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const Sky*>(instance) != 0;
	}

	G3D::Vector3 Lighting::getMoonPosition()
	{
		return (skyParameters.physicallyCorrect) ? skyParameters.trueMoonPosition : skyParameters.moonPosition;
	}

	G3D::Vector3 Lighting::getSunPosition()
	{
		return (skyParameters.physicallyCorrect) ? skyParameters.trueSunPosition : skyParameters.sunPosition;
	}

	void Lighting::setShadowColor(G3D::Color4 value)
	{
		if (value != shadowColor)
		{
			shadowColor = value;

			raisePropertyChanged(desc_ShadowColor);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

#ifdef NATIVE_LIGHTING_BRIGHTNESS_PENDING
	// result. INFERRED: descriptor object name and "Appearance" category follow desc_ShadowColor above.
	static Reflection::PropDescriptor<Lighting, float> desc_Brightness(
		"Brightness",
		"Appearance",
		&Lighting::getBrightness,
		&Lighting::setBrightness,
		Reflection::PropertyDescriptor::STANDARD);

	void Lighting::setBrightness(float value)
	{
		if (value != brightness)
		{
			brightness = value;

			raisePropertyChanged(desc_Brightness);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}
#endif // NATIVE_LIGHTING_BRIGHTNESS_PENDING

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

	void Lighting::setTimeStr(const std::string& value)
	{
		setTime(boost::posix_time::duration_from_string(value));
	}

	void Lighting::setClearColor3(G3D::Color3 value)
	{
		setShadowColor(G3D::Color4(value, 1.0f));
	}

	void Lighting::setMinutesAfterMidnight(double value)
	{
		setTime(boost::posix_time::seconds(value * 60.0));
	}

#ifdef LIGHTING_HEADER_DECLARES_GEOGRAPHICLATITUDE
	static Reflection::PropDescriptor<Lighting, float> prop_GeographicLatitude(
		"GeographicLatitude",
		"Data",
		&Lighting::getGeographicLatitude,
		&Lighting::setGeographicLatitude,
		Reflection::PropertyDescriptor::STANDARD);

	float Lighting::getGeographicLatitude() const
	{
		return skyParameters.geoLatitude;
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
#endif

	void Lighting::replaceSky(Sky* newSky)
	{
		while (Sky* currentSky = findFirstChildOfType<Sky>())
		{
			currentSky->setParent(NULL);
		}

		newSky->setParent(this);
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

	template boost::shared_ptr<Lighting> Creatable<Instance>::create<Lighting>();
}

template class boost::token_iterator<boost::char_separator<char,std::char_traits<char> >,std::_String_const_iterator<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >;
template class std::_String_const_iterator<char,std::char_traits<char>,std::allocator<char> >;

#include "util/Name.h"

namespace RBX
{

G3D::Color3 Lighting::getAmbient() const
{
	return ambient;
}

}

namespace RBX
{
	// INFERRED: descriptor names and the "Appearance" category follow the donor Lighting pattern; the binary's
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_ColorShiftTop(
		"ColorShift_Top",
		"Appearance",
		&Lighting::getColorShiftTop,
		&Lighting::setColorShiftTop,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_ColorShiftBottom(
		"ColorShift_Bottom",
		"Appearance",
		&Lighting::getColorShiftBottom,
		&Lighting::setColorShiftBottom,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_Ambient(
		"Ambient",
		"Appearance",
		&Lighting::getAmbient,
		&Lighting::setAmbient,
		Reflection::PropertyDescriptor::STANDARD);

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

namespace RBX
{
std::string Lighting::getTimeStr() const
	{
		return boost::posix_time::to_simple_string(timeOfDay);
	}
}
