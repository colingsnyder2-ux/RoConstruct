// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/custommesh.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/custommesh.h"

#include "reflection/property.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {

char sSpecialShape[] = "SpecialMesh";

static Reflection::EnumPropDescriptor<SpecialShape, SpecialShape::MeshType> desc_meshType(
	"MeshType", "Data", &SpecialShape::getMeshType, &SpecialShape::setMeshType
);

static Reflection::PropDescriptor<SpecialShape, G3D::Vector3> desc_scale(
	"Scale", "Data", &SpecialShape::getScale, &SpecialShape::setScale
);

static Reflection::PropDescriptor<SpecialShape, MeshId> desc_meshId(
	"MeshId", "Data", &SpecialShape::getMeshId, &SpecialShape::setMeshId
);

static Reflection::PropDescriptor<SpecialShape, TextureId> desc_textureId(
	"TextureId", "Data", &SpecialShape::getTextureId, &SpecialShape::setTextureId
);

static Reflection::PropDescriptor<SpecialShape, G3D::Vector3> desc_vertColor(
	"VertexColor", "Data", &SpecialShape::getVertColor, &SpecialShape::setVertColor
);

// FUNCTION: WEBSERVICE 0x100ea070 FOLDED
// FUNCTION: ROBLOX 0x005dfdf0 FOLDED
bool SpecialShape::askSetParent(const Instance* instance) const
{
	return dynamic_cast<const PartInstance*>(instance) != NULL;
}

// FUNCTION: WEBSERVICE 0x1012c930
// FUNCTION: ROBLOX 0x005b3330
const float SpecialShape::getAlpha() const
{
	if (getParent()) {
		PartInstance* part = dynamic_cast<PartInstance*>(getParent());
		if (part) {
			return part->getTransparencyUi();
		}
	}

	return 0;
}

namespace Reflection {

// FUNCTION: WEBSERVICE 0x1012d0c0
// FUNCTION: ROBLOX 0x005b3980
template <>
EnumDesc<SpecialShape::MeshType>::EnumDesc() : EnumDescriptor("MeshType", typeid(SpecialShape::MeshType))
{
	addPair(SpecialShape::HEAD_MESH, "Head");
	addPair(SpecialShape::TORSO_MESH, "Torso");
	addPair(SpecialShape::WEDGE_MESH, "Wedge");
	addPair(SpecialShape::BRICK_MESH, "Brick");
	addPair(SpecialShape::SPHERE_MESH, "Sphere");
	addPair(SpecialShape::CYLINDER_MESH, "Cylinder");
	addPair(SpecialShape::FILE_MESH, "FileMesh");
}

} // namespace Reflection

// FUNCTION: WEBSERVICE 0x1012d970
// FUNCTION: ROBLOX 0x005b4270
SpecialShape::SpecialShape() : meshType(HEAD_MESH), scale(1.0f, 1.0f, 1.0f), vertColor(1.0f, 1.0f, 1.0f)
{
	setName("Mesh");
}

// FUNCTION: WEBSERVICE 0x1012dbb0
void SpecialShape::setMeshType(MeshType value)
{
	if (meshType != value) {
		meshType = value;
		raisePropertyChanged(desc_meshType);
	}
}

// FUNCTION: WEBSERVICE 0x1012dbe0
// FUNCTION: ROBLOX 0x005b44e0
void SpecialShape::setScale(const G3D::Vector3& value)
{
	if (scale != value) {
		scale = value;
		raisePropertyChanged(desc_scale);
	}
}

// FUNCTION: WEBSERVICE 0x1012dc40
// FUNCTION: ROBLOX 0x005b4540
void SpecialShape::setVertColor(const G3D::Vector3& value)
{
	if (vertColor != value) {
		vertColor = value;
		raisePropertyChanged(desc_vertColor);
	}
}

// FUNCTION: WEBSERVICE 0x1012dca0
// FUNCTION: ROBLOX 0x005b45a0
void SpecialShape::setMeshId(const MeshId& value)
{
	if (meshId != value) {
		meshId = value;
		raisePropertyChanged(desc_meshId);
		setMeshType(FILE_MESH);
	}
}

// FUNCTION: WEBSERVICE 0x1012dd00
// FUNCTION: ROBLOX 0x005b4600
void SpecialShape::setTextureId(const TextureId& value)
{
	if (textureId != value) {
		textureId = value;
		raisePropertyChanged(desc_textureId);
		setMeshType(FILE_MESH);
	}
}
} // namespace RBX

template class RBX::FactoryProduct<RBX::SpecialShape, RBX::Instance, RBX::sSpecialShape>;
template class RBX::Reflection::Described<
	RBX::SpecialShape,
	RBX::sSpecialShape,
	RBX::FactoryProduct<RBX::SpecialShape, RBX::Instance, RBX::sSpecialShape> >;
template class RBX::DescribedCreatable<RBX::SpecialShape, RBX::Instance, RBX::sSpecialShape>;
