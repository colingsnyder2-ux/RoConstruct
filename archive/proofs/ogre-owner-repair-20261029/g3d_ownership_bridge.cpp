#include <G3D/ReferenceCount.h>
#include <stdio.h>

int destroyed = 0;
class TrackedResource : public G3D::ReferenceCountedObject {
public:
    ~TrackedResource() { ++destroyed; }
};

extern "C" int g3d_ownership_smoke() {
    G3D::ReferenceCountedPointer<G3D::ReferenceCountedObject> owner(new TrackedResource);
    G3D::WeakReferenceCountedPointer<G3D::ReferenceCountedObject> weak(owner);
    {
        G3D::ReferenceCountedPointer<G3D::ReferenceCountedObject> copy(owner);
        if (weak.createStrongPtr().isNull() || copy.pointer() != owner.pointer()) return 1;
    }
    if (destroyed != 0 || weak.createStrongPtr().isNull()) return 2;
    owner = static_cast<G3D::ReferenceCountedObject*>(0);
    if (destroyed != 1 || weak.createStrongPtr().notNull()) return 3;
    puts("G3D native ownership: weak reference cleared, exactly one destruction");
    return 0;
}
