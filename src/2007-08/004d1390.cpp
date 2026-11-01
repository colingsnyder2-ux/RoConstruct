// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client RbxView/Part.cpp

// Candidate translation unit (score above; library headers required).
#include "Part.h"

#include "MaterialFactory.h"
#include "MeshFactory.h"
#include "PBBMesh.h"
#include "View.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/custommesh.h"

#include <boost/bind.hpp>

namespace RBX {
namespace View {

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
bool PartChunk::castsShadows() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
bool PartChunk::cullable() const
{
	return true;
}

// STUB: WEBSERVICE 0x1016c240
float primaryComponent(const G3D::Vector3& v)
{
	float nx = G3D::abs(v.x);
	float ny = G3D::abs(v.y);
	float nz = G3D::abs(v.z);

	return G3D::max(G3D::max(nx, ny), nz);
}

// FUNCTION: WEBSERVICE 0x1016c6d0
bool Part::usesMegaTexture() const
{
	if (specialShape == NULL && partInstance->getPartType() == RBX::Part::BLOCK_PART) {
		G3D::Vector3 size = partInstance->getPartSizeXml();

		return primaryComponent(size) < 30.0;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1016c740
const G3D::CoordinateFrame& PartChunk::cframe()
{
	coordinateFrame = partInstance->getCoordinateFrame();

	return coordinateFrame;
}

// STUB: WEBSERVICE 0x1016cd00
G3D::ReferenceCountedPointer<Render::Material> Part::getMaterial()
{
	STUB(0x1016cd00);
	return material;
}

// FUNCTION: WEBSERVICE 0x1016d060
void Part::onEvent(const PartInstance* source, CanAggregateChanged event)
{
	view->sceneManager->setSleeping(this, event.canClump);
}

// FUNCTION: WEBSERVICE 0x1016d100
void PartChunk::onAncestorChanged(boost::shared_ptr<Instance>)
{
	Workspace* workspace = Workspace::findWorkspace(partInstance.get());
	Instance* parent;

	if (workspace == NULL ||
		(workspace != (parent = partInstance->getParent()) && (parent == NULL || !parent->isDescendentOf(workspace)))) {
		view->sceneManager->removeModel(this);
	}
}

// FUNCTION: WEBSERVICE 0x1016d320
void PartChunk::invalidateMesh()
{
	mesh = NULL;

	view->sceneManager->invalidateModel(this, partInstance->getCanAggregate());
}

// FUNCTION: WEBSERVICE 0x1016d410
void PartChunk::invalidateMaterial()
{
	material = NULL;
	materialInvalid = true;

	view->sceneManager->invalidateModel(this, partInstance->getCanAggregate());
}

// FUNCTION: WEBSERVICE 0x1016d500
void PartChunk::onSpecialShapeChanged()
{
	invalidateMesh();
	invalidateMaterial();
}

// FUNCTION: WEBSERVICE 0x1016d510
void PartChunk::onPropertyChanged(const Reflection::PropertyDescriptor* descriptor)
{
	if (descriptor == &PartInstance::prop_Size) {
		invalidateMesh();
		invalidateMaterial();
	}
	else if (descriptor == &PartInstance::prop_shapeXml) {
		invalidateMesh();
	}
	else if (Surfaces::isSurfaceDescriptor(*descriptor)) {
		invalidateMesh();
	}
}

// FUNCTION: WEBSERVICE 0x1016d550
void Part::onPropertyChanged(const Reflection::PropertyDescriptor* descriptor)
{
	PartChunk::onPropertyChanged(descriptor);

	if (descriptor == &PartInstance::prop_Color) {
		if (usesMegaTexture()) {
			invalidateMesh();
		}

		invalidateMaterial();
	}
	else if (descriptor == &PartInstance::prop_Transparency || descriptor == &PartInstance::prop_Reflectance) {
		invalidateMaterial();
	}
}

// FUNCTION: WEBSERVICE 0x1016d5d0
G3D::ReferenceCountedPointer<Render::Mesh> PartChunk::getMesh()
{
	if (mesh.isNull()) {
		updateMesh();
	}

	return mesh;
}

// FUNCTION: WEBSERVICE 0x1016e0e0
void PartChunk::onChildRemoved(boost::shared_ptr<Instance> child)
{
	if (child.get() == specialShape) {
		shapePropertyChangedConnection.disconnect();
		specialShape = NULL;
		invalidateMesh();
	}
}

// FUNCTION: WEBSERVICE 0x1016f210
PartChunk::~PartChunk()
{
}

// FUNCTION: WEBSERVICE 0x101703a0
Part::~Part()
{
	if (partInstance) {
		partInstance->Notifier<PartInstance, CanAggregateChanged>::removeListener(this);
	}
}

// STUB: WEBSERVICE 0x101722a0
void Part::updateMesh()
{
	STUB(0x101722a0);
}

// STUB: WEBSERVICE 0x10173c90
void PartChunk::onChildAdded(boost::shared_ptr<Instance> child)
{
	SpecialShape* specialShape = dynamic_cast<SpecialShape*>(child.get());

	if (specialShape != NULL) {
		this->specialShape = specialShape;

		shapePropertyChangedConnection = Instance::event_propertyChanged.connect(
			specialShape,
			boost::bind(&PartChunk::onSpecialShapeChanged, this),
			10
		);

		invalidateMesh();
	}
}

// STUB: WEBSERVICE 0x10174160
PartChunk::PartChunk(float polygonOffset, const boost::shared_ptr<PartInstance>& partInstance, View* view)
	: Render::Chunk(polygonOffset), partInstance(partInstance), materialInvalid(true), view(view), specialShape(NULL)
{
	view->sceneManager->addModel(this);
}

// STUB: WEBSERVICE 0x10174800
Part::Part(const boost::shared_ptr<PartInstance>& partInstance, View* view) : PartChunk(0.0f, partInstance, view)
{
	STUB(0x10174800);
}

} // namespace View
} // namespace RBX
