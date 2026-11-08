// >>> native-status (generated) -- do not edit >>>
// DebugSettingsCoordinateGetters | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 40d22561 | roc native-status --write
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
#ifndef NATIVE_DEBUGSETTINGS_PENDING
bool DebugSettings::getShowModelCoordinateFrames() const
{
    return ModelInstance::showModelCoord;
}
#endif

bool DebugSettings::getShowWorldCoordinateFrames() const
{
    return Workspace::showWorldCoord;
}
}
