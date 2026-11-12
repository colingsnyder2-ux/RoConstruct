// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// DebugSettings::getShowModelCoordinateFrames (00563150) and getShowWorldCoordinateFrames (00563160) - native 2008-06.
// >>> native-status (generated) -- do not edit >>>
// DebugSettingsCoordinateGetters | 2008-06 | draft (byte proof at 00563150, 00563160)
// 2/2 mapped addresses byte-exact | no mapped strings | by colin
// <<< native-status | src 40d22561 | roc native-status --write
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
bool DebugSettings::getShowModelCoordinateFrames() const
{
    return ModelInstance::showModelCoord;
}

bool DebugSettings::getShowWorldCoordinateFrames() const
{
    return Workspace::showWorldCoord;
}
}
