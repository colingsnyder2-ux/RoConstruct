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
