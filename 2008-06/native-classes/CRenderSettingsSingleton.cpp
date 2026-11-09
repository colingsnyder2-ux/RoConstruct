// >>> native-status (generated) -- do not edit >>>
// CRenderSettingsSingleton | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 1983bb3e | roc native-status --write
#include "CRenderSettings.h"
#include <boost/thread/recursive_mutex.hpp>

namespace RBX {
template<typename Class, const char* ClassName>
Class& GlobalSettingsItem<Class, ClassName>::singleton()
{
    boost::recursive_mutex::scoped_lock lock(GlobalSettings::mutex);
    if (!sing) {
        boost::shared_ptr<Class> item = Creatable<Instance>::create<Class>();
        item->setParent(GlobalSettings::singleton().get());
    }
    return *static_cast<Class*>(sing);
}
}

template CRenderSettings& RBX::GlobalSettingsItem<CRenderSettings, sRenderSettings>::singleton();
