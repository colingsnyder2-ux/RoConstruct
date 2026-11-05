// from server: 100% by EspClaude
// from server: 79% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_4b80595ed6878660.cpp

// Candidate translation unit (score above; library headers required).

#pragma float_control(precise, off)

#include <G3D/CoordinateFrame.h>
#include <G3D/Ray.h>
#include <G3D/AABox.h>
typedef G3D::Vector3 Vector3;
typedef G3D::Ray Ray;
typedef G3D::AABox Box;
struct Extents {Vector3 low,high;Extents(const Vector3& a,const Vector3& b):low(a),high(b){}};
struct SizeData {
    unsigned int tag;
    Vector3 size;
};
struct Primitive {
    char pad[0xe0];
    SizeData* sizeData;
    const G3D::CoordinateFrame& getValue();
};

struct Faces {
    char storage[0x34];
    int get(int index);
};

extern float halfScale;
extern float collisionTime;
extern bool collisionInside;

extern void __cdecl collide(
    const Vector3& origin,
    const Vector3& direction,
    const Box& box,
    Vector3& point,
    float& time,
    bool& inside);

struct S {
    char padding[0x118];
    Primitive* primitive;
    char padding2[0x134-0x11c];
    Faces faces;

    int f(const Ray& source, int* faceIndex);
};

int S::f(const Ray& source, int* faceIndex)
{
    const G3D::CoordinateFrame& frame =
        primitive->getValue();
    Ray ray = frame.toObjectSpace(source);

    const Vector3& size = primitive->sizeData->size;
    float x = size.x * halfScale;
    float y = size.y * halfScale;
    float z = size.z * halfScale;
    Extents bounds(Vector3(-x,-y,-z),Vector3(x,y,z));
    const Vector3& low=bounds.low;
    const Vector3& high=bounds.high;
    Vector3 point(0.0f, 0.0f, 0.0f);

    collide(ray.origin, ray.direction, Box(low, high), point,
            collisionTime, collisionInside);

    for (int i = 0; i < 3; ++i) {
        if (reinterpret_cast<float*>(&point)[i] ==
            reinterpret_cast<const float*>(&high)[i]) {
            *faceIndex = i;
            return faces.get(i);
        }
        if (reinterpret_cast<float*>(&point)[i] ==
            reinterpret_cast<const float*>(&low)[i]) {
            *faceIndex = i + 3;
            return faces.get(i + 3);
        }
    }
    return 0;
}
