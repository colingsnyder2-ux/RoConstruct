// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/workspace-camera
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"

namespace RBX {
Camera* Workspace::getCamera() const {
    return currentCamera ? currentCamera.get() : cameraTemplate.get();
}

const G3D::GCamera& Workspace::getGCamera() const {
    return getCamera()->getGCamera();
}
}
