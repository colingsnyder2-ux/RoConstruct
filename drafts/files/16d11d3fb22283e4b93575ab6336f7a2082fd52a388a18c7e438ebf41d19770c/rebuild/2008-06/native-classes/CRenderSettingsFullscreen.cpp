// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// CRenderSettings::getFullscreenSize (00445250) - native 2008-06.
// >>> native-status (generated) -- do not edit >>>
// CRenderSettingsFullscreen | 2008-06 | draft (byte proof at 00445250)
// 1/1 mapped addresses byte-exact | no mapped strings | by colin
// <<< native-status | src a05cf324 | roc native-status --write
#include "CRenderSettings.h"

G3D::Vector2int16 CRenderSettings::getFullscreenSize() const
{
    return fullscreenSize;
}
