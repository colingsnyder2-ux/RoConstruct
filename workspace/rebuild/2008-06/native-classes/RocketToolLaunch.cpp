// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// RocketToolLaunch | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src cd7bca0f | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ShootTools.h"
namespace RBX {
PV RocketTool::launch(const UIEvent& event, const G3D::CoordinateFrame& frame) {
    G3D::Vector3 hit;
    G3D::Vector3 forward = getPart(event, 0, hit) ? (hit-frame.translation).direction() : frame.lookVector();
    G3D::CoordinateFrame result;
    result.lookAt(forward);
    G3D::Vector3 position;
    position = forward;
    position *= 5.0f;
    position += frame.translation;
    result.translation = position;
    return PV(result, Velocity::zero());
}
}
