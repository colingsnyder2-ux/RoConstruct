// 2008-06 native RBX::SpecialShape (inactive); evidence in native-headers/v8datamodel/SpecialShape.h.
// Verified by tests/record_native_special_shape.py. Original unit 0059ece0..005a008d, initializers
// 007f4c20..007f4d20, atexit 007fdfe0..007fe090. Unit profile: document-swap flags + /fp:fast (setScale /
// setVertColor compare with `fld; fcomp mem`). The EnumPropDescriptor constructor 0059fe00 and the
// TypedPropertyDescriptor<MeshId> Value/boost::any helpers 0059eec0..0059f400 come from header templates; they are
// exact only against the generated reflection.h / type.h / property.h copies the recorder writes (proposals).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
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

#ifdef SPECIALSHAPE_HEADER_DECLARES_GETALPHA
	// 0059eca0 (registry placeholder func_0059eca0): donor custommesh.cpp getAlpha, the first body of the unit (just
	// before the FactoryProduct<SpecialShape> destructor 0059ece0). Parent +0x104, dynamic_cast to PartInstance
	// (??_R0 0092dd50), then PartInstance::alpha() = 1 - (1 - transparency +0x1e8) * alphaModifier +0x328 (the
	// part-embedded PartInstance layout). Guarded: native-headers/v8datamodel/SpecialShape.h does not yet declare
	// `const float getAlpha() const;` (header proposal). Measured byte-identical with that declaration (batch 50 mx06).
	const float SpecialShape::getAlpha() const
	{
		Instance* parent = getParent();
		if (!parent)
			return 0.0f;

		if (PartInstance* part = dynamic_cast<PartInstance*>(parent))
			return part->alpha();

		return 0.0f;
	}
#endif

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

// Dynamic initializers 007f4c20, 007f4c60, 007f4ca0, 007f4ce0, 007f4d20 (in this order; Functionality 5 = STANDARD).
static RBX::Reflection::EnumPropDescriptor<RBX::SpecialShape, RBX::SpecialShape::MeshType> desc_meshType("MeshType", "Data", &RBX::SpecialShape::getMeshType, &RBX::SpecialShape::setMeshType, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::SpecialShape, G3D::Vector3> desc_scale("Scale", "Data", &RBX::SpecialShape::getScale, &RBX::SpecialShape::setScale, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::SpecialShape, RBX::MeshId> desc_meshId("MeshId", "Data", &RBX::SpecialShape::getMeshId, &RBX::SpecialShape::setMeshId, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::SpecialShape, RBX::TextureId> desc_textureId("TextureId", "Data", &RBX::SpecialShape::getTextureId, &RBX::SpecialShape::setTextureId, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::SpecialShape, G3D::Vector3> desc_vertColor("VertexColor", "Data", &RBX::SpecialShape::getVertColor, &RBX::SpecialShape::setVertColor, RBX::Reflection::PropertyDescriptor::STANDARD);

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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
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

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sSpecialShape>();

