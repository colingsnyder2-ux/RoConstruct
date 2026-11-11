// >>> native-status (generated) -- do not edit >>>
// FaceInstanceLifetime | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 68ca1bfa | roc native-status --write
#include "v8datamodel/FaceInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {
char sFaceInstance[] = "FaceInstance";
FaceInstance::FaceInstance() : face(NORM_Z_NEG) {}
bool FaceInstance::askSetParent(const Instance* instance) const {
    return dynamic_cast<const PartInstance*>(instance) != NULL;
}
}
