#undef _RELEASEASSERT // 004b7f20 builds its ConstProperty without RBXASSERT(isMemberOf): 00570c40 has one caller in the exe
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "util/standardout.h"
#include "BitStream.h"
#include "security/SecurityContext.h"
#include "v8datamodel/PartInstance.h"
#include <typeinfo>

namespace RBX
{
	// Same inline definition as AppUnit558_2008Instance.cpp (reflection/member.h only declares it); the target inlines it.
	template<>
	inline Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::ConstIterator&
	Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::ConstIterator::operator++()
	{
		++iter;
		return *this;
	}

	namespace Network
	{
		const Instance* Replicator::getDefault(const Name& className)
		{
			Security::Impersonator impersonate(Security::Replicator);

			std::map<const Name*, boost::shared_ptr<Instance> >::iterator iter = defaultObjects.find(&className);

			if (iter == defaultObjects.end())
			{
				boost::shared_ptr<Instance> instance = AbstractFactoryProduct<Instance>::create(className);

				if (!instance)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Replication: Can't create default object of type %s", className.c_str());
				}

				defaultObjects[&className] = instance;
				return instance.get();
			}
			else
			{
				return iter->second.get();
			}
		}

		SharedStringDictionary& Replicator::getSharedDictionary(const Reflection::PropertyDescriptor& descriptor)
		{
			std::map<const Reflection::PropertyDescriptor*, boost::shared_ptr<SharedStringDictionary> >::iterator iter = strings.find(&descriptor);

			if (iter == strings.end())
			{
				boost::shared_ptr<SharedStringDictionary> result(new SharedStringDictionary);

				strings[&descriptor] = result;
				return *result;
			}
			else
			{
				return *iter->second;
			}
		}

		void Replicator::serializeValue(const Reflection::ConstProperty& property, bool, RakNet::BitStream& stream)
		{
			if (property.getDescriptor().type == Reflection::Type::singleton<std::string>())
				getSharedDictionary(property.getDescriptor()).serializeString(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<bool>())
				stream << property.getValue<bool>();
			else if (property.getDescriptor().type == Reflection::Type::singleton<int>())
				stream << property.getValue<int>();
			else if (property.getDescriptor().type == Reflection::Type::singleton<float>())
				stream << property.getValue<float>();
			else if (property.getDescriptor().type == Reflection::Type::singleton<double>())
				serialize<double>(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<BrickColor>())
				serialize<BrickColor>(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<G3D::Color3>())
				serialize<G3D::Color3>(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<G3D::Vector3>())
			{
				if (&property.getDescriptor() == &PartInstance::prop_Size)
					writeBrickVector(stream, property.getValue<G3D::Vector3>());
				else
					serialize<G3D::Vector3>(property, stream);
			}
			else if (property.getDescriptor().type == Reflection::Type::singleton<G3D::CoordinateFrame>())
				serialize<G3D::CoordinateFrame>(property, stream);
			else if (dynamic_cast<const Reflection::EnumPropertyDescriptor*>(&property.getDescriptor()))
				serializeEnum(property, stream);
			else if (dynamic_cast<const Reflection::RefPropertyDescriptor*>(&property.getDescriptor()))
				serializeRef(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<ContentId>())
				serialize<std::string>(property, stream);
		}

		// 004b7f20 (name INFERRED, see Replicator2008.h; getDefault 004b4bb0, serializeValue 004b6890,
		void Replicator::writeProperties(const Instance* instance, RakNet::BitStream& stream)
		{
			const Instance* defaultInstance = getDefault(instance->getClassName());

			Reflection::ConstPropertyIterator iter = instance->properties_begin();
			Reflection::ConstPropertyIterator end = instance->properties_end();
			for (; iter != end; ++iter)
			{
				Reflection::ConstProperty property(iter.getDescriptor(), instance);
				if (property.getDescriptor().canStreamWrite() && &property.getDescriptor() != &Instance::propParent)
				{
					if (typeid(bool) == property.getDescriptor().type.type)
					{
						serializeValue(property, false, stream);
						if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
							StandardOut::singleton()->print(MESSAGE_INFO, "   write %s %s, 1 bit", property.getDescriptor().type.name.c_str(), property.getDescriptor().name.c_str());
					}
					else if (defaultInstance && property.getDescriptor().equalValues(instance, defaultInstance))
					{
						stream << true;
						if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
							StandardOut::singleton()->print(MESSAGE_INFO, "   write %s %s, 1 bit (default)", property.getDescriptor().type.name.c_str(), property.getDescriptor().name.c_str());
					}
					else
					{
						int bits = stream.GetNumberOfBitsUsed();
						stream << false;
						serializeValue(property, false, stream);
						if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
							StandardOut::singleton()->print(MESSAGE_INFO, "   write %s %s, %d bits", property.getDescriptor().type.name.c_str(), property.getDescriptor().name.c_str(), stream.GetNumberOfBitsUsed() - bits);
					}
				}
			}
		}
	}

	template boost::shared_ptr<Network::Replicator::ReplicatorStatsItem>
	Creatable<Instance>::create<Network::Replicator::ReplicatorStatsItem, boost::shared_ptr<Network::Replicator>,
								RakNetStatistics*>(boost::shared_ptr<Network::Replicator>, RakNetStatistics*); // 004b7e50
}

template class boost::shared_ptr<RBX::Network::Replicator::ReplicatorStatsItem>;
template class boost::shared_ptr<RBX::Network::Replicator>;

#include "Network/Players.h"
#include "RakPeerInterface.h"
#include "v8datamodel/ModelInstance.h"

namespace RBX
{
	namespace Network
	{
		Replicator::ItemSender::~ItemSender()
		{
			int bytesUsed = bitStream.GetNumberOfBytesUsed();
			if (bytesUsed > 0)
			{
				Item::writeItemType(bitStream, Item::ItemTypeEnd);
				peer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, replicator.remotePlayerId, false);
			}
			bitStream.Reset(); // outside the if in the target (jle lands on the Reset call)
		}

		void Replicator::Item::writeItemType(RakNet::BitStream& stream, ItemType value)
		{
			if (value >= ItemTypeDelete && value <= ItemTypeChangeProperty)
			{
				stream.WriteBits((unsigned char*)&value, 2, true);
			}
			else
			{
				unsigned char zero = 0;
				stream.WriteBits(&zero, 2, true);
				stream.Write(value);
			}
		}

		void Replicator::MarkerItem::write(RakNet::BitStream& bitStream)
		{
			writeItemType(bitStream, ItemTypeMarker);
			bitStream << (int)id;

			if (NetworkSettings::singleton().printInstances)
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Replication: Sending marker %d to %s", id, replicator.remotePlayerId.ToString(true));
			}

			replicator.onSentMarker(id);
		}

		bool Replicator::remoteDeleteOnDisconnect(const Instance* instance) const
		{
			// INFERRED: the target inlines the first level of Instance::isDescendentOf (004ab960 compares the +0x104
			const Instance* ancestor = players;
			Instance* parent = instance->parent;
			if (ancestor == parent || (parent && parent->isDescendentOf(ancestor)))
				return true;

			if (instance == Players::findLocalCharacter(instance))
				return true;

			return false;
		}

		void Replicator::closeReplicationItem(const std::pair<const Instance* const, ReplicationData>& item)
		{
			item.second.connection0.disconnect();
			item.second.connection1.disconnect();
			if (item.second.removeOnClose)
				item.second.instance->setParent(NULL);
		}
	}
}
