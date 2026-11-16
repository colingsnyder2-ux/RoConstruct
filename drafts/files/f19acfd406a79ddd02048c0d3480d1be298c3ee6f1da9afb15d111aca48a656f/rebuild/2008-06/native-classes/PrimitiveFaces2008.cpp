// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#undef _RELEASEASSERT
#include "v8world/Primitive2008.h"
#include "util/Face.h"
#include "v8kernel/Body2008.h"
namespace RBX {
Face Primitive::getFaceInObject(NormalId objectFace)
{
    G3D::Vector3 halfSize = geometry->getGridSize() * 0.5f;
    return Face::fromExtentsSide(Extents(-halfSize, halfSize), objectFace);
}
Face Primitive::getFaceInWorld(NormalId objectFace)
{
    return getFaceInObject(objectFace).toWorldSpace(body->getCoordinateFrame());
}
G3D::CoordinateFrame Primitive::getFaceCoordInObject(NormalId objectFace)
{
    G3D::Vector3 offset = normalIdToVector3(objectFace) * geometry->getGridSize();
    return G3D::CoordinateFrame(normalIdToMatrix3(objectFace), offset);
}
}
