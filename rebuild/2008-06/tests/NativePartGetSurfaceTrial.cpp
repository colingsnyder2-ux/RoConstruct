// Adapted from tools/openrbx/Client/roc_espeon_rayextents6315b1980ab637ee.cpp.
// Diagnostic-only offset overlay; complete PartInstance ABI remains unproven.

#pragma float_control(precise, off)

#include <G3D/CoordinateFrame.h>
#include <G3D/Ray.h>
#include <G3D/AABox.h>
#include <G3D/CollisionDetection.h>
namespace RBX {
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
class Surface;
typedef G3D::Vector3 Vector3;
typedef G3D::Ray Ray;
typedef G3D::AABox Box;
struct Extents {Vector3 low,high;Extents(const Vector3& a,const Vector3& b):low(a),high(b){}};
struct Primitive {
    const G3D::CoordinateFrame& getCoordinateFrame() const;
};

struct Surfaces {
    char storage[0x34];
    Surface& operator[](NormalId index);
};

struct SizeData {
    unsigned int tag;
    Vector3 size;
};

struct PartInstance {
    char padding[0x1f4];
    Surfaces faces;
    char primitiveStorage[0x9c];
    SizeData* sizeData;

    Surface* getSurface(const Ray& source, int& faceIndex);
};

Surface* PartInstance::getSurface(const Ray& source, int& faceIndex)
{
    const G3D::CoordinateFrame& frame =
        reinterpret_cast<Primitive*>(primitiveStorage)->getCoordinateFrame();
    Ray ray = frame.toObjectSpace(source);

    const Vector3& size = sizeData->size;
    float x = size.x * 0.5f;
    float y = size.y * 0.5f;
    float z = size.z * 0.5f;
    Extents bounds(Vector3(-x,-y,-z),Vector3(x,y,z));
    const Vector3& low=bounds.low;
    const Vector3& high=bounds.high;
    Vector3 point(0.0f, 0.0f, 0.0f);

    G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox(ray.origin, ray.direction, Box(low, high), point);

    for (int i = 0; i < 3; ++i) {
        if (reinterpret_cast<float*>(&point)[i] ==
            reinterpret_cast<const float*>(&high)[i]) {
            faceIndex = i;
            return &faces[static_cast<NormalId>(i)];
        }
        if (reinterpret_cast<float*>(&point)[i] ==
            reinterpret_cast<const float*>(&low)[i]) {
            faceIndex = i + 3;
            return &faces[static_cast<NormalId>(i + 3)];
        }
    }
    return 0;
}
}
