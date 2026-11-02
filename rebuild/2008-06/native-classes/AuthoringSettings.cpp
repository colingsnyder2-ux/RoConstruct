#include "AuthoringSettings.h"
#include <boost/thread/recursive_mutex.hpp>

namespace RBX {

// 0041fcf0 (AuthoringSettings instance): create the item on first use and parent it to the
// GlobalSettings service; the item's constructor publishes itself through sing.
template<typename Class, const char** ClassName>
Class& GlobalSettingsItem<Class, ClassName>::singleton()
{
    boost::recursive_mutex::scoped_lock lock(GlobalSettings::mutex);
    if (!sing) {
        boost::shared_ptr<Class> item = Creatable<Instance>::create<Class>();
        item->setParent(GlobalSettings::singleton().get());
    }
    return *static_cast<Class*>(sing);
}

// 0040a6c0 (complete) / 0040a7c0 (deleting).
template<typename Class, const char** ClassName>
GlobalSettingsItem<Class, ClassName>::~GlobalSettingsItem()
{
    sing = NULL;
}

} // namespace RBX

template AuthoringSettings& RBX::GlobalSettingsItem<AuthoringSettings, &sAuthoringSettings>::singleton();

// 0040d140.
AuthoringSettings::AuthoringSettings() : showDepricatedObjects(false), showPreliminaryObjects(true) {}
