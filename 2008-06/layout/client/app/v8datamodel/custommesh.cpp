// =============================================================================
// custommesh.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/custommesh.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/SpecialShape.h"
#include "v8datamodel/PartInstance.h"
#include "reflection/enumconverter.h"

namespace RBX
{
	char sSpecialShape[] = "SpecialMesh"; // 0094afac (pushed by classDescriptor 0059f7e0)

	// Template members the shared headers only declare (same definitions as Team.cpp / Feature.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	Reflection::EnumDesc<SpecialShape::MeshType>::EnumDesc()   // 0059f630
		: EnumDescriptor("MeshType", typeid(SpecialShape::MeshType))
	{
		addPair(SpecialShape::HEAD_MESH, "Head");
		addPair(SpecialShape::TORSO_MESH, "Torso");
		addPair(SpecialShape::WEDGE_MESH, "Wedge");
		addPair(SpecialShape::BRICK_MESH, "Brick");
		addPair(SpecialShape::SPHERE_MESH, "Sphere");
		addPair(SpecialShape::CYLINDER_MESH, "Cylinder");
		addPair(SpecialShape::FILE_MESH, "FileMesh");
	}
}

static RBX::Reflection::EnumPropDescriptor<RBX::SpecialShape, RBX::SpecialShape::MeshType> desc_meshType(
	"MeshType",
	"Data",
	&RBX::SpecialShape::getMeshType,
	&RBX::SpecialShape::setMeshType,
	RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::SpecialShape, G3D::Vector3> desc_scale(
	"Scale",
	"Data",
	&RBX::SpecialShape::getScale,
	&RBX::SpecialShape::setScale,
	RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::SpecialShape, RBX::MeshId> desc_meshId(
	"MeshId",
	"Data",
	&RBX::SpecialShape::getMeshId,
	&RBX::SpecialShape::setMeshId,
	RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::SpecialShape, RBX::TextureId> desc_textureId(
	"TextureId",
	"Data",
	&RBX::SpecialShape::getTextureId,
	&RBX::SpecialShape::setTextureId,
	RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::SpecialShape, G3D::Vector3> desc_vertColor(
	"VertexColor",
	"Data",
	&RBX::SpecialShape::getVertColor,
	&RBX::SpecialShape::setVertColor,
	RBX::Reflection::PropertyDescriptor::STANDARD);

namespace RBX
{
	SpecialShape::SpecialShape()
		: meshType(HEAD_MESH),
		  scale(1.0f, 1.0f, 1.0f),
		  vertColor(1.0f, 1.0f, 1.0f)
	{
		setName("Mesh");
	}

	bool SpecialShape::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const PartInstance*>(instance) != 0;
	}

	void SpecialShape::setMeshType(MeshType value)
	{
		if (meshType != value)
		{
			meshType = value;
			raisePropertyChanged(desc_meshType);
		}
	}

	void SpecialShape::setScale(const G3D::Vector3& value)
	{
		if (scale != value)
		{
			scale = value;
			raisePropertyChanged(desc_scale);
		}
	}

	void SpecialShape::setVertColor(const G3D::Vector3& value)
	{
		if (vertColor != value)
		{
			vertColor = value;
			raisePropertyChanged(desc_vertColor);
		}
	}

	void SpecialShape::setMeshId(const MeshId& value)
	{
		if (meshId != value)
		{
			meshId = value;
			raisePropertyChanged(desc_meshId);
			setMeshType(FILE_MESH);
		}
	}

	void SpecialShape::setTextureId(const TextureId& value)
	{
		if (textureId != value)
		{
			textureId = value;
			raisePropertyChanged(desc_textureId);
			setMeshType(FILE_MESH);
		}
	}
}

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::SpecialShape::MeshType>;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::SpecialShape::MeshType> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::SpecialShape::MeshType> > >;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::SpecialShape::MeshType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::SpecialShape::MeshType> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::SpecialShape::MeshType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::SpecialShape::MeshType> >,0> >;
template class std::_Vector_const_iterator<enum RBX::SpecialShape::MeshType,std::allocator<enum RBX::SpecialShape::MeshType> >;
template class std::_Vector_iterator<enum RBX::SpecialShape::MeshType,std::allocator<enum RBX::SpecialShape::MeshType> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::SpecialShape::MeshType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::SpecialShape::MeshType> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::SpecialShape::MeshType> >;
template class std::vector<enum RBX::SpecialShape::MeshType,std::allocator<enum RBX::SpecialShape::MeshType> >;

template void RBX::Name::callDoDeclare<RBX::sSpecialShape>();
