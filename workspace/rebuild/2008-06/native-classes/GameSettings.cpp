// 2008-06 native RBX::GameSettings (inactive); evidence in native-headers/v8datamodel/GameSettings.h.
// Verified by tests/record_native_settings_items.py (unit profile: document-swap flags).
// >>> native-status (generated) -- do not edit >>>
// GameSettings | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 1a7bb98a | roc native-status --write
#include "v8datamodel/GameSettings.h"
#include <G3D/format.h>
#include <boost/thread/recursive_mutex.hpp>
#include <stdexcept>

namespace RBX
{
	const char sGameSettings[] = "GameSettings"; // 00838478

	// Template members the shared headers only declare (same definitions as native-classes/NetworkSettings.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>* GlobalSettingsItem<Class, ClassName>::sing = NULL; // 0096dd10

	// 005bf580: the 2008 item names itself after its class and refuses a second instance.
	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>::GlobalSettingsItem()
	{
		setName(ClassName);
		if (sing)
			throw std::runtime_error(G3D::format("singleton %s already exists", ClassName));
		sing = this;
	}

	// 005bf1f0 (deleting 005bf7e0).
	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>::~GlobalSettingsItem()
	{
		sing = NULL;
	}

	// 0044bee0 (emitted with the application module that first asks for the item): create the item on first use and
	// parent it to the GlobalSettings service; the item's constructor publishes itself through sing.
	template<typename Class, const char* ClassName>
	Class& GlobalSettingsItem<Class, ClassName>::singleton()
	{
		boost::recursive_mutex::scoped_lock lock(GlobalSettings::mutex);
		if (!sing)
		{
			boost::shared_ptr<Class> item = Creatable<Instance>::create<Class>();
			item->setParent(GlobalSettings::singleton().get());
		}
		return *static_cast<Class*>(sing);
	}

	// Dynamic initializers 007f5560..007f5620, in this order (Functionality 5 = STANDARD).
	static Reflection::BoundProp<bool, 1> prop_FunnyPhysics("FunnyPhysics", "Debug", &GameSettings::funnyPhysics, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_ChatHistory("ChatHistory", "Online", &GameSettings::chatHistory, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_ChatScrollLength("ChatScrollLength", "Online", &GameSettings::chatScrollLength, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_SoundEnabled("SoundEnabled", "Sound", &GameSettings::soundEnabled, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_SoftwareSound("SoftwareSound", "Sound", &GameSettings::softwareSound, Reflection::PropertyDescriptor::STANDARD);

	GameSettings::GameSettings()
		: chatHistory(50),
		  chatScrollLength(5),
		  soundEnabled(true),
		  softwareSound(false),
		  funnyPhysics(false)
	{
		setName("Game Options");
	}
}

template RBX::GameSettings& RBX::GlobalSettingsItem<RBX::GameSettings, RBX::sGameSettings>::singleton();
