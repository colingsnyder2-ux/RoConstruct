#include "AppUnit49C_2008/Streaming2008.h"
#include <BitStream.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Color3.h>
#include "reflection/property.h"
#include <typeinfo>

namespace RBX
{
	namespace Network
	{
		RakNet::BitStream& operator<<(RakNet::BitStream& stream, const G3D::Color3& value);
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::Color3& value);
	}

	namespace Reflection
	{
		template<typename T>
		T ConstProperty::getValue() const
		{
			const TypedPropertyDescriptor<T>* typed = dynamic_cast<const TypedPropertyDescriptor<T>*>(&getDescriptor());
			if (typed == NULL)
				throw std::bad_cast();
			return typed->getValue(getInstance());
		}

		template<typename T>
		void Property::setValue(const T& value)
		{
			const TypedPropertyDescriptor<T>* typed = dynamic_cast<const TypedPropertyDescriptor<T>*>(&getDescriptor());
			if (typed == NULL)
				throw std::bad_cast();
			typed->setValue(getInstance(), value);
		}
	}

	namespace Network
	{
		template<typename T>
		void serialize(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream)
		{
			bitStream << property.getValue<T>();
		}

		template<typename T>
		void deserialize(Reflection::Property& property, RakNet::BitStream& bitStream)
		{
			T value;
			bitStream >> value;
			if (property.getInstance())
				property.setValue<T>(value);
		}

		template void serialize<G3D::Vector3>(const Reflection::ConstProperty&, RakNet::BitStream&);
		template void deserialize<G3D::Vector3>(Reflection::Property&, RakNet::BitStream&);
		template void serialize<G3D::Color3>(const Reflection::ConstProperty&, RakNet::BitStream&);
		template void deserialize<G3D::Color3>(Reflection::Property&, RakNet::BitStream&);
		template void serialize<G3D::CoordinateFrame>(const Reflection::ConstProperty&, RakNet::BitStream&);
		template void deserialize<G3D::CoordinateFrame>(Reflection::Property&, RakNet::BitStream&);
		template void deserialize<float>(Reflection::Property&, RakNet::BitStream&);
		template void serialize<double>(const Reflection::ConstProperty&, RakNet::BitStream&);
		template void deserialize<double>(Reflection::Property&, RakNet::BitStream&);
	}
}

#include <G3D/Vector3.h>

struct CSHA1 {
    char padding[0x270];
    float x, y, z;
    G3D::Vector3 getVector() const;
};

