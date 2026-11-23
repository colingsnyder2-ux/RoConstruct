// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
#undef _RELEASEASSERT
// NATIVE_PRIMITIVE_NATIVE_BODY (batch 14): the part-embedded Primitive.h reaches native-headers/v8kernel/Body2008.h
// (0xdc, pv +0x94) instead of the donor v8kernel/Body.h (pv +0x88); Contact / Joint come from the native
// v8world/Contact2008.h / Joints2008.h (Edge on IPipelined2008.h) for the rbx_static_casts below, and Constants from
// v8kernel/Constants.h (formerly reached through the donor kernel headers).
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8world/Primitive.h"
#include "v8world/Contact2008.h"
#include "v8world/Joints2008.h"
#include "v8kernel/Constants.h"
#include "v8world/Controller.h"

namespace RBX {
void newTouch(Primitive* touch, Primitive* touchOther);

// 0097abc1 (.bss byte, zero-initialised): donor Primitive::disableSleep; readers SleepStage::computeAssemblyState 0064a795
// and 0064a95a. It sits right before the Primitive-unit statics from 0097abc4.
bool Primitive::disableSleep = false;

// 005e8770 (new Body: 0xdc and Body() 006149c0 with the 2008 Body of Body2008.h).
Primitive::Primitive(Geometry::GeometryType geometryType)
    : guidSetExternally(false), edgeVersion(1), contacts(this), joints(this),
      worldIndex(-1), traverseId(-1), world(NULL), clump(NULL), clumpDepth(-1),
      spatialNodes(NULL), fuzzyExtentsStateId(-2), geometry(newGeometry(geometryType)),
      body(new Body), myOwner(NULL), dragging(false), anchored(false),
      jointAnchored(false), canSleep(false), canCollide(true), friction(0.0f),
      elasticity(0.75f), controller(NullController::getStaticNullController()),
      JointK(this, &Primitive::computeJointK)
{
    for (int i = 0; i < 6; i++) {
        surfaceType[i] = NO_SURFACE;
        surfaceData[i] = NULL;
    }
}

Primitive::~Primitive()
{
    Geometry::GeometryType type = geometry->getGeometryType();
    if (type != Geometry::GEOMETRY_NONE) {
        delete geometry;
        delete body;
    }
    for (int i = 0; i < 6; i++)
        delete surfaceData[i];
}

Contact* Primitive::getFirstContact()
{
    return contacts.edges.size() > 0 ? rbx_static_cast<Contact*>(contacts.edges[0]) : NULL;
}

Joint* Primitive::getFirstJoint() const
{
    return joints.edges.size() > 0 ? rbx_static_cast<Joint*>(joints.edges[0]) : NULL;
}

Edge* Primitive::getFirstEdge() const
{
    return joints.edges.size() > 0 ? joints.edges[0] : (contacts.edges.size() > 0 ? contacts.edges[0] : NULL);
}

// 005e82c0: body +0xa0, Body::updatePV 00599360 through the getPV inline, lea eax,[body+pv] with the 2008 pv +0x94
// (Body2008.h: updatePV 00599360 / setCoordinateFrame 00614400), reached through NATIVE_PRIMITIVE_NATIVE_BODY.
const G3D::CoordinateFrame& Primitive::getCoordinateFrame() const
{
    return body->getPV().position;
}

// 005e7980 (registry func_005e7980; openrbx Primitive::computeFuzzyExtents, only caller getFastFuzzyExtents 005e7a50):
// two getCoordinateFrame inlines (updatePV 00599360 twice), geometry (+0x9c) slot 5 getCenterToCorner, expand(0.01f
// 0082748c). NEAR MISS (197 B, same size): only the x87 operand order of the three c + r adds differs (target x: r + c,
// y/z: c + r); writing r + c, a named corner local, or a file-local helper did not change it (batch 43, parked).
Extents Primitive::computeFuzzyExtents() const
{
    const G3D::Matrix3& rotation = body->getCoordinateFrame().rotation;
    const G3D::Vector3& translation = body->getCoordinateFrame().translation;

    Extents extents = Extents::fromCenterCorner(translation, geometry->getCenterToCorner(rotation));
    extents.expand(0.01f);

    return extents;
}

// 005e7a50 (registry func_005e7a50; openrbx Primitive::getFastFuzzyExtents): fuzzyExtents +0x80, stateId +0x98.
const Extents& Primitive::getFastFuzzyExtents() const
{
    if (fuzzyExtentsStateId != body->getStateIndex()) {
        fuzzyExtents = computeFuzzyExtents();
        fuzzyExtentsStateId = body->getStateIndex();
    }

    return fuzzyExtents;
}

// 005e7f20 (registry func_005e7f20; openrbx Primitive::hitTest, caller ContactManager::getSlowHit 0060ced0):
// CoordinateFrame::toObjectSpace(Ray) 00518970, geometry slot 8 hitTest, pointToWorldSpace 004766a0.
bool Primitive::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint, bool& inside)
{
    G3D::Ray localRay = body->getCoordinateFrame().toObjectSpace(worldRay);
    G3D::Vector3 localHitPoint;

    if (geometry->hitTest(localRay, localHitPoint, inside)) {
        worldHitPoint = body->getCoordinateFrame().pointToWorldSpace(localHitPoint);
        return true;
    }

    return false;
}

void Primitive::onNewTouch(Primitive* p0, Primitive* p1)
{
    newTouch(p0, p1);
    newTouch(p1, p0);
}

void Primitive::setController(Controller* _controller)
{
    if (!_controller)
        _controller = NullController::getStaticNullController();

    if (controller != _controller)
        controller = _controller;
}

float Primitive::computeJointK() const
{
    Geometry::GeometryType type = geometry->getGeometryType();
    return Constants::getJointK(geometry->getGridSize(), type == Geometry::GEOMETRY_BALL);
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::Array<RBX::Edge *>;
