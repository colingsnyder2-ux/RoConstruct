// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// PartInstanceLifetime | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 22e3bf71 | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"

namespace RBX {
PartInstance::PartInstance()
    : Base("Part"), partType(Part::BLOCK_PART), formFactor(BRICK),
      color(BrickColor::lego_194), transparency(0.0f), reflectance(0.0f), locked(false),
      surfaces(this), renderImportance(0.0f), primitive(Geometry::GEOMETRY_BLOCK),
      myWorld(NULL), alphaModifier(1.0f),
      PersistentPart(this, &PartInstance::computePersistentPart),
      SurfacesNeedAdorn(this, &PartInstance::computeSurfacesNeedAdorn)
{
    primitive.setSurfaceType(NORM_Y, STUDS);
    primitive.setSurfaceType(NORM_Y_NEG, INLET);
    primitive.setGridSize(G3D::Vector3(4.0f, 1.2f, 2.0f));
    primitive.setFriction(0.3f);
    primitive.setElasticity(0.5f);
    primitive.setAnchor(false);
    primitive.setCanSleep(false);
    primitive.setOwner(this);
    registerGuid();
    primitive.setGuid(guid);
}

PartInstance::~PartInstance() {}
}
