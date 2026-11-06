// Compile-only ABI observer. Never linked into the client.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/workspace-camera
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ICameraOwner.h"
#include "v8datamodel/Camera.h"

typedef char NativeCameraSize[sizeof(RBX::Camera) == 0x1e8 ? 1 : -1];

extern "C" RBX::ICameraOwner* workspaceCameraOwner(RBX::Workspace* workspace) {
    return workspace;
}

extern "C" const G3D::GCamera& workspaceCameraProjection(const RBX::Camera* camera) {
    return camera->getGCamera();
}
