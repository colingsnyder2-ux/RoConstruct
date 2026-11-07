// >>> native-status (generated) -- do not edit >>>
// AuthoringSettings | 2008-06 | linked
// 1/1 exact by name (100%) | 1/1 exact bodies | no strings | verified 2026-11-07| by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 9bed2929 | roc native-status --write
#include "AuthoringSettings.h"
#include <boost/thread/recursive_mutex.hpp>
#include <G3D/format.h>
#include <stdexcept>

char sAuthoringSettings[] = "Authoring";

namespace RBX {
template<typename Class, typename DerivedClass, const char* ClassName>
FactoryProduct<Class, DerivedClass, ClassName>::FactoryProduct() {}

template<typename Class, typename DerivedClass, const char* ClassName>
DescribedCreatable<Class, DerivedClass, ClassName>::DescribedCreatable() {}

template<> GlobalSettingsItem<AuthoringSettings, sAuthoringSettings>*
GlobalSettingsItem<AuthoringSettings, sAuthoringSettings>::sing = NULL;

template<typename Class, const char* ClassName>
GlobalSettingsItem<Class, ClassName>::GlobalSettingsItem()
{
    this->setName(ClassName);
    if (sing) throw std::runtime_error(G3D::format("singleton %s already exists", ClassName));
    sing = this;
}

template<> const Name& FactoryProduct<AuthoringSettings, GlobalSettings::Item, sAuthoringSettings>::getClassName() const
{
    return Name::declare<sAuthoringSettings>();
}


// 0041fcf0 (AuthoringSettings instance): create the item on first use and parent it to the
// GlobalSettings service; the item's constructor publishes itself through sing.
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

// 0040a6c0 (complete) / 0040a7c0 (deleting).
template<typename Class, const char* ClassName>
GlobalSettingsItem<Class, ClassName>::~GlobalSettingsItem()
{
    sing = NULL;
}

} // namespace RBX

template AuthoringSettings& RBX::GlobalSettingsItem<AuthoringSettings, sAuthoringSettings>::singleton();

// 0040d140.
AuthoringSettings::AuthoringSettings() : showDepricatedObjects(false), showPreliminaryObjects(true) {}
