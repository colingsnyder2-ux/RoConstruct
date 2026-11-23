// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native (inactive): template instances the donor-free boot of CRobloxApp::InitInstance reaches first:
// FactoryProduct<CRenderSettings, GlobalSettings::Item>::FactoryProduct (base-class ctor of 00448c60) and
// GlobalSettingsItem<NetworkSettings>::singleton (0049e890; same body as the DebugSettings/GameSettings/CRenderSettings ones).
#include "../native-headers/CRenderSettings.h"
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
