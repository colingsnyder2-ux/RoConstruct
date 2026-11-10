#include "NativeAxisMoveToolTrial.h"
#include "v8datamodel/ICameraOwner.h"
#include "util/Extents.h"
#include "AppDraw/DrawAdorn.h"
namespace RBX {
struct AxisRenderBox {
    G3D::Vector3 low; float high[3];
    AxisRenderBox() : low(G3D::Vector3::inf()) { const G3D::Vector3& v=G3D::Vector3::inf(); high[0]=-v.x; high[1]=-v.y; high[2]=-v.z; }
    G3D::Vector3 center() const { return (G3D::Vector3(high[0], high[1], high[2]) + low) * 0.5f; }
    G3D::Vector3 size() const { return G3D::Vector3(high[0], high[1], high[2]) - low; }
};
typedef char axis_render_box_size[sizeof(AxisRenderBox) == sizeof(Extents) ? 1 : -1];
void AxisMoveTool::render2d(Adorn* adorn) {
    AxisRenderBox box;
    if (bounds(reinterpret_cast<Extents&>(box))) {
        G3D::CoordinateFrame frame(box.center());
        G3D::Vector3 size = box.size();
        DrawAdorn::handles2d(size, frame,
            reinterpret_cast<ICameraOwner*>(reinterpret_cast<char*>(workspace) + 0x288)->getGCamera(), adorn, G3D::Color3::orange());
    }
}
void AxisMoveTool::render3dAdorn(Adorn* adorn) {
    AxisRenderBox box;
    if (bounds(reinterpret_cast<Extents&>(box))) {
        G3D::CoordinateFrame frame(box.center());
        G3D::Vector3 size = box.size();
        DrawAdorn::handles3d(size, frame, adorn, HANDLE_MOVE,
            reinterpret_cast<ICameraOwner*>(reinterpret_cast<char*>(workspace) + 0x288)->getGCamera().getCoordinateFrame().translation);
    }
}
}