G3D::Vector3 CSHA1::getVector() const
{
    G3D::Vector3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

#include "ViewNew/SphereMesh.h"
#include "ViewNew/CylinderMesh.h"
#include "ViewNew/HeadMesh.h"
#include "ViewNew/WedgeMesh.h"
#include "ViewNew/TorsoMesh.h"
#include "ViewNew/PBBMesh.h"
#include "ViewNewPartMesh2008/MeshFactoryCache2008.h"

namespace RBX
{
	namespace ViewNew
	{
		template class MeshFactory<SphereMesh, 1>;
		template class MeshFactory<CylinderAlongXMesh, 1>;
		template class MeshFactory<HeadMesh, 1>;
		template class MeshFactory<WedgeMesh, 1>;
		template class MeshFactory<TorsoMesh, 1>;
		template class MeshFactory<PBBMesh, 4>;
	}
}

template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > > >;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>,std::less<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey>,std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::CylinderAlongXMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::HeadMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::PBBMesh,4>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::SphereMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::TorsoMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::DecalKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;
template class std::allocator<std::pair<RBX::ViewNew::MeshFactory<RBX::ViewNew::WedgeMesh,1>::TextureKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> > >;

// INFERRED: sub_0061ce80 (placeholder name for 0061ce80 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <lua.h>
#include <algorithm>
#include "util/Name.h"
#include "LuaBridge2008/LuaBridge2008.h"

namespace RBX
{
	namespace Lua
	{
		int sub_0061ce80(lua_State* L)
		{
			float v[3];
			int nargs = std::min(3, lua_gettop(L));

			for (int i = 0; i < nargs; i++)
				v[i] = tonumberClamped(L, i + 1);

			for (int i = nargs; i < 3; i++)
				v[i] = 0;

			Vector3Bridge::pushVector3(L, G3D::Vector3(v));
			return 1;
		}
	}
}

#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "tool/Dragger.h"
#include "util/Math.h"
#include "util/Extents.h"

namespace RBX {
bool hitMoveHandles(const Extents&, const G3D::Ray&, G3D::Vector3&, NormalId&);
bool AxisMoveTool::hitHandle(const UIEvent& event, G3D::Vector3& point, NormalId& face) {
    Extents box;
    if (bounds(box)) {
        if (hitMoveHandles(box, getUnitMouseRay(event), point, face)) return true;
    }
    return false;
}
MouseCommand* AxisMoveTool::onMouseDown(const UIEvent& event) {
    G3D::Vector3 point;
    NormalId face;
    if (hitHandle(event, point, face)) {
        mouseDownView = event.mousePosition;
        axis = face % 3;
        dragPoint = Math::toGrid(point, axisMoveGrid());
        dragRay = G3D::Ray::fromOriginAndDirection(dragPoint, normalIdToVector3(face));
        capture();
        return this;
    }
    return ArrowToolBase::onMouseDown(event);
}
}

#line 1 ".\\G3Dcpp\\Box.cpp"
/**
  @file Box.cpp
  Box class

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2001-06-02
  @edited  2006-02-05
*/

#include "G3D/Box.h"
#include "G3D/debug.h"
#include "G3D/Plane.h"
#include "G3D/AABox.h"
#include "G3D/CoordinateFrame.h"

namespace G3D {

/**
 Sets a field on four vertices.  Used by the constructor.
 */
#define setMany(i0, i1, i2, i3, field, extreme) \
    _corner[i0].field = _corner[i1].field = \
    _corner[i2].field = _corner[i3].field = \
    (extreme).field

Box::Box() {
}

Box::Box(const AABox& b) {
    init(b.low(), b.high());
}

Box::Box(class BinaryInput& b) {
	deserialize(b);
}

void Box::serialize(class BinaryOutput& b) const {
	int i;
	for (i = 0; i < 8; ++i) {
		_corner[i].serialize(b);
	}

    // Other state can be reconstructed
}

void Box::deserialize(class BinaryInput& b) {
	int i;

    _center = Vector3::zero();
    for (i = 0; i < 8; ++i) {
		_corner[i].deserialize(b);
        _center += _corner[i];
	}

    _center = _center / 8;

    // Reconstruct other state from the corners
    _axis[0] = _corner[5] - _corner[4];
    _axis[1] = _corner[7] - _corner[4];
    _axis[2] = _corner[0] - _corner[4];

    for (i = 0; i < 3; ++i) {
        _extent[i] = _axis[i].magnitude();
        _axis[i] /= _extent[i];
    }

    _volume = _extent.x * _extent.y * _extent.z;

    _area = 2 *
        (_extent.x * _extent.y +
         _extent.y * _extent.z +
         _extent.z * _extent.x);
}

Box::Box(
    const Vector3& min,
    const Vector3& max) {

    init(min.min(max), min.max(max));

}

void Box::init(
    const Vector3& min,
    const Vector3& max) {

    setMany(0, 1, 2, 3, z, max);
    setMany(4, 5, 6, 7, z, min);

    setMany(1, 2, 5, 6, x, max);
    setMany(0, 3, 4, 7, x, min);

    setMany(3, 2, 6, 7, y, max);
    setMany(0, 1, 5, 4, y, min);

    _extent = max - min;

    _axis[0] = Vector3::unitX();
    _axis[1] = Vector3::unitY();
    _axis[2] = Vector3::unitZ();

    _volume = _extent.x * _extent.y * _extent.z;
    _area = 2 *
        (_extent.x * _extent.y +
         _extent.y * _extent.z +
         _extent.z * _extent.x);

    _center = (max + min) / 2;
}

float Box::volume() const {
    return _volume;
}

float Box::surfaceArea() const {
    return _area;
}

void Box::getLocalFrame(CoordinateFrame& frame) const {

    frame.rotation = Matrix3(
        _axis[0][0], _axis[1][0], _axis[2][0],
        _axis[0][1], _axis[1][1], _axis[2][1],
        _axis[0][2], _axis[1][2], _axis[2][2]);

    frame.translation = _center;
}

CoordinateFrame Box::localFrame() const {
    CoordinateFrame out;
    getLocalFrame(out);
    return out;
}

void Box::getFaceCorners(int f, Vector3& v0, Vector3& v1, Vector3& v2, Vector3& v3) const {
    switch (f) {
    case 0:
        v0 = _corner[0]; v1 = _corner[1]; v2 = _corner[2]; v3 = _corner[3];
        break;

    case 1:
        v0 = _corner[1]; v1 = _corner[5]; v2 = _corner[6]; v3 = _corner[2];
        break;

    case 2:
        v0 = _corner[7]; v1 = _corner[6]; v2 = _corner[5]; v3 = _corner[4];
        break;

    case 3:
        v0 = _corner[2]; v1 = _corner[6]; v2 = _corner[7]; v3 = _corner[3];
        break;

    case 4:
        v0 = _corner[3]; v1 = _corner[7]; v2 = _corner[4]; v3 = _corner[0];
        break;

    case 5:
        v0 = _corner[1]; v1 = _corner[0]; v2 = _corner[4]; v3 = _corner[5];
        break;

    default:
        debugAssert((f >= 0) && (f < 6));
    }
}

bool Box::culledBy(
    const Array<Plane>&		plane,
	int&				    cullingPlaneIndex,
	const uint32			inMask,
	uint32&					outMask) const {

	return culledBy(plane.getCArray(), plane.size(), cullingPlaneIndex, inMask, outMask);
}

bool Box::culledBy(
    const Array<Plane>&		plane,
	int&				    cullingPlaneIndex,
	const uint32			inMask) const {

	return culledBy(plane.getCArray(), plane.size(), cullingPlaneIndex, inMask);
}

int Box::dummy = 0;

bool Box::culledBy(
    const class Plane*  plane,
    int                 numPlanes,
	int&				cullingPlane,
	const uint32		_inMask,
    uint32&             childMask) const {

	uint32 inMask = _inMask;
	assert(numPlanes < 31);

    childMask = 0;

    // See if there is one plane for which all of the
	// vertices are in the negative half space.
    for (int p = 0; p < numPlanes; p++) {

		// Only test planes that are not masked
		if ((inMask & 1) != 0) {

			Vector3 corner;

            int numContained = 0;
            int v = 0;

            // We can early-out only if we have found one point on each
            // side of the plane (i.e. if we are straddling).  That
            // occurs when (numContained < v) && (numContained > 0)
			for (v = 0; (v < 8) && ((numContained == v) || (numContained == 0)); ++v) {
                if (plane[p].halfSpaceContains(getCorner(v))) {
                    ++numContained;
                }
			}

			if (numContained == 0) {
				// Plane p culled the box
				cullingPlane = p;

                // The caller should not recurse into the children,
                // since the parent is culled.  If they do recurse,
                // make them only test against this one plane, which
                // will immediately cull the volume.
                childMask = 1 << p;
				return true;

            } else if (numContained < v) {
                // The bounding volume straddled the plane; we have
                // to keep testing against this plane
                childMask |= (1 << p);
            }
		}

        // Move on to the next bit.
		inMask = inMask >> 1;
    }

    // None of the planes could cull this box
	cullingPlane = -1;
    return false;
}

bool Box::culledBy(
    const class Plane*  plane,
    int                 numPlanes,
	int&				cullingPlane,
	const uint32		_inMask) const {

	uint32 inMask = _inMask;
	assert(numPlanes < 31);

    // See if there is one plane for which all of the
	// vertices are in the negative half space.
    for (int p = 0; p < numPlanes; p++) {

		// Only test planes that are not masked
		if ((inMask & 1) != 0) {

			bool culled = true;

            int v;

			// Assume this plane culls all points.  See if there is a point
			// not culled by the plane... early out when at least one point
            // is in the positive half space.
			for (v = 0; (v < 8) && culled; ++v) {
                culled = ! plane[p].halfSpaceContains(getCorner(v));
			}

			if (culled) {
				// Plane p culled the box
				cullingPlane = p;

				return true;
            }
		}

        // Move on to the next bit.
		inMask = inMask >> 1;
    }

    // None of the planes could cull this box
	cullingPlane = -1;
    return false;
}

bool Box::contains(
    const Vector3&      point) const {

    // Form axes from three edges, transform the point into that
    // space, and perform 3 interval tests

    Vector3 u = _corner[4] - _corner[0];
    Vector3 v = _corner[3] - _corner[0];
    Vector3 w = _corner[1] - _corner[0];

    Matrix3 M = Matrix3(u.x, v.x, w.x,
                        u.y, v.y, w.y,
                        u.z, v.z, w.z);

    // M^-1 * (point - _corner[0]) = point in unit cube's object space
    // compute the inverse of M
    Vector3 osPoint = M.inverse() * (point - _corner[0]);

    return
        (osPoint.x >= 0) &&
        (osPoint.y >= 0) &&
        (osPoint.z >= 0) &&
        (osPoint.x <= 1) &&
        (osPoint.y <= 1) &&
        (osPoint.z <= 1);
}

#undef setMany

void Box::getRandomSurfacePoint(Vector3& P, Vector3& N) const {
    float aXY = _extent.x * _extent.y;
    float aYZ = _extent.y * _extent.z;
    float aZX = _extent.z * _extent.x;

    float r = (float)random(0, aXY + aYZ + aZX);

    // Choose evenly between positive and negative face planes
    float d = (random(0, 1) < 0.5f) ? -1.0f : 1.0f;

    // The probability of choosing a given face is proportional to
    // its area.
    if (r < aXY) {
        P = _axis[0] * (float)random(-0.5, 0.5) * _extent.x +
            _axis[1] * (float)random(-0.5, 0.5) * _extent.y +
            _center + _axis[2] * d * _extent.z * 0.5f;
        N = _axis[2] * d;
    } else if (r < aYZ) {
        P = _axis[1] * (float)random(-0.5, 0.5) * _extent.y +
            _axis[2] * (float)random(-0.5, 0.5) * _extent.z +
            _center + _axis[0] * d * _extent.x * 0.5f;
        N = _axis[0] * d;
    } else {
        P = _axis[2] * (float)random(-0.5, 0.5) * _extent.z +
            _axis[0] *(float) random(-0.5, 0.5) * _extent.x +
            _center + _axis[1] * d * _extent.y * 0.5f;
        N = _axis[1] * d;
    }
}

Vector3 Box::randomInteriorPoint() const {
    Vector3 sum = _center;

    for (int a = 0; a < 3; ++a) {
        sum += _axis[a] * (float)random(-0.5, 0.5) * _extent[a];
    }

    return sum;
}

void Box::getBounds(class AABox& aabb) const {

    Vector3 lo = _corner[0];
    Vector3 hi = lo;

    for (int v = 1; v < 8; ++v) {
        const Vector3& C = _corner[v];
        lo = lo.min(C);
        hi = hi.max(C);
    }

    aabb = AABox(lo, hi);
}

} // namespace

#line 1 ".\\G3Dcpp\\Cone.cpp"
/**
 @file Cone.cpp

 Cone class

 @maintainer Morgan McGuire, matrix@graphics3d.com

 @created 2001-07-09
 @edited  2006-01-29
*/

#include "G3D/platform.h"
#include "G3D/Cone.h"
#include "G3D/Line.h"
#include "G3D/Sphere.h"

namespace G3D {

Cone::Cone(const Vector3 &tip, const Vector3 &direction, float angle) {
    this->tip = tip;
    this->direction = direction.direction();
    this->angle = angle;

    assert(angle >= 0);
    assert(angle <= G3D_PI);
}

/**
 Forms the smallest cone that contains the box.  Undefined if
 the tip is inside or on the box.
 */
Cone::Cone(const Vector3& tip, const Box& box) {
    this->tip = tip;
    this->direction = (box.getCenter() - tip).direction();

    // Find the biggest angle
    float smallestDotProduct = direction.dot((box.corner(0) - tip).direction());

    for (int i = 1; i < 8; ++i) {
        float dp = direction.dot((box.corner(i) - tip).direction());

        assert(dp > 0);

        if (dp < smallestDotProduct) {
            smallestDotProduct = dp;
        }
    }

    angle = acosf(smallestDotProduct);
}

bool Cone::intersects(const Sphere& b) const {
    // If the bounding sphere contains the tip, then
    // they definitely touch.
    if (b.contains(this->tip)) {
        return true;
    }

    // Move the tip backwards, effectively making the cone bigger
    // to account for the radius of the sphere.

    Vector3 tip = this->tip - direction * b.radius / sinf(angle);

    return Cone(tip, direction, angle).contains(b.center);
}

bool Cone::contains(const Vector3& v) const {

    Vector3 d = (v - tip).direction();

    float x = d.dot(direction);

    return (x > 0) && (x >= cosf(angle));
}

}; // namespace

#line 1 ".\\G3Dcpp\\Cylinder.cpp"
/**
 @file Cylinder.cpp

 @maintainer Morgan McGuire, matrix@graphics3d.com

 @created 2003-02-07
 @edited  2006-02-18

 Copyright 2000-2006, Morgan McGuire.
 All rights reserved.
 */

#include "G3D/Cylinder.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/LineSegment.h"

namespace G3D {

Cylinder::Cylinder(class BinaryInput& b) {
	deserialize(b);
}

Cylinder::Cylinder() {
}

Cylinder::Cylinder(const Vector3& _p1, const Vector3& _p2, float _r)
	: p1(_p1), p2(_p2), mRadius(_r) {
}

void Cylinder::serialize(class BinaryOutput& b) const {
	p1.serialize(b);
	p2.serialize(b);
	b.writeFloat64(mRadius);
}

void Cylinder::deserialize(class BinaryInput& b) {
	p1.deserialize(b);
	p2.deserialize(b);
	mRadius = b.readFloat64();
}

Line Cylinder::getAxis() const {
	return Line::fromTwoPoints(p1, p2);
}

Vector3 Cylinder::getPoint1() const {
	return p1;
}

Vector3 Cylinder::getPoint2() const {
	return p2;
}

float Cylinder::radius() const {
	return mRadius;
}

float Cylinder::volume() const {
	return
		G3D_PI * square(mRadius) * (p1 - p2).magnitude();
}

float Cylinder::area() const {
	return
        // Sides
		(2.0f * G3D_PI * mRadius) * height() +

        // Caps
        2.0f * G3D_PI * square(mRadius);
}

void Cylinder::getBounds(AABox& out) const {
    Vector3 min = p1.min(p2) - (Vector3(1, 1, 1) * mRadius);
    Vector3 max = p1.max(p2) + (Vector3(1, 1, 1) * mRadius);
    out = AABox(min, max);
}

bool Cylinder::contains(const Vector3& p) const {
    return LineSegment::fromTwoPoints(p1, p2).distanceSquared(p) <= square(mRadius);
}

void Cylinder::getReferenceFrame(CoordinateFrame& cframe) const {
    cframe.translation = center();

    Vector3 Y = (p1 - p2).direction();
    Vector3 X = (abs(Y.dot(Vector3::unitX())) > 0.9) ? Vector3::unitY() : Vector3::unitX();
    Vector3 Z = X.cross(Y).direction();
    X = Y.cross(Z);
    cframe.rotation.setColumn(0, X);
    cframe.rotation.setColumn(1, Y);
    cframe.rotation.setColumn(2, Z);
}

void Cylinder::getRandomSurfacePoint(Vector3& p, Vector3& N) const {
    float h = height();
    float r = radius();

    // Create a random point on a standard cylinder and then rotate to the global frame.

    // Relative areas (factor of 2PI already taken out)
    float capRelArea  = square(r) / 2.0f;
    float sideRelArea = r * h;

    float r1 = random(0, capRelArea * 2 + sideRelArea);

    if (r1 < capRelArea * 2) {

        // Select a point uniformly at random on a disk
        // @cite http://mathworld.wolfram.com/DiskPointPicking.html
        float a = random(0, G3D_TWO_PI);
        float r2 = sqrt(random(0, 1)) * r;
        p.x = cos(a) * r2;
        p.z = sin(a) * r2;

        N.x = 0;
        N.z = 0;
        if (r1 < capRelArea) {
            // Top
            p.y = h / 2.0f;
            N.y = 1;
        } else {
            // Bottom
            p.y = -h / 2.0f;
            N.y = -1;
        }
    } else {
        // Side
        float a = random(0, G3D_TWO_PI);
        N.x = cos(a);
        N.y = 0;
        N.z = sin(a);
        p.x = N.x * r;
        p.z = N.y * r;
        p.y = random(-h / 2.0f, h / 2.0f);
    }

    // Transform to world space
    CoordinateFrame cframe;
    getReferenceFrame(cframe);

    p = cframe.pointToWorldSpace(p);
    N = cframe.normalToWorldSpace(N);
}

Vector3 Cylinder::randomInteriorPoint() const {
    float h = height();
    float r = radius();

    // Create a random point in a standard cylinder and then rotate to the global frame.

    // Select a point uniformly at random on a disk
    // @cite http://mathworld.wolfram.com/DiskPointPicking.html
    float a = random(0, G3D_TWO_PI);
    float r2 = sqrt(random(0, 1)) * r;

    Vector3 p(  cos(a) * r2,
                random(-h / 2.0f, h / 2.0f),
                sin(a) * r2);

    // Transform to world space
    CoordinateFrame cframe;
    getReferenceFrame(cframe);

    return cframe.pointToWorldSpace(p);
}

} // namespace

#line 1 ".\\G3Dcpp\\MeshBuilder.cpp"
/**
  @file MeshBuilder.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2002-02-27
  @edited  2005-02-24
 */

#include "G3D/MeshBuilder.h"
#include "G3D/MeshAlg.h"

namespace G3D {

void MeshBuilder::setName(const std::string& n) {
    name = n;
}

void MeshBuilder::commit(std::string& n, Array<int>& indexArray, Array<Vector3>& outvertexArray) {
    n = name;

    // Make the data fit in a unit cube
    centerTriList();

    Array<int> toNew, toOld;

    if (close == MeshBuilder::AUTO_WELD) {
        Array<int> index;
        MeshAlg::createIndexArray(triList.size(), index);
        double minEdgeLen, maxEdgeLen, meanEdgeLen, medianEdgeLen;
        double minFaceArea, maxFaceArea, meanFaceArea, medianFaceArea;
        MeshAlg::computeAreaStatistics(triList, index,
            minEdgeLen, meanEdgeLen, medianEdgeLen, maxEdgeLen,
            minFaceArea, meanFaceArea, medianFaceArea, maxFaceArea);
        close = minEdgeLen * 0.1;
    }

    MeshAlg::computeWeld(triList, outvertexArray, toNew, toOld, close);

    // Construct triangles
    for (int t = 0; t < triList.size(); t += 3) {
        int index[3];

        for (int i = 0; i < 3; ++i) {
           index[i] = toNew[t + i];
        }

        // Throw out zero size triangles
        if ((index[0] != index[1]) &&
            (index[1] != index[2]) &&
            (index[2] != index[0])) {
            indexArray.append(index[0], index[1], index[2]);
        }
    }
}

void MeshBuilder::centerTriList() {
    // Compute the range of the vertices
    Vector3 vmin, vmax;

    computeBounds(vmin, vmax);

    Vector3 diagonal = vmax - vmin;
    double scale = max(max(diagonal.x, diagonal.y), diagonal.z) / 2;
    debugAssert(scale > 0);

    Vector3 translation = vmin + diagonal / 2;

    // Center and scale all vertices in the input list
    int v;

    //Matrix3 rot90 = Matrix3::fromAxisAngle(Vector3::UNIT_Y, toRadians(180)) * Matrix3::fromAxisAngle(Vector3::UNIT_X, toRadians(90));
    for (v = 0; v < triList.size(); ++v) {
        triList[v] = (triList[v] - translation) / scale;
        //triList[v] = rot90 * triList[v];
    }
}

void MeshBuilder::computeBounds(Vector3& min, Vector3& max) {
    min = Vector3::INF3;
    max = -min;

    int v;
    for (v = 0; v < triList.size(); ++v) {
        min = min.min(triList[v]);
        max = max.max(triList[v]);
    }
}

void MeshBuilder::addTriangle(const Vector3& a, const Vector3& b, const Vector3& c) {
    triList.append(a, b, c);

	if (_twoSided) {
	    triList.append(c, b, a);
	}
}

void MeshBuilder::addQuad(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d) {
    addTriangle(a, b, c);
    addTriangle(a, c, d);
}

void MeshBuilder::addTriangle(const Triangle& t) {
	addTriangle(t.vertex(0), t.vertex(1), t.vertex(2));
}

} // namespace

#line 1 ".\\G3Dcpp\\PhysicsFrame.cpp"
/**
 @file PhysicsFrame.cpp

 @maintainer Morgan McGuire, matrix@graphics3d.com

 @created 2002-07-09
 @edited  2006-01-25
*/

#include "G3D/PhysicsFrame.h"

namespace G3D {

PhysicsFrame::PhysicsFrame() {
    translation = Vector3::zero();
    rotation    = Quat();
}

PhysicsFrame::PhysicsFrame(
    const CoordinateFrame& coordinateFrame) {

    translation = coordinateFrame.translation;
    rotation    = Quat(coordinateFrame.rotation);
}

PhysicsFrame PhysicsFrame::operator*(const PhysicsFrame& other) const {
    PhysicsFrame result;

    result.rotation = rotation * other.rotation;
    result.translation = translation + rotation.toRotationMatrix() * other.translation;

    return result;
}

CoordinateFrame PhysicsFrame::toCoordinateFrame() const {
    CoordinateFrame f;

    f.translation = translation;
    f.rotation    = rotation.toRotationMatrix();

    return f;
}

PhysicsFrame PhysicsFrame::lerp(
    const PhysicsFrame&     other,
    float                   alpha) const {

    PhysicsFrame result;

    result.translation = translation.lerp(other.translation, alpha);
    result.rotation    = rotation.slerp(other.rotation, alpha);

    return result;
}

PhysicsFrame PhysicsFrame::integrate(
    float                   t,
    const PhysicsFrame&     dx) {

    PhysicsFrame result;

    result.translation = translation + t * dx.translation;
    result.rotation    = rotation * dx.rotation.pow(t);

    return result;
}

PhysicsFrame PhysicsFrame::integrate(
    float                   t,
    const PhysicsFrame&     dx,
    const PhysicsFrame&     ddx) {

    PhysicsFrame result;

    // TODO: is this correct?
    result.translation = translation + t * dx.translation + t * t * ddx.translation;
    result.rotation    = rotation * dx.rotation.pow(t) * ddx.rotation.pow(t * t);

    return result;
}

void PhysicsFrame::deserialize(class BinaryInput& b) {
    translation.deserialize(b);
    rotation.deserialize(b);
}

void PhysicsFrame::serialize(class BinaryOutput& b) const {
    translation.serialize(b);
    rotation.serialize(b);
}

}; // namespace

#line 1 ".\\G3Dcpp\\Ray.cpp"
/**
 @file Ray.cpp

 @maintainer Morgan McGuire, matrix@graphics3d.com

 @created 2002-07-12
 @edited  2004-03-19
 */

#include "G3D/Ray.h"
#include "G3D/CollisionDetection.h"

namespace G3D {

Ray::Ray(class BinaryInput& b) {
	deserialize(b);
}

void Ray::serialize(class BinaryOutput& b) const {
	origin.serialize(b);
	direction.serialize(b);
}

void Ray::deserialize(class BinaryInput& b) {
	origin.deserialize(b);
	direction.deserialize(b);
}

Ray Ray::refract(
    const Vector3&  newOrigin,
    const Vector3&  normal,
    float           iInside,
    float           iOutside) const {

    Vector3 D = direction.refractionDirection(normal, iInside, iOutside);
    return Ray::fromOriginAndDirection(
        newOrigin + (direction + normal * (float)sign(direction.dot(normal))) * 0.001f, D);
}

Ray Ray::reflect(
    const Vector3&  newOrigin,
    const Vector3&  normal) const {

    Vector3 D = direction.reflectionDirection(normal);
    return Ray::fromOriginAndDirection(newOrigin + (D + normal) * 0.001f, D);
}

Vector3 Ray::intersection(const Plane& plane) const {
    float d;
    Vector3 normal = plane.normal();
    plane.getEquation(normal, d);
    float rate = direction.dot(normal);

    if (rate >= 0.0f) {
        return Vector3::inf();
    } else {
        float t = -(d + origin.dot(normal)) / rate;

        return origin + direction * t;
    }
}

float Ray::intersectionTime(const class Sphere& sphere) const {
    Vector3 dummy;
    return CollisionDetection::collisionTimeForMovingPointFixedSphere(
            origin, direction, sphere, dummy);
}

float Ray::intersectionTime(const class Plane& plane) const {
    Vector3 dummy;
    return CollisionDetection::collisionTimeForMovingPointFixedPlane(
            origin, direction, plane, dummy);
}

float Ray::intersectionTime(const class Box& box) const {
    Vector3 dummy;
    float time = CollisionDetection::collisionTimeForMovingPointFixedBox(
            origin, direction, box, dummy);

    if ((time == inf()) && (box.contains(origin))) {
        return 0.0f;
    } else {
        return time;
    }
}

float Ray::intersectionTime(const class AABox& box) const {
    Vector3 dummy;
    bool inside;
    float time = CollisionDetection::collisionTimeForMovingPointFixedAABox(
            origin, direction, box, dummy, inside);

    if ((time == inf()) && inside) {
        return 0.0f;
    } else {
        return time;
    }
}

}

#line 1 ".\\glg3dcpp\\edgeFeatures.cpp"
/**
 @file edgeFeatures.cpp

 @maintainer Morgan McGuire, morgan@graphics3d.com

 @created 2004-04-20
 @edited  2004-04-25
 */

#include "GLG3D/edgeFeatures.h"
#include "GLG3D/RenderDevice.h"
#include "GLG3D/VAR.h"

namespace G3D {

void drawFeatureEdges(RenderDevice* renderDevice, const PosedModelRef& model, float creaseAngle) {

    float dotThreshold = max(cosf(creaseAngle), 0.0f);

    bool drawCreases = (creaseAngle <= G3D_PI / 2);

    const Vector3 wsEye = renderDevice->getCameraToWorldMatrix().translation;

    const Array<MeshAlg::Edge>&     edgeArray   = model->weldedEdges();
    const Array<Vector3>&           faceNormal  = model->objectSpaceFaceNormals(drawCreases);
    const Array<MeshAlg::Face>&     faceArray   = model->weldedFaces();
    const Array<Vector3>&           vertexArray = model->objectSpaceGeometry().vertexArray;

    // Work in the object space of the model so we don't
    // have to transform the geometry.
    const CoordinateFrame           cframe      = model->coordinateFrame();
    const Vector3                   eye         = cframe.pointToObjectSpace(wsEye);

    // Compute backfaces
    static Array<bool> backface;
    backface.resize(faceNormal.size(), DONT_SHRINK_UNDERLYING_ARRAY);
    for (int f = faceNormal.size() - 1; f >= 0; --f) {
        // View vector
        const Vector3 V = (eye - vertexArray[faceArray[f].vertexIndex[0]]);
        backface[f] = faceNormal[f].dot(V) < 0;
    }

    // Find contour edges
    static Array<Vector3> cpuVertexArray;
    cpuVertexArray.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);
    for (int e = edgeArray.size() - 1; e >= 0; --e) {
        const MeshAlg::Edge& edge = edgeArray[e];

        const int f0 = edge.faceIndex[0];
        const int f1 = edge.faceIndex[1];

        if (
            // Boundaries:
            (f0 == MeshAlg::Face::NONE) ||
            (f1 == MeshAlg::Face::NONE) ||

            // Contours:
            (backface[f0] ^ backface[f1]) ||

            // Front-face creases:
            (drawCreases &&
             (faceNormal[f0].dot(faceNormal[f1]) <= dotThreshold) &&
             ! (backface[f0] && backface[f1]))) {

            cpuVertexArray.append(
                vertexArray[edge.vertexIndex[0]],
                vertexArray[edge.vertexIndex[1]]);
        }
    }

    VARAreaRef varArea = VARArea::create(cpuVertexArray.size() * sizeof(Vector3));
    VAR gpuVertexArray(cpuVertexArray, varArea);

    renderDevice->pushState();
        renderDevice->setObjectToWorldMatrix(cframe);
        renderDevice->beginIndexedPrimitives();
            renderDevice->setVertexArray(gpuVertexArray);
            renderDevice->sendSequentialIndices(RenderDevice::LINES, cpuVertexArray.size());
        renderDevice->endIndexedPrimitives();
    renderDevice->popState();
}

}

