// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// PrimitiveLifetime | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 691108f5 | roc native-status --write
#undef _RELEASEASSERT
#include "v8world/Primitive.h"
#include "v8kernel/Body.h"
#include "v8world/Controller.h"

namespace RBX {
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
}
