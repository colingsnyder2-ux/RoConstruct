// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// PrimitiveLifetime | 2008-06 | draft (no current byte proof)
// 0/6 mapped addresses byte-exact | 6 unproved | no mapped strings | by tester (+3) (mixed 3)
// <<< native-status | src b9d389d5 | roc native-status --write
#undef _RELEASEASSERT
#include "v8world/Primitive.h"
#include "v8kernel/Body.h"
#include "v8world/Controller.h"

namespace RBX {
void newTouch(Primitive* touch, Primitive* touchOther);

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

// 005e82c0. PARKED on a header layout, not the body: the compiled code is the original sequence (body +0xa0,
// Body::updatePV 00599360 through the getPV inline, lea eax,[body+pv]) except the donor v8kernel/Body.h puts pv at
// +0x88 while the 2008-06 Body has it at +0x94 (Body2008.h: updatePV 00599360 / setCoordinateFrame 00614400).
// Body2008.h cannot be included next to the donor Primitive.h (Edge.h -> Kernel.h reaches the donor Body.h).
const G3D::CoordinateFrame& Primitive::getCoordinateFrame() const
{
    return body->getPV().position;
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