#include "tool/ShootTools.h"

namespace RBX {
PV RocketTool::launch(const UIEvent& event, const G3D::CoordinateFrame& frame) {
    G3D::Vector3 hit;
    G3D::Vector3 forward = getPart(event, 0, hit) ? (hit-frame.translation).direction() : frame.lookVector();
    G3D::CoordinateFrame result;
    result.lookAt(forward);
    G3D::Vector3 position;
    position = forward;
    position *= 5.0f;
    position += frame.translation;
    result.translation = position;
    return PV(result, Velocity::zero());
}
}

#include "util/Units.h"
#include "v8kernel/Constants.h"
#include <math.h>

namespace RBX {
float __cdecl ballisticAngle(float,float,float,float);
PV SlingshotTool::launch(const UIEvent& event,const G3D::CoordinateFrame& frame) {
 float unused1=0,unused2=0;
 G3D::Vector3 hit;
 PartInstance* part=getPart(event,0,hit);
 G3D::Vector3 direction=part?(hit-frame.translation).direction():frame.lookVector();
 G3D::Vector3 position=frame.translation+direction*3.0f;
 if(!part){
  G3D::CoordinateFrame launchFrame(position);
  return PV(launchFrame,Velocity(direction*85.0f,G3D::Vector3::zero()));
 } else {
  G3D::Vector3 delta=hit;delta-=position;
  float height=delta.y;delta.y=0;
  float distance=delta.unitize(0.000001f);
  float angle=ballisticAngle(85.0f,distance,height,Units::kmsAccelerationToRbx(Constants::getKmsGravity()).y);
  delta.y=sinf(angle);
  float c=cosf(angle);
  delta.x*=c;delta.z*=c;
  G3D::CoordinateFrame launchFrame(position);
  return PV(launchFrame,Velocity(delta*85.0f,G3D::Vector3::zero()));
 }
}
int SlingshotTool::getShootSound() { return 6; }
}

#include "axis-vector-negation/G3D/Vector3.h"
#include "G3D/Vector3.h"
#include "G3D/g3dmath.h"
#include "G3D/stringutils.h"
#include "G3D/TextInput.h"
#include "G3D/TextOutput.h"
#include "G3D/Vector3int16.h"
#include "G3D/Matrix3.h"
#include "G3D/Vector2.h"

namespace G3D {
Vector2 Vector3::xy() const  { return Vector2       (x, y); }
}
