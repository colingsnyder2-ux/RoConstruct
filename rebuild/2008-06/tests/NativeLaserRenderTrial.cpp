#include "NativeLaserTrial.h"
#include "RbxGraphics/Adorn.h"
namespace RBX {
void LaserTool::render3dAdorn(Adorn* adorn) {
 if (frames>0) {
  --frames;
  adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());
  G3D::Color4 color(G3D::Color3::red(),1.0f);
  adorn->lineSegment(G3D::LineSegment::fromTwoPoints(origin,target), color,5.0f);
 }
}
}
