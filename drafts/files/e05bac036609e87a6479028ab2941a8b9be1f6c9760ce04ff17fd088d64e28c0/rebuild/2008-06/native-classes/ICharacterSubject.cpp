#include "v8datamodel/ICharacterSubject.h"
namespace RBX {
G3D::CoordinateFrame ICharacterSubject::getFocusLookingAtGoal(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal)
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
