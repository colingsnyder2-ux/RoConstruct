// >>> native-status (generated) -- do not edit >>>
// CameraFirstPerson | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 0f65f832 | roc native-status --write
#include "v8datamodel/Camera.h"
#include "v8datamodel/ICharacterSubject.h"

namespace RBX {
bool Camera::isFirstPersonCamera() const
{
    ICameraSubject* subject = cameraSubject.get() ? dynamic_cast<ICameraSubject*>(cameraSubject.get()) : 0;
    ICharacterSubject* character = dynamic_cast<ICharacterSubject*>(subject);
    if (character) return character->getCursorCenterLocked();
    return false;
}
}
