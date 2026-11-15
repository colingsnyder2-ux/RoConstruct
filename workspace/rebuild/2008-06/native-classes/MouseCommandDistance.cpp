// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "humanoid/Humanoid.h"
namespace RBX {
float MouseCommand::distanceFromCharacter(const G3D::Vector3& point) const
{
    PartInstance* head = Humanoid::getLocalHeadFromContext(workspace);
    if (head) return (head->getCoordinateFrame().translation - point).magnitude();
    return 0.0f;
}
bool MouseCommand::characterCanReach(const G3D::Vector3& point) const
{
    return Humanoid::getLocalHeadFromContext(workspace) && distanceFromCharacter(point) < 60.0;
}
}
