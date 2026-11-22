// INFERRED: constructor signatures and callback spelling from unique RTTI, original calls, and byte/reference matches.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/partchunk-profile /I{headers}/part-embedded /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include "ViewNew/PartChunk.h"
#include "RenderLib/Material2008.h"
#include "RenderLib/ViewBase2008.h"
#include "RenderLib/SceneManager2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Decal.h"
#include "v8datamodel/SpecialShape.h"
#include "v8datamodel/Workspace.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
namespace RBX {
// 004e7ed0 (instance for boost::bind(&PartChunk::onChildAdded, this, _1), called by the PartChunk ctor 004eaae0).
// INFERRED: body of the template the profile v8tree/Instance.h only declares; the shape follows that header's
// visitDescendents (read the copy-on-write children, end before begin) without the recursion.
template<class Function> void Instance::visitChildren(Function function) const
{
    if (children) {
        boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = children.read();
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = c->end();
        std::vector<boost::shared_ptr<Instance> >::const_iterator iter = c->begin();
        for (; iter != end; iter++)
            function(*iter);
    }
}
}
namespace RBX { namespace ViewNew {
// 004e6520: 2007 openrbx RbxView/Part.cpp PartChunk::onAncestorChanged shape.
void PartChunk::onAncestorChanged(boost::shared_ptr<Instance> ancestor)
{
    Workspace* workspace = Workspace::findWorkspace(partInstance.get());
    Instance* parent;

    if (workspace == NULL ||
        (workspace != (parent = partInstance->getParent()) && (parent == NULL || !parent->isDescendentOf(workspace)))) {
        view->sceneManager->removeModel(this);
    }
}
// 004e6630: the same shape on the Texture's own instance (+0xd8).
void Texture::onTextureAncestorChanged(boost::shared_ptr<Instance> ancestor)
{
    Workspace* workspace = Workspace::findWorkspace(decal.get());
    Instance* parent;

    if (workspace == NULL ||
        (workspace != (parent = decal->getParent()) && (parent == NULL || !parent->isDescendentOf(workspace)))) {
        view->sceneManager->removeModel(this);
    }
}
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

// 004e83b0: the 2008 Decal version re-parents the chunk (shared_from of the decal's PartInstance parent) and refreshes
// it while the decal stays in the Workspace (calls 005a3380, __RTDynamicCast to PartInstance, 00618a40, 00422ae0 twice).
void Decal::onDecalAncestorChanged(boost::shared_ptr<Instance> ancestor)
{
    if (decal) {
        Workspace* workspace = Workspace::findWorkspace(decal.get());
        partInstance = shared_from(dynamic_cast<PartInstance*>(decal->getParent()));
        if (workspace && decal->isDescendentOf(workspace)) {
            invalidateMaterial();
            invalidateMesh();
        }
        if (!workspace || !decal->isDescendentOf(workspace))
            view->sceneManager->removeModel(this);
    }
}

// 004ea5e0: 2007 openrbx PartChunk::onChildAdded plus the 2008 Decal child test (dynamic_cast to RBX::Decal 00940dbc,
// then invalidateMesh 004e6740 / invalidateMaterial 004e68b0).
void PartChunk::onChildAdded(boost::shared_ptr<Instance> child)
{
    SpecialShape* specialShape = dynamic_cast<SpecialShape*>(child.get());

    if (specialShape != NULL) {
        this->specialShape = specialShape;

        shapePropertyChangedConnection = Instance::event_propertyChanged.connect(
            specialShape, boost::bind(&PartChunk::onSpecialShapeChanged, this), 10
        );

        invalidateMesh();
    }

    if (dynamic_cast<RBX::Decal*>(child.get())) {
        invalidateMesh();
        invalidateMaterial();
    }
}
} }
