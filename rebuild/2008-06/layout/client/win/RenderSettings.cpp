// =============================================================================
// RenderSettings.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/RenderSettings.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "CRenderSettings.h"
#include "Network/NetworkSettings.h"
#include <boost/thread/recursive_mutex.hpp>

namespace RBX
{
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
