// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_part_grouped_tail_constructor_9b19d0716f31ff52.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_part_instance_guid_decl_2b7e2a3e9ffcb726.cpp")
#include <roc_part_primitive_decl_probe_7140c279266668c9.cpp>
#include <roc_part_grouped_tail_decl_25cfdd3b306c5d60.cpp>

namespace RBX {
// Native00554270, Guid::getLocalScope(), cdecl0 returning const Name&.
const Name& partLocalScope();
PartInstance::PartInstance()
 : Base("Part"), partType(Part::BLOCK_PART), formFactor(BRICK),
   color(BrickColor::lego_194), transparency(0.0f), reflectance(0.0f), locked(false),
   surfaces(this), renderImportance(0.0f), primitive(Geometry::GEOMETRY_BLOCK),
   myWorld(NULL), alphaModifier(1.0f),
   PersistentPart(this,&PartInstance::computePersistentPart),
   SurfacesNeedAdorn(this,&PartInstance::computeSurfacesNeedAdorn)
{
 primitive.setSurfaceType(NORM_Y,STUDS);
 primitive.setSurfaceType(NORM_Y_NEG,INLET);
 primitive.setGridSize(G3D::Vector3(4.0f,1.2f,2.0f));
 primitive.setFriction(0.3f);
 primitive.setElasticity(0.5f);
 primitive.setAnchor(false);
 primitive.setCanSleep(false);
 primitive.setOwner(this);
 registerGuid();
 primitive.setGuid(getGuid());
}
typedef char primitive_target_size[sizeof(Primitive)==0xfc?1:-1];
typedef char part_target_size[sizeof(PartInstance)==0x404?1:-1];
}
