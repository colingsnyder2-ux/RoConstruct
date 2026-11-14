// 2008-06 native RBX::Lighting (inactive); evidence in native-headers/v8datamodel/Lighting2008.h.
// Verified by tests/record_native_lighting2008.py. Original unit 005df0c0..005e2760 (constructor 005e1a40,
// destructor 005e1d60); classDescriptor 005e1100, doDeclare 004ab0f0.
// >>> native-status (generated) -- do not edit >>>
// Lighting2008 | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
// <<< native-status | src 05533627 | roc native-status --write
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

	// Dynamic initializer 007f69b0 (the other Lighting descriptors, 007f6a50..007f6c40, are not recovered yet).
	Reflection::SignalDesc<Lighting, void(bool)> Lighting::event_LightingChanged("LightingChanged", "skyboxChanged");

	// 0097a91c, dynamic initializer 007f69d0 (??__Eprop_Time@RBX@@YAXXZ: a namespace-scope static, as in the donor
	// Lighting.cpp): PropDescriptor<Lighting, std::string> ctor 005e1170, "TimeOfDay" 0083df58 / "Data" 00822490,
	// getter getTimeStr 005e0be0, setter setTimeStr 005e2730, flags 5 (STANDARD).
	static Reflection::PropDescriptor<Lighting, std::string> prop_Time("TimeOfDay", "Data", &Lighting::getTimeStr, &Lighting::setTimeStr, Reflection::PropertyDescriptor::STANDARD);

	// 0097aa58, dynamic initializer 007f6b40: PropDescriptor<Lighting, G3D::Color3> ctor 005e12d0, "ShadowColor"
	// 0083dfe4 / "Appearance" 008329ac, getter 005df4a0, setter 005e2540, flags 5 (STANDARD).
	// INFERRED: the object name (desc_ShadowColor) follows the donor desc_ClearColor pattern; the binary records none.
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_ShadowColor("ShadowColor", "Appearance", &Lighting::getShadowColor3, &Lighting::setClearColor3, Reflection::PropertyDescriptor::STANDARD);

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

	// 005e2030: Color4 by value (ret 0x10); compares r, g, b, a with +0x254, stores, raises desc_ShadowColor 0097aa58
	// (raisePropertyChanged 0040db00), fires event_LightingChanged(false) (findSignalInstance 0056b620, signal1
	// operator() 005e1f00), then ServiceProvider::find<RunService> 004651c0 and invalidateRunViews 00555350.
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

	// 005e2570: total_seconds() (__alldiv by 1000000), modulo 86400, compared with timeOfDay.total_seconds(); stores
	// seconds(totalSeconds) as ticks (__allmul 006a16d0) at +0x268, skyParameters.setTime 007b59b0, raises prop_Time
	// 0097a91c, fires event_LightingChanged(false) and RunService::invalidateRunViews (donor body).
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

	// 005e2730: setTime(duration_from_string(value)) (str_from_delimited_time_duration 005e0c20, setTime 005e2570).
	void Lighting::setTimeStr(const std::string& value)
	{
		setTime(boost::posix_time::duration_from_string(value));
	}

	// 005e2540: by-value Color4(value, 1) (fld1 into +0xc), then setShadowColor 005e2030; ret 0xc.
	void Lighting::setClearColor3(G3D::Color3 value)
	{
		setShadowColor(G3D::Color4(value, 1.0f));
	}

	// 005e26e0 ("SetMinutesAfterMidnight" BoundFuncDesc 0097a938, initializer 007f6b10): value * 60.0 (0083df30),
	// __ftol2_sse, seconds -> ticks (__allmul by 1000000), setTime 005e2570.
	void Lighting::setMinutesAfterMidnight(double value)
	{
		setTime(boost::posix_time::seconds(value * 60.0));
	}

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

	// create<Lighting> 004adb60 (ServiceProvider::create<Lighting> reaches it).
	template boost::shared_ptr<Lighting> Creatable<Instance>::create<Lighting>();
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::token_iterator<boost::char_separator<char,std::char_traits<char> >,std::_String_const_iterator<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >;
template class std::_String_const_iterator<char,std::char_traits<char>,std::allocator<char> >;
