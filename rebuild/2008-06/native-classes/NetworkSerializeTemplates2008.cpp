// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::serialize<T> / deserialize<T> generic instances of the Replicator unit
// (004acd30..004ae7d0, inactive). Declarations: native-headers/AppUnit49C_2008/Streaming2008.h (template, body not
// in the header). Bodies are the donor tools/rbxgs/Client/Network/Streaming.h generic ones (read-only): serialize =
// operator<<(stream, property.getValue<T>()); deserialize = T value; operator>>(stream, value); setValue<T>.
// The 2008 deserialize guards the setValue with property.getInstance() (cmp [ecx+4],0 in 004adac0), as the
// BrickColor specialization 004a75b0 does. ConstProperty::getValue<T> / Property::setValue<T> are separate bodies
// (004accd0, 004ad2a0, ...) with the checked dynamic_cast shape of AppUnit49C_2008Streaming.cpp.
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
