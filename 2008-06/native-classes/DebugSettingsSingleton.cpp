// >>> native-status (generated) -- do not edit >>>
// DebugSettingsSingleton | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 0f789944 | roc native-status --write
#include "v8datamodel/DebugSettings.h"
#include <boost/thread/recursive_mutex.hpp>
namespace RBX {
template<typename Class, const char* ClassName>
Class& GlobalSettingsItem<Class,ClassName>::singleton() {
    boost::recursive_mutex::scoped_lock lock(GlobalSettings::mutex);
    if (!sing) {
        boost::shared_ptr<Class> item = Creatable<Instance>::create<Class>();
        item->setParent(GlobalSettings::singleton().get());
    }
    return *static_cast<Class*>(sing);
}
template DebugSettings& GlobalSettingsItem<DebugSettings,sDebugSettings>::singleton();
}
