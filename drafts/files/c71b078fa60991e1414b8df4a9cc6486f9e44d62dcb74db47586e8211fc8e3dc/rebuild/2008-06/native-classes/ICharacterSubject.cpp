// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/ICharacterSubject.h"
namespace RBX {
// Original goalFromDistance calls this helper at 00641293.
__declspec(noinline) G3D::CoordinateFrame ICharacterSubject::getFocusLookingAtGoal(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal)
{
    G3D::CoordinateFrame temp = cameraFocus;
    temp.lookAt(cameraGoal.translation);
    return temp;
}
G3D::CoordinateFrame ICharacterSubject::goalFromDistance(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal, const float distance)
{
    G3D::CoordinateFrame manLookCamera = getFocusLookingAtGoal(cameraFocus, cameraGoal);
    G3D::Vector3 newCameraPt = manLookCamera.lookVector() * distance + manLookCamera.translation;
    return G3D::CoordinateFrame(G3D::Matrix3::identity(), newCameraPt);
}
}
