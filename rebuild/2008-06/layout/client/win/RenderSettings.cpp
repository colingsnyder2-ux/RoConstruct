#include "CRenderSettings.h"
#include "Network/NetworkSettings.h"
#include <boost/thread/recursive_mutex.hpp>

namespace RBX {
template<class C, class D, const char* N>
FactoryProduct<C,D,N>::FactoryProduct() : D() {}
template FactoryProduct<CRenderSettings, GlobalSettings::Item, sRenderSettings>::FactoryProduct();

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
template NetworkSettings& GlobalSettingsItem<NetworkSettings, sNetworkSettings>::singleton();
}
