// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "StandardVerbs.h"
#include "util/Math.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ICameraOwner.h"

namespace RBX {
G3D::Matrix3 TiltSelectionVerb::getRotationAxis()
{
    return Math::matrixTiltQuadrant(Math::toYAxisQuadrant(workspace->getGCamera().getCoordinateFrame()));
}
}
