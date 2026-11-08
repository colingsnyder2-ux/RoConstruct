#include "tool/Dragger.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
void __cdecl movePart(PartInstance*, const G3D::Vector3&);
void __cdecl applyMove(const G3D::Array<Primitive*>& parts, const G3D::Vector3& value) {
    if (value != G3D::Vector3::zero()) {
        for (int i = 0; i < parts.size(); ++i) {
            Primitive* primitive = parts[i];
            PartInstance* part = PartInstance::fromPrimitive(primitive);
            movePart(part, value);
        }
    }
}
}
