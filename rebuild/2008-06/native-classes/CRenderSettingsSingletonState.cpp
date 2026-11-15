#include "CRenderSettings.h"

namespace RBX {
template<> GlobalSettingsItem<CRenderSettings, sRenderSettings>*
GlobalSettingsItem<CRenderSettings, sRenderSettings>::sing = NULL;
}
