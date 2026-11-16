// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#undef _RELEASEASSERT
#include "v8world/Primitive2008.h"
#include "util/Face.h"
#include "v8world/Controller.h"
#include "v8kernel/Constants.h"
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
Contact* Primitive::getFirstContact() {
    return contacts.edges.size() > 0 ? (Contact*)contacts.edges[0] : NULL;
}
void Primitive::setUnknown0x14(int value) {
    if (value != unknown0x14 && world == NULL)
        unknown0x14 = value;
}
const G3D::CoordinateFrame& Primitive::getCoordinateFrame() const
{
    return body->getCoordinateFrame();
}
float Primitive::getRadius() const
{
    return geometry->getRadius();
}
void Primitive::setSurfaceType(NormalId id, SurfaceType type)
{
    if (surfaceType[id] != type)
        surfaceType[id] = type;
}
float Primitive::computeJointK() const
{
    Geometry::GeometryType type = geometry->getGeometryType();
    return Constants::getJointK(geometry->getGridSize(), type == Geometry::GEOMETRY_BALL);
}
void Primitive::setGuid(const Guid& value)
{
    guid.copyDataFrom(value);
    guidSetExternally = true;
}
void Primitive::setClump(Clump* value)
{
    if (value != clump)
        clump = value;
}
Extents Primitive::computeFuzzyExtents() const
{
    Extents ext = Extents::fromCenterCorner(body->getPV().position.translation,
        geometry->getCenterToCorner(body->getPV().position.rotation));
    ext.expand(0.01f);
    return ext;
}
const Extents& Primitive::getFastFuzzyExtents() const
{
    if (fuzzyExtentsStateId != body->getStateIndex()) {
        fuzzyExtents = computeFuzzyExtents();
        fuzzyExtentsStateId = body->getStateIndex();
    }
    return fuzzyExtents;
}
void Primitive::setController(Controller* value)
{
    if (!value)
        value = NullController::getStaticNullController();
    if (controller != value)
        controller = value;
}
}
