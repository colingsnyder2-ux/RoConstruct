#include "v8datamodel/Camera.h"
#include "v8datamodel/ICharacterSubject.h"
namespace RBX {
bool Camera::isFirstPersonCamera() const {
    ICameraSubject* subject = cameraSubject.get() ? dynamic_cast<ICameraSubject*>(cameraSubject.get()) : 0;
    ICharacterSubject* character = dynamic_cast<ICharacterSubject*>(subject);
    if (character) return character->getCursorCenterLocked();
    return false;
}
}
