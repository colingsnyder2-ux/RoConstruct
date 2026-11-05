// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_handles3d_410275e979a30584.cpp

// Candidate translation unit (score above; library headers required).
#include <AppDraw/DrawAdorn.h>
#include <AppDraw/HitTest.h>
#include <G3D/Ray.h>

namespace RBX {
// Native Adorn ray dispatch is byte offset 0x54. The older header puts ray
// at 0x50; retain the actual ray prototype without inventing the missing slot.
static inline void nativeRay(Adorn* adorn, const G3D::Ray& ray,
                             const G3D::Color4& color, float scale) {
    typedef void (__thiscall *RayMethod)(Adorn*, const G3D::Ray&, const G3D::Color4&, float);
    reinterpret_cast<RayMethod>((*reinterpret_cast<void***>(adorn))[21])(adorn, ray, color, scale);
}

const G3D::Color3& DrawAdorn::resizeColor() {
    static G3D::Color3 color(0.1f, 0.6f, 1.0f);
    return color;
}

void DrawAdorn::handles3d(const G3D::Vector3& size, const G3D::CoordinateFrame& frame,
                         Adorn* adorn, HandleType type, const G3D::Vector3& camera) {
    G3D::Vector3 halfSize = size * 0.5f;
    for (int side = 0; side < 2; ++side) {
        float sign = side < 1.0f ? -1.0f : 1.0f;
        for (int axis = 0; axis < 3; ++axis) {
            switch (type) {
            case HANDLE_RESIZE:
            case HANDLE_VELOCITY: {
                G3D::Vector3 point(0, 0, 0);
                point[axis] = (halfSize[axis] + 3.0f) * sign;
                G3D::Vector3 worldPoint = frame.pointToWorldSpace(point);
                float radius = HitTest::distanceToHandleRadius(camera, worldPoint);
                adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(worldPoint));
                adorn->sphere(G3D::Sphere(G3D::Vector3::zero(), radius), resizeColor(), G3D::Color4::clear());
                break;
            }
            case HANDLE_MOVE: {
                G3D::Ray ray;
                ray.origin[axis] = halfSize[axis] * sign;
                ray.direction[axis] = sign * 3.5f;
                G3D::Vector3 worldPoint = frame.pointToWorldSpace(ray.origin);
                float scale = HitTest::distanceToHandleRadius(camera, worldPoint) * 4.0f;
                adorn->setObjectToWorldMatrix(frame);
                nativeRay(adorn, ray, G3D::Color3::orange(), scale);
                break;
            }
            default: {
                G3D::Vector3 point(0, 0, 0);
                point[axis] = (halfSize[axis] + 4.0f) * sign;
                adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(frame.translation + point));
                cylinder(adorn, frame, 0, 1.0f, 0.5f, G3D::Color3::red());
                break;
            }
            }
        }
    }
}
}
