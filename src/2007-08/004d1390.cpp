// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client RbxView/Part.cpp

// Candidate translation unit (score above; library headers required).
#include "Part.h"

#include "BrickMesh.h"
#include "CylinderMesh.h"
#include "FileMesh.h"
#include "HeadMesh.h"
#include "MaterialFactory.h"
#include "MeshFactory.h"
#include "PBBMesh.h"
#include "SphereMesh.h"
#include "TorsoMesh.h"
#include "WedgeMesh.h"
#include "rbxview/View.h"
#include "renderlib/TextureProxy.h"
#include "util/ContentProvider.h"
#include "v8datamodel/Decal.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/custommesh.h"

#include <boost/bind.hpp>

namespace RBX {
namespace View {

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
bool PartChunk::castsShadows() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
bool PartChunk::cullable() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x1016c240
// FUNCTION: ROBLOX 0x00477940
float primaryComponent(const G3D::Vector3& v)
{
	float nx = fabs(v.x);
	float ny = fabs(v.y);
	float nz = fabs(v.z);

	if (nx > ny) {
		if (nx > nz) {
			return nx;
		}

		return nz;
	}

	if (ny > nz) {
		return ny;
	}

	return nz;
}

// FUNCTION: WEBSERVICE 0x1016c6d0
// FUNCTION: ROBLOX 0x00477c90
bool Part::usesMegaTexture() const
{
	if (specialShape == NULL && partInstance->getPartType() == RBX::Part::BLOCK_PART) {
		G3D::Vector3 size = partInstance->getPartSizeXml();

		return primaryComponent(size) < 30.0;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1016c740
// FUNCTION: ROBLOX 0x00477d00
const G3D::CoordinateFrame& PartChunk::cframe()
{
	coordinateFrame = partInstance->getCoordinateFrame();

	return coordinateFrame;
}

// FUNCTION: WEBSERVICE 0x1016cd00
// FUNCTION: ROBLOX 0x004780c0
G3D::ReferenceCountedPointer<Render::Material> Part::getMaterial()
{
	try {
		if (materialInvalid) {
			MaterialFactory::Attributes attr = {
				partInstance->getColor(), partInstance->getTransparencyUi(), partInstance->getReflectance()
			};

			if (usesMegaTexture()) {
				material = view->materialFactory->getMegaMaterial(attr);
				materialInvalid = false;
			}
			else if (specialShape && specialShape->getMeshType() == SpecialShape::FILE_MESH) {
				std::string textureFile;
				if (!ContentProvider::singleton().requestContentFile(specialShape->getTextureId(), textureFile)) {
					material = view->materialFactory->getMaterial(attr);
					return material;
				}

				G3D::Vector3 color = specialShape->getVertColor();
				float trans = specialShape->getAlpha();

				material = new Render::Material();
				material->appendLevel(
					new Render::TextureProxy(*view->textureManager, textureFile, false),
					G3D::Color3(color),
					0.0f,
					0.1f,
					0.0f,
					trans
				);
				materialInvalid = false;
			}
			else {
				material = view->materialFactory->getMaterial(attr);
				materialInvalid = false;
			}
		}
	}
	catch (...) {
	}

	return material;
}

// FUNCTION: WEBSERVICE 0x1016d060
// FUNCTION: ROBLOX 0x00478420
void Part::onEvent(const PartInstance* source, CanAggregateChanged event)
{
	view->sceneManager->setSleeping(this, event.canClump);
}

// FUNCTION: WEBSERVICE 0x1016d100
// FUNCTION: ROBLOX 0x004784c0
void PartChunk::onAncestorChanged(boost::shared_ptr<Instance> ancestor)
{
	Workspace* workspace = Workspace::findWorkspace(partInstance.get());
	Instance* parent;

	if (workspace == NULL ||
		(workspace != (parent = partInstance->getParent()) && (parent == NULL || !parent->isDescendentOf(workspace)))) {
		view->sceneManager->removeModel(this);
	}
}

// FUNCTION: WEBSERVICE 0x1016d210 FOLDED
// FUNCTION: ROBLOX 0x004785d0 FOLDED
void Decal::onDecalAncestorChanged(boost::shared_ptr<Instance> ancestor)
{
	Workspace* workspace = Workspace::findWorkspace(decal.get());
	Instance* parent;

	if (workspace == NULL ||
		(workspace != (parent = decal->getParent()) && (parent == NULL || !parent->isDescendentOf(workspace)))) {
		view->sceneManager->removeModel(this);
	}
}

// FUNCTION: WEBSERVICE 0x1016d210 FOLDED
// FUNCTION: ROBLOX 0x004785d0 FOLDED
void Texture::onTextureAncestorChanged(boost::shared_ptr<Instance> ancestor)
{
	Workspace* workspace = Workspace::findWorkspace(texture.get());
	Instance* parent;

	if (workspace == NULL ||
		(workspace != (parent = texture->getParent()) && (parent == NULL || !parent->isDescendentOf(workspace)))) {
		view->sceneManager->removeModel(this);
	}
}

// FUNCTION: WEBSERVICE 0x1016d320
// FUNCTION: ROBLOX 0x004786e0
void PartChunk::invalidateMesh()
{
	mesh = NULL;

	view->sceneManager->invalidateModel(this, partInstance->getCanAggregate());
}

// FUNCTION: WEBSERVICE 0x1016d410
// FUNCTION: ROBLOX 0x004787d0
void PartChunk::invalidateMaterial()
{
	material = NULL;
	materialInvalid = true;

	view->sceneManager->invalidateModel(this, partInstance->getCanAggregate());
}

// FUNCTION: WEBSERVICE 0x1016d500
// FUNCTION: ROBLOX 0x004788c0
void PartChunk::onSpecialShapeChanged()
{
	invalidateMesh();
	invalidateMaterial();
}

// FUNCTION: WEBSERVICE 0x1016d510
// FUNCTION: ROBLOX 0x004788d0
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
// FUNCTION: ROBLOX 0x00478910
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
// FUNCTION: ROBLOX 0x00478990
G3D::ReferenceCountedPointer<Render::Mesh> PartChunk::getMesh()
{
	if (mesh.isNull()) {
		updateMesh();
	}

	return mesh;
}

// FUNCTION: WEBSERVICE 0x1016d610
// FUNCTION: ROBLOX 0x004789d0
void Decal::onDecalPropertyChanged(const Reflection::PropertyDescriptor* descriptor)
{
	if (descriptor == &FaceInstance::prop_Face) {
		invalidateMesh();
	}
	else if (descriptor == &RBX::Decal::prop_Texture) {
		invalidateMaterial();
	}
	else if (descriptor == &RBX::Decal::prop_Specular) {
		invalidateMaterial();
	}
	else if (descriptor == &RBX::Decal::prop_Shiny) {
		invalidateMaterial();
	}
}

// FUNCTION: WEBSERVICE 0x1016d640
// FUNCTION: ROBLOX 0x00478a00
G3D::ReferenceCountedPointer<Render::Material> Decal::getMaterial()
{
	try {
		if (materialInvalid) {
			std::string textureFile;
			if (ContentProvider::singleton().requestContentFile(decal->getTexture(), textureFile)) {
				material = new Render::Material();
				material->appendLevel(
					new Render::TextureProxy(*view->textureManager, textureFile, false),
					G3D::Color3::WHITE,
					decal->getSpecular(),
					decal->getShiny(),
					0.0f,
					0.0f
				);
				materialInvalid = false;
			}
		}
	}
	catch (...) {
	}

	return material;
}

// FUNCTION: WEBSERVICE 0x1016d810
// FUNCTION: ROBLOX 0x00478bd0
void Texture::onTexturePropertyChanged(const Reflection::PropertyDescriptor* descriptor)
{
	if (descriptor == &FaceInstance::prop_Face) {
		invalidateMesh();
	}
	else if (descriptor == &RBX::Decal::prop_Texture) {
		invalidateMaterial();
	}
	else if (descriptor == &RBX::Decal::prop_Specular) {
		invalidateMaterial();
	}
	else if (descriptor == &RBX::Decal::prop_Shiny) {
		invalidateMaterial();
	}
	else if (descriptor == &RBX::Texture::prop_StudsPerTileU) {
		invalidateMesh();
	}
	else if (descriptor == &RBX::Texture::prop_StudsPerTileV) {
		invalidateMesh();
	}
}

// FUNCTION: WEBSERVICE 0x1016d850
// FUNCTION: ROBLOX 0x00478c10
G3D::ReferenceCountedPointer<Render::Material> Texture::getMaterial()
{
	try {
		if (materialInvalid) {
			std::string textureFile;
			if (ContentProvider::singleton().requestContentFile(texture->getTexture(), textureFile)) {
				material = new Render::Material();
				material->appendLevel(
					new Render::TextureProxy(*view->textureManager, textureFile, true),
					G3D::Color3::WHITE,
					texture->getSpecular(),
					texture->getShiny(),
					0.0f,
					0.0f
				);
				materialInvalid = false;
			}
		}
	}
	catch (...) {
	}

	return material;
}

// FUNCTION: WEBSERVICE 0x1016e0e0
// FUNCTION: ROBLOX 0x004792e0
void PartChunk::onChildRemoved(boost::shared_ptr<Instance> child)
{
	if (child.get() == specialShape) {
		shapePropertyChangedConnection.disconnect();
		specialShape = NULL;
		invalidateMesh();
	}
}

// FUNCTION: WEBSERVICE 0x1016f210
// FUNCTION: ROBLOX 0x00479e00
PartChunk::~PartChunk()
{
}

// FUNCTION: WEBSERVICE 0x1016f360
// FUNCTION: ROBLOX 0x00479f50
Decal::~Decal()
{
}

// FUNCTION: WEBSERVICE 0x1016f400
// FUNCTION: ROBLOX 0x00479ff0
Texture::~Texture()
{
}

// FUNCTION: WEBSERVICE 0x101703a0
// FUNCTION: ROBLOX 0x0047aba0
Part::~Part()
{
	if (partInstance) {
		partInstance->Notifier<PartInstance, CanAggregateChanged>::removeListener(this);
	}
}

static RenderSurfaceType renderSurfaceType(SurfaceType surfaceType)
{
	switch (surfaceType) {
	case RBX::STUDS:
		return STUDS;
	case RBX::INLET:
		return INLET;
	case RBX::WELD:
		return WELD;
	case RBX::GLUE:
		return GLUE;
	default:
		return FLAT;
	}
}

// FUNCTION: WEBSERVICE 0x101722a0
// FUNCTION: ROBLOX 0x0047c660
void Part::updateMesh()
{
	RenderSurfaceTypes surfaceTypes;
	surfaceTypes.setSurfaceType(NORM_X, renderSurfaceType(partInstance->getSurfaces()[NORM_X].getSurfaceType()));
	surfaceTypes.setSurfaceType(NORM_Y, renderSurfaceType(partInstance->getSurfaces()[NORM_Y].getSurfaceType()));
	surfaceTypes.setSurfaceType(NORM_Z, renderSurfaceType(partInstance->getSurfaces()[NORM_Z].getSurfaceType()));
	surfaceTypes.setSurfaceType(
		NORM_X_NEG, renderSurfaceType(partInstance->getSurfaces()[NORM_X_NEG].getSurfaceType())
	);
	surfaceTypes.setSurfaceType(
		NORM_Y_NEG, renderSurfaceType(partInstance->getSurfaces()[NORM_Y_NEG].getSurfaceType())
	);
	surfaceTypes.setSurfaceType(
		NORM_Z_NEG, renderSurfaceType(partInstance->getSurfaces()[NORM_Z_NEG].getSurfaceType())
	);

	G3D::Vector3 size = partInstance->getPartSizeXml();

	if (usesMegaTexture()) {
		mesh = BrickMesh::create(size, surfaceTypes, partInstance->getColor());
	}
	else if (!specialShape) {
		switch (partInstance->getPartType()) {
		case RBX::Part::BALL_PART:
			mesh = MeshFactory<SphereMesh, 1>::create(size, surfaceTypes);
			break;
		case RBX::Part::BLOCK_PART:
			mesh = MeshFactory<PBBMesh, 4>::create(size, surfaceTypes);
			break;
		case RBX::Part::CYLINDER_PART:
			mesh = MeshFactory<CylinderAlongXMesh, 1>::create(size, surfaceTypes);
			break;
		}
	}
	else {
		size *= specialShape->getScale();

		switch (specialShape->getMeshType()) {
		case SpecialShape::WEDGE_MESH:
			mesh = MeshFactory<WedgeMesh, 1>::create(size, surfaceTypes);
			break;
		case SpecialShape::HEAD_MESH:
			mesh = MeshFactory<HeadMesh, 1>::create(size, surfaceTypes);
			break;
		case SpecialShape::TORSO_MESH:
			mesh = MeshFactory<TorsoMesh, 1>::create(size, surfaceTypes);
			break;
		case SpecialShape::SPHERE_MESH:
			mesh = MeshFactory<SphereMesh, 1>::create(size, surfaceTypes);
			break;
		case SpecialShape::CYLINDER_MESH:
			mesh = MeshFactory<CylinderAlongXMesh, 1>::create(size, surfaceTypes);
			break;
		case SpecialShape::BRICK_MESH:
			mesh = MeshFactory<PBBMesh, 4>::create(size, surfaceTypes);
			break;
		case SpecialShape::FILE_MESH:
			mesh = FileMesh::create(specialShape->getScale(), specialShape->getMeshId());
			break;
		}
	}

	radius = sqrt(2.0f) * 0.5 * primaryComponent(size);
}

// FUNCTION: WEBSERVICE 0x10173790
// FUNCTION: ROBLOX 0x0047dbe0
void Decal::updateMesh()
{
	if (partInstance) {
		G3D::Vector3 size = partInstance->getPartSizeXml();

		if (specialShape) {
			size *= specialShape->getScale();
		}

		if (!specialShape) {
			switch (partInstance->getPartType()) {
			case RBX::Part::BALL_PART:
				mesh = MeshFactory<SphereMesh, 1>::createDecal(size, decal->getFace());
				break;
			case RBX::Part::BLOCK_PART:
				mesh = MeshFactory<PBBMesh, 4>::createDecal(size, decal->getFace());
				break;
			case RBX::Part::CYLINDER_PART:
				mesh = MeshFactory<CylinderAlongXMesh, 1>::createDecal(size, decal->getFace());
				break;
			}
		}
		else {
			switch (specialShape->getMeshType()) {
			case SpecialShape::WEDGE_MESH:
				mesh = MeshFactory<WedgeMesh, 1>::createDecal(size, decal->getFace());
				break;
			case SpecialShape::HEAD_MESH:
				mesh = MeshFactory<HeadMesh, 1>::createDecal(size, decal->getFace());
				break;
			case SpecialShape::TORSO_MESH:
				mesh = MeshFactory<TorsoMesh, 1>::createDecal(size, decal->getFace());
				break;
			case SpecialShape::SPHERE_MESH:
				mesh = MeshFactory<SphereMesh, 1>::createDecal(size, decal->getFace());
				break;
			case SpecialShape::CYLINDER_MESH:
				mesh = MeshFactory<CylinderAlongXMesh, 1>::createDecal(size, decal->getFace());
				break;
			case SpecialShape::BRICK_MESH:
				mesh = MeshFactory<PBBMesh, 4>::createDecal(size, decal->getFace());
				break;
			}
		}

		radius = sqrt(2.0f) * 0.5 * primaryComponent(size);
	}
}

// FUNCTION: WEBSERVICE 0x101739a0
// FUNCTION: ROBLOX 0x0047ddf0
void Texture::updateMesh()
{
	if (partInstance) {
		G3D::Vector3 size = partInstance->getPartSizeXml();

		if (specialShape) {
			size *= specialShape->getScale();
		}

		if (!specialShape) {
			switch (partInstance->getPartType()) {
			case RBX::Part::BALL_PART:
				mesh = MeshFactory<SphereMesh, 1>::createTexture(size, texture->getFace(), texture->getStudsPerTile());
				break;
			case RBX::Part::BLOCK_PART:
				mesh = MeshFactory<PBBMesh, 4>::createTexture(size, texture->getFace(), texture->getStudsPerTile());
				break;
			case RBX::Part::CYLINDER_PART:
				mesh = MeshFactory<CylinderAlongXMesh, 1>::createTexture(
					size, texture->getFace(), texture->getStudsPerTile()
				);
				break;
			}
		}
		else {
			switch (specialShape->getMeshType()) {
			case SpecialShape::WEDGE_MESH:
				mesh = MeshFactory<WedgeMesh, 1>::createTexture(size, texture->getFace(), texture->getStudsPerTile());
				break;
			case SpecialShape::HEAD_MESH:
				mesh = MeshFactory<HeadMesh, 1>::createTexture(size, texture->getFace(), texture->getStudsPerTile());
				break;
			case SpecialShape::TORSO_MESH:
				mesh = MeshFactory<TorsoMesh, 1>::createTexture(size, texture->getFace(), texture->getStudsPerTile());
				break;
			case SpecialShape::SPHERE_MESH:
				mesh = MeshFactory<SphereMesh, 1>::createTexture(size, texture->getFace(), texture->getStudsPerTile());
				break;
			case SpecialShape::CYLINDER_MESH:
				mesh = MeshFactory<CylinderAlongXMesh, 1>::createTexture(
					size, texture->getFace(), texture->getStudsPerTile()
				);
				break;
			case SpecialShape::BRICK_MESH:
				mesh = MeshFactory<PBBMesh, 4>::createTexture(size, texture->getFace(), texture->getStudsPerTile());
				break;
			}
		}

		radius = sqrt(2.0f) * 0.5 * primaryComponent(size);
	}
}

// FUNCTION: WEBSERVICE 0x10173c90
// FUNCTION: ROBLOX 0x0047e0e0
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
}

// FUNCTION: WEBSERVICE 0x10174160
// FUNCTION: ROBLOX 0x0047e5b0
PartChunk::PartChunk(float polygonOffset, const boost::shared_ptr<PartInstance>& partInstance, View* view)
	: Render::Chunk(polygonOffset), partInstance(partInstance), materialInvalid(true), view(view), specialShape(NULL)
{
	view->sceneManager->addModel(this);

	childAddedConnection =
		Instance::event_childAdded.connect(partInstance.get(), boost::bind(&PartChunk::onChildAdded, this, _1), 10);
	childRemovedConnection =
		Instance::event_childRemoved.connect(partInstance.get(), boost::bind(&PartChunk::onChildRemoved, this, _1), 10);
	ancestorChangedConnection = Instance::event_ancestryChanged.connect(
		partInstance.get(), boost::bind(&PartChunk::onAncestorChanged, this, _1), 10
	);
	propertyChangedConnection = Instance::event_propertyChanged.connect(
		partInstance.get(), boost::bind(&PartChunk::onPropertyChanged, this, _1), 10
	);

	partInstance->visitChildren(boost::bind(&PartChunk::onChildAdded, this, _1));
}

// FUNCTION: WEBSERVICE 0x10174480
// FUNCTION: ROBLOX 0x0047e8d0
Decal::Decal(RBX::Decal& decal, PartInstance& parentPart, View* view)
	: PartChunk(Render::Chunk::DECAL_OFFSET, shared_from(&parentPart), view), decal(shared_from(&decal))
{
	decalAncestorChangedConnection =
		Instance::event_ancestryChanged.connect(&decal, boost::bind(&Decal::onDecalAncestorChanged, this, _1), 10);
	decalPropertyChangedConnection =
		Instance::event_propertyChanged.connect(&decal, boost::bind(&Decal::onDecalPropertyChanged, this, _1), 10);
}

// FUNCTION: WEBSERVICE 0x10174640
// FUNCTION: ROBLOX 0x0047ea90
Texture::Texture(RBX::Texture& texture, PartInstance& parentPart, View* view)
	: PartChunk(Render::Chunk::TEXTURE_OFFSET, shared_from(&parentPart), view), texture(shared_from(&texture))
{
	textureAncestorChangedConnection = Instance::event_ancestryChanged.connect(
		&texture, boost::bind(&Texture::onTextureAncestorChanged, this, _1), 10
	);
	texturePropertyChangedConnection = Instance::event_propertyChanged.connect(
		&texture, boost::bind(&Texture::onTexturePropertyChanged, this, _1), 10
	);
}

// FUNCTION: WEBSERVICE 0x10174800
// FUNCTION: ROBLOX 0x0047ec50
Part::Part(const boost::shared_ptr<PartInstance>& partInstance, View* view) : PartChunk(0.0f, partInstance, view)
{
	if (partInstance->getCanAggregate()) {
		view->sceneManager->setSleeping(this, true);
	}
	startListening(partInstance, this);
	invalidateMesh();
	invalidateMaterial();
}

} // namespace View
} // namespace RBX
