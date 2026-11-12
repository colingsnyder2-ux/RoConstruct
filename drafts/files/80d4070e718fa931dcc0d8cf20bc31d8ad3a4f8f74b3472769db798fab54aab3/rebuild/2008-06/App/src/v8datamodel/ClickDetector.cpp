// 2008-06 native RBX::ClickDetector (inactive); evidence in native-headers/v8datamodel/ClickDetector.h.
// Verified by tests/record_native_click_detector.py. Original unit 00629340..00629b9a, initializers
// 007f7d20..007f7d90, atexit 00800330..00800370; classDescriptor 005c02b0, doDeclare 005bf800.
// NATIVE_CLICKDETECTOR_PENDING bodies need declarations the shared headers do not have yet:
// ServiceProvider::findServiceProvider (004898d0), Instance::findFirstChildOfType<T> (006294a0), a complete
// RBX::Workspace for dynamic_cast and a native ModelInstance.h that compiles (donor Camera.h passes &sCamera);
// the recorder checks them against generated header copies (proposals).
#include "v8datamodel/ClickDetector.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"
#include "Network/Players.h"

namespace RBX
{
	char sClickDetector[] = "ClickDetector"; // 0095b3c8 (doDeclare 005bf800, classDescriptor 005c02b0)

	// Template members the shared headers only declare (same definitions as Team.cpp / Sparkles.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	// Dynamic initializers 007f7d20, 007f7d50, 007f7d90 (in this order).
	Reflection::SignalDesc<ClickDetector, void(void)> ClickDetector::event_MouseClick("MouseClick");
	static Reflection::PropDescriptor<ClickDetector, bool> desc_FrontendMouseClick("FrontendMouseClick", "Behavior", &ClickDetector::getFrontendMouseClick, &ClickDetector::setFrontendMouseClick, Reflection::PropertyDescriptor::STREAMING);
	Reflection::BoundProp<float, 1> ClickDetector::prop_MaxActivationDistance("MaxActivationDistance", "Data", &ClickDetector::maxActivationDistance, Reflection::PropertyDescriptor::STANDARD);

	ClickDetector::ClickDetector()
		: zeroInitialized(0),
		  maxActivationDistance(32.0f)
	{
		setName("ClickDetector");
	}

	ClickDetector::~ClickDetector()
	{
	}

	bool ClickDetector::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const PartInstance*>(instance) != 0 || dynamic_cast<const ModelInstance*>(instance) != 0;
	}

	void ClickDetector::setFrontendMouseClick(bool value)
	{
		if (ServiceProvider::findServiceProvider(this) && Network::Players::backendProcessing(this, true))
			event_MouseClick.fire(this);
	}

	void ClickDetector::click(PartInstance* part, float distance)
	{
		if (distance < maxActivationDistance)
		{
			frontendMouseClick = !frontendMouseClick;
			raisePropertyChanged(desc_FrontendMouseClick);
			if (Network::Players::backendProcessing(this, true))
				event_MouseClick.fire(this);
		}
	}

	bool ClickDetector::isClickable(PartInstance* part, float distance, bool raiseClickedEvent)
	{
		if (part)
		{
			Instance* instance = part;
			do
			{
				ClickDetector* detector = instance->findFirstChildOfType<ClickDetector>();
				if (detector && distance < detector->maxActivationDistance)
				{
					if (raiseClickedEvent)
						detector->click(part, distance);
					return true;
				}
				instance = instance->getParent();
			} while (instance && !dynamic_cast<Workspace*>(instance));
		}
		return false;
	}
}
