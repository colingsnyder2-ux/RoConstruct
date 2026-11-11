// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/draw-handles
// >>> native-status (generated) -- do not edit >>>
// ResizeToolRender | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 328a11d0 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ResizeTool.h"
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
    ServiceClient<Selection> selection(static_cast<Instance*>(workspace));
    std::vector<boost::shared_ptr<Instance> >::const_iterator it;
    for (it = selection->selection->begin(); it != selection->selection->end(); ++it) {
        if (PartInstance* part = dynamic_cast<PartInstance*>(it->get())) {
            DrawAdorn::handles3d(part->getPartSizeXml(), part->getCoordinateFrame(), adorn, HANDLE_RESIZE,
                workspace->getGCamera().getCoordinateFrame().translation);
        }
    }
}
void ResizeTool::render2d(Adorn* adorn) {
    ServiceClient<Selection> selection(static_cast<Instance*>(workspace));
    std::vector<boost::shared_ptr<Instance> >::const_iterator it;
    for (it = selection->selection->begin(); it != selection->selection->end(); ++it) {
        if (PartInstance* part = dynamic_cast<PartInstance*>(it->get())) {
            DrawAdorn::handles2d(part->getPartSizeXml(), part->getCoordinateFrame(),
                workspace->getGCamera(), adorn, DrawAdorn::resizeColor());
        }
    }
}
}

#include <AppDraw/DrawAdorn.h>
#include <AppDraw/HitTest.h>
#include <G3D/Ray.h>
#include "util/Rect.h"
namespace RBX {
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
                adorn->ray(ray, G3D::Color3::orange(), scale);
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
