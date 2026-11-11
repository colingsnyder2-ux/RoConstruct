// >>> native-status (generated) -- do not edit >>>
// CRenderSettingsBase | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src d55f0f27 | roc native-status --write
#include "CRenderSettings.h"
#include <G3D/format.h>
#include <stdexcept>

char sRenderSettings[] = "RenderSettings";

namespace RBX {
template<typename Class, const char* ClassName>
GlobalSettingsItem<Class, ClassName>::GlobalSettingsItem()
{
    this->setName(ClassName);
    if (sing) throw std::runtime_error(G3D::format("singleton %s already exists", ClassName));
    sing = this;
}

template<typename Class, const char* ClassName>
GlobalSettingsItem<Class, ClassName>::~GlobalSettingsItem()
{
    sing = NULL;
}

template<> const Name& FactoryProduct<CRenderSettings, GlobalSettings::Item, sRenderSettings>::getClassName() const
{
    return Name::declare<sRenderSettings>();
}

template GlobalSettingsItem<CRenderSettings, sRenderSettings>::GlobalSettingsItem();
template GlobalSettingsItem<CRenderSettings, sRenderSettings>::~GlobalSettingsItem();
}
