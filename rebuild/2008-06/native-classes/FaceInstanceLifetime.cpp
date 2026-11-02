#include "v8datamodel/FaceInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {
const char* sFaceInstance = "FaceInstance";
FaceInstance::FaceInstance() : face(NORM_Z_NEG) {}
bool FaceInstance::askSetParent(const Instance* instance) const {
    return dynamic_cast<const PartInstance*>(instance) != NULL;
}
}
