// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
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

// 00599f80 (registry ?fromPrimitive@PartInstance@RBX@@SAPAV12@PAVPrimitive@2@@Z): Primitive myOwner +0xa4 is the
// IMoving base at PartInstance +0x1c0. Defined here so that primitivesToParts 0059b810 inlines it, as the original
// does (0059b849..0059b858). NOTE: native-classes/AppUnit598PartInstance.cpp builds the same address under the name
// fromPrimitiveConst (reported for review).
PartInstance* PartInstance::fromPrimitive(Primitive* p)
{
    if (p)
        return static_cast<PartInstance*>(p->getOwner());
    else
        return NULL;
}

// 0059b810 (registry func_0059b810; caller 005a2580): openrbx PartInstance::primitivesToParts. shared_from 00618a40,
// G3D::Array<shared_ptr<PartInstance> >::append 0059b310 -> resize 0059a200 -> realloc 00599bc0.
void PartInstance::primitivesToParts(const G3D::Array<Primitive*>& primitives, G3D::Array<boost::shared_ptr<PartInstance> >& parts)
{
    for (int i = 0; i < primitives.size(); i++) {
        PartInstance* part = fromPrimitive(primitives[i]);
        parts.append(shared_from(part));
    }
}

#ifndef NATIVE_PART_INSTANCE_EXTERNAL_DESTRUCTOR
PartInstance::~PartInstance() {}
#endif
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::ComputeProp<RBX::Part,RBX::PartInstance>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *> >;
template class std::vector<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *,std::allocator<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *> >;
