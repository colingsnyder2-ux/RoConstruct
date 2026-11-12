// 2008-06 native rows of the application range 00404000..00408000 (inactive): Roblox template instances that the
// ATL COM unit of CApp (00405da0..0040995f) emits. Verified by tests/record_native_app_unit404.py (document-swap
// flags, VS2008 RTM 21022). Only committed native headers are included, read-only; no declaration is added.
#include "v8datamodel/DebugSettings.h"
#include "v8tree/Instance.h"
#include "util/Object.h"

namespace RBX
{
	// 00407be0: GlobalSettingsItem<DebugSettings>::singleton. Same body as the GameSettings instance 0044bee0
	// (native-classes/GameSettings.cpp): lock GlobalSettings::mutex (do_lock 00563090 / do_unlock 005630e0 on
	// 00974aa0), test sing (0096c318), create the item through Creatable<Instance>::create<DebugSettings> (00407820)
	// and parent it to GlobalSettings::singleton() (005690f0) with setParent (0055a8f0).
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
}

template RBX::DebugSettings& RBX::GlobalSettingsItem<RBX::DebugSettings, RBX::sDebugSettings>::singleton();

// 00405da0: AbstractFactoryProduct<Instance>::getCreators (util/Object.h inline body; the function-local map
// 0096c2b4 with guard bit 0096c2d4, the _Tree constructor 00446110 and the atexit 006a17af of its destructor 007fa0a0).
template std::map<const RBX::Name*, const RBX::ICreator*>& RBX::AbstractFactoryProduct<RBX::Instance>::getCreators();
