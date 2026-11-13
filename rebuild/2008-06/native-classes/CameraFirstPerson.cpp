// >>> native-status (generated) -- do not edit >>>
// CameraFirstPerson | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by atomic.potato (ntech:deepseek-flash)
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
