#include "NativeResizeToolTrial.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ICameraOwner.h"
#include "AppDraw/DrawAdorn.h"
namespace RBX {
const G3D::Color3& DrawAdorn::resizeColor() {
    static G3D::Color3 c(0.1f, 0.6f, 1.0f);
    return c;
}
void ResizeTool::render3dAdorn(Adorn* adorn) {
    ServiceClient<Selection> selection(reinterpret_cast<Instance*>(workspace));
    std::vector<boost::shared_ptr<Instance> >::const_iterator it;
    for (it = selection->selection->begin(); it != selection->selection->end(); ++it) {
        if (PartInstance* part = dynamic_cast<PartInstance*>(it->get())) {
            DrawAdorn::handles3d(part->getPartSizeXml(), part->getCoordinateFrame(), adorn, HANDLE_RESIZE,
                reinterpret_cast<ICameraOwner*>(reinterpret_cast<char*>(workspace) + 0x288)->getGCamera().getCoordinateFrame().translation);
        }
    }
}
void ResizeTool::render2d(Adorn* adorn) {
    ServiceClient<Selection> selection(reinterpret_cast<Instance*>(workspace));
    std::vector<boost::shared_ptr<Instance> >::const_iterator it;
    for (it = selection->selection->begin(); it != selection->selection->end(); ++it) {
        if (PartInstance* part = dynamic_cast<PartInstance*>(it->get())) {
            DrawAdorn::handles2d(part->getPartSizeXml(), part->getCoordinateFrame(),
                reinterpret_cast<ICameraOwner*>(reinterpret_cast<char*>(workspace) + 0x288)->getGCamera(), adorn, DrawAdorn::resizeColor());
        }
    }
}
}

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

#include "../../../tools/rbxgs/Client/App/roc_native_rect_center_f0523507542fe513.cpp"
namespace RBX {
void DrawAdorn::handles2d(const G3D::Vector3& size, const G3D::CoordinateFrame& frame,
                         const G3D::GCamera& camera, Adorn* adorn, const G3D::Color3& color) {
    G3D::Vector3 halfSize = size * 0.5f;
    for (int side = 0; side < 2; ++side) {
        float sign = side < 1.0f ? -1.0f : 1.0f;
        for (int axis = 0; axis < 3; ++axis) {
            G3D::Vector3 point(0, 0, 0);
            point[axis] = (halfSize[axis] + 3.0f) * sign;
            G3D::Vector2 screen = camera.project(frame.pointToWorldSpace(point), adorn->getViewport()).xy();
            adorn->rect2d(Rect::fromCenterSize(screen, 6.0f).toRect2D(), color);
        }
    }
}
}
