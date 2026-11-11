// INFERRED: constructor signatures and callback spelling from unique RTTI, original calls, and byte/reference matches.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/partchunk-profile /I{headers}/part-embedded /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// ViewNewPartChunkRecovery2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src adc6d417 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include "ViewNew/PartChunk.h"
#include "RenderLib/Material2008.h"
#include "RenderLib/ViewBase2008.h"
#include "RenderLib/SceneManager2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Decal.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
namespace RBX { namespace ViewNew {
void PartChunk::invalidateMesh() {
    if (partInstance) {
        mesh = NULL;
        view->sceneManager->invalidateModel(this, partInstance->getCanAggregate());
        if (!partInstance->getCanAggregate()) {
            if (getSortValue() < 0.5f) setSortValue(0.5f);
        } else if (getSortValue() < 1.0f) setSortValue(0.0f);
    }
}
void PartChunk::invalidateMaterial() {
    if (partInstance) {
        material = NULL;
        materialInvalid = true;
        view->sceneManager->invalidateModel(this, partInstance->getCanAggregate());
        if (!partInstance->getCanAggregate()) {
            if (getSortValue() < 0.5f) setSortValue(0.5f);
        } else if (getSortValue() < 1.0f) setSortValue(0.0f);
    }
}
void PartChunk::onPropertyChanged(const Reflection::PropertyDescriptor* descriptor) {
    if (descriptor == &PartInstance::prop_Size) { invalidateMesh(); invalidateMaterial(); }
    else if (descriptor == &PartInstance::prop_Transparency) invalidateMaterial();
    else if (descriptor == &PartInstance::prop_shapeXml) invalidateMesh();
    else if (Surfaces::isSurfaceDescriptor(*descriptor)) invalidateMesh();
    else if (descriptor == &PartInstance::prop_RenderImportance) {
        setSortValue(partInstance->getRenderImportance());
        if (!partInstance->getCanAggregate()) { if (getSortValue() < 0.5f) setSortValue(0.5f); }
        else if (getSortValue() < 1.0f) setSortValue(0.0f);
    }
}

PartChunk::PartChunk(float polygonOffset, const boost::shared_ptr<PartInstance>& partInstance, ViewBase* view)
    : RenderBase::Chunk(polygonOffset), partInstance(partInstance), view(view), materialInvalid(true), specialShape(NULL)
{
    view->sceneManager->addModel(this);
    childAddedConnection = Instance::event_childAdded.connect(partInstance.get(), boost::bind(&PartChunk::onChildAdded, this, _1), 10);
    childRemovedConnection = Instance::event_childRemoved.connect(partInstance.get(), boost::bind(&PartChunk::onChildRemoved, this, _1), 10);
    ancestorChangedConnection = Instance::event_ancestryChanged.connect(partInstance.get(), boost::bind(&PartChunk::onAncestorChanged, this, _1), 10);
    propertyChangedConnection = Instance::event_propertyChanged.connect(partInstance.get(), boost::bind(&PartChunk::onPropertyChanged, this, _1), 10);
    if (partInstance) partInstance->visitChildren(boost::bind(&PartChunk::onChildAdded, this, _1));
}


Decal::Decal(RBX::Decal* decal, PartInstance* partInstance, ViewBase* view)
    : PartChunk(-0.2f, shared_from(partInstance), view), decal(shared_from(decal))
{
    decalAncestorChangedConnection = Instance::event_ancestryChanged.connect(decal, boost::bind(&Decal::onDecalAncestorChanged, this, _1), 10);
    decalPropertyChangedConnection = Instance::event_propertyChanged.connect(decal, boost::bind(&Decal::onDecalPropertyChanged, this, _1), 10);
}
Texture::Texture(RBX::Texture* decal, PartInstance* partInstance, ViewBase* view)
    : PartChunk(-0.1f, shared_from(partInstance), view), decal(shared_from(decal))
{
    textureAncestorChangedConnection = Instance::event_ancestryChanged.connect(decal, boost::bind(&Texture::onTextureAncestorChanged, this, _1), 10);
    texturePropertyChangedConnection = Instance::event_propertyChanged.connect(decal, boost::bind(&Texture::onTexturePropertyChanged, this, _1), 10);
}

void PartChunk::onSpecialShapeChanged() { invalidateMesh(); invalidateMaterial(); }
} }
