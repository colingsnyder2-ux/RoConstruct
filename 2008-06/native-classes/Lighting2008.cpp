// 2008-06 native RBX::Lighting (inactive); evidence in native-headers/v8datamodel/Lighting2008.h.
// Verified by tests/record_native_lighting2008.py. Original unit 005df0c0..005e2760 (constructor 005e1a40,
// destructor 005e1d60); classDescriptor 005e1100, doDeclare 004ab0f0.
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
