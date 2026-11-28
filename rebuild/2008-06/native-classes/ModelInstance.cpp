// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/ModelInstance.h"
#include "humanoid/Humanoid2008.h"   // Humanoid::modelIsCharacter 005d9a20 (getCameraIgnorePrimitives 00583570)
namespace RBX {
// Free function of the drag-utilities unit (defined in native-classes/DragPrimitiveBounds.cpp; identity registry
// ?collectPrimitives@RBX@@YAXPBVInstance@1@AAV?$vector@PAVPrimitive@RBX@@...@Z), declared locally as in
// AppUnit57C_2008ModelInstance.cpp.
void collectPrimitives(const Instance* object, std::vector<Primitive*>& output); // 0060f340
void ModelInstance::onDescendentAdded(Instance* instance) {
    PVInstance::onDescendentAdded(instance);
    LocalGridExtents.setDirty();
    WorldGridExtents.setDirty();
    FlagHeight.setDirty();
    if (instance == (Instance*)candidatePrimaryPart.get()) {
        candidatePrimaryPart.reset();
        updatePrimaryPart((PartInstance*)instance);
    }
    shouldRenderSetDirty();
}
void ModelInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance) {
    if (primaryPart == (PartInstance*)instance.get()) primaryPart = 0;
    if (candidatePrimaryPart.get() == (PartInstance*)instance.get()) candidatePrimaryPart.reset();
    LocalGridExtents.setDirty();
    WorldGridExtents.setDirty();
    FlagHeight.setDirty();
    shouldRenderSetDirty();
    PVInstance::onDescendentRemoving(instance);
}
// 00583570 (registry placeholder func_00583570; ICameraSubject slot of the +0x29c subobject, `lea esi, [ecx - 0x29c]`,
// ret 4). Its vtordisp thunks 005849d0 (ModelInstance), 00590790 (RootInstance, -0x60) and 005a2c90 (Workspace, -0x1b8)
// are compiler-emitted with the vtables. Donor tools/rbxgs v8datamodel/ModelInstance.cpp shape
// (DragUtilities::getPrimitivesConst, then the character's Humanoid), with the 2008 callees: 0060f340 (cdecl, add esp 8
// with the Humanoid call's argument) and Humanoid::modelIsCharacter 005d9a20 instead of findFirstChildOfType<Humanoid>,
// then the donor's humanoid->getIgnorePrims (ICharacterSubject +0x14c slot 7 of vtable 0083d388: 005db9e0).
// INFERRED: 0060f340 is the one body the binary has for both vector<Primitive*> and vector<const Primitive*> (same
// vector layout; the registry names it collectPrimitives), so the const vector is passed through a reinterpret_cast.
void ModelInstance::getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives) {
    collectPrimitives(this, reinterpret_cast<std::vector<Primitive*>&>(primitives));
    if (Humanoid* humanoid = Humanoid::modelIsCharacter(this))
        humanoid->getIgnorePrims(primitives);
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::ComputeProp<RBX::Extents,RBX::ModelInstance>;
