#undef _RELEASEASSERT // 004b7f20 builds its ConstProperty without RBXASSERT(isMemberOf): 00570c40 has one caller in the exe
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "util/standardout.h"
#include "BitStream.h"
#include "RakPeerInterface.h"
#include "RakNetStatistics.h"
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

		void Replicator::ReplicatorStatsItem::update()
		{
			if (replicator->peer)
			{
				ping->formatValue(
					replicator->peer->GetLastPing(replicator->remotePlayerId),
					"%d avg:%d best:%d",
					replicator->peer->GetLastPing(replicator->remotePlayerId),
					replicator->peer->GetAveragePing(replicator->remotePlayerId),
					replicator->peer->GetLowestPing(replicator->remotePlayerId)
				);

				waitingRefs->formatValue(replicator->waitItems.size());

				// INFERRED: double holder (the donor has float ratio): the target divides with float conversions (fadd dword
				double ratio = (float)statistics->messagesTotalBitsResent / statistics->totalBitsSent;
				packetLoss->formatValue(ratio, "%.1g%%", ratio * 100.0);

				instanceSize->formatMem(instanceCount != 0 ? instanceBits / (instanceCount * 8) : 0);
			}
		}
	}

	template boost::shared_ptr<Network::Replicator::ReplicatorStatsItem>
	Creatable<Instance>::create<Network::Replicator::ReplicatorStatsItem, boost::shared_ptr<Network::Replicator>,
								RakNetStatistics*>(boost::shared_ptr<Network::Replicator>, RakNetStatistics*); // 004b7e50
}

template class boost::shared_ptr<RBX::Network::Replicator::ReplicatorStatsItem>;
template class boost::shared_ptr<RBX::Network::Replicator>;

#undef _RELEASEASSERT // 004b6d10 builds its ConstProperty without RBXASSERT(isMemberOf) (as NetworkReplicator2008StatsItem.cpp)
#include "Network/Players.h"
#include "v8datamodel/ModelInstance.h"
#include "Network/Player.h"
#include "v8datamodel/PartInstance.h" // PartInstance::prop_Size (deserializeValue 004b6ab0)
#include "util/scopedassign.h"
#include "v8datamodel/Camera.h" // wantReplicate 004aaf90
#include <stdexcept>

namespace RBX
{
	template<>
	inline Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::Iterator&
	Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::Iterator::operator++()
	{
		++iter;
		return *this;
	}

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

		// INFERRED: the donor v8tree/Instance.h inline isDescendentOf body (if/else form); the native Instance.h declares
		static inline bool isDescendentOfInline(const Instance* self, const Instance* ancestor)
		{
			Instance* thisParent = self->getParent();
			if (ancestor == thisParent)
				return true;

			if (thisParent)
				return thisParent->isDescendentOf(ancestor);
			else
				return false;
		}

		bool Replicator::remoteDeleteOnDisconnect(const Instance* instance) const
		{
			if (isDescendentOfInline(instance, players))
				return true;

			if (instance == Players::findLocalCharacter(instance))
				return true;

			return false;
		}

		void Replicator::ChangePropertyItem::write(RakNet::BitStream& bitStream)
		{
			if (replicator.containerConnections.find(instance.get()) != replicator.containerConnections.end())
			{
				writeItemType(bitStream, ItemTypeChangeProperty);

				replicator.serializeId(bitStream, instance.get());
				replicator.propNames.send(bitStream, desc);

				if (NetworkSettings::singleton().printProperties)
				{
					// INFERRED: the target registers the guid (0049bba0) inside the argument list, right before
					StandardOut::singleton()->print(MESSAGE_INFO, "Replication: %s:%s.%s >> %s",
						instance->getClassName().c_str(),
						(const_cast<Instance*>(instance.get())->registerGuid(), instance->getGuid()).readableString(4).c_str(),
						desc.name.c_str(),
						replicator.remotePlayerId.ToString(true));
				}

				replicator.serializeValue(Reflection::ConstProperty(desc, instance.get()), true, bitStream);
			}
		}

		Replicator::NewInstanceItem::NewInstanceItem(Replicator& replicator, const boost::shared_ptr<Instance>& instance)
			: Item(replicator),
			  instance(instance)
		{
			replicator.pendingNewInstances.insert(instance.get());
		}

		Replicator::DeleteInstanceItem::DeleteInstanceItem(Replicator& replicator, const boost::shared_ptr<const Instance>& instance)
			: Item(replicator),
			  instance(instance)
		{
			replicator.pendingDeleteInstances.insert(instance.get());
		}

		// INFERRED: donor Replicator.cpp inline helper (no standalone body in the client: onParentChanged 004b01e0
		inline bool Replicator::removeFromPendingNewInstances(const Instance* instance)
		{
			bool removed = pendingNewInstances.erase(instance) != 0;
			return removed;
		}

		void Replicator::onParentChanged(boost::shared_ptr<Instance> instance)
		{
			if (containerConnections.find(instance->getParent()) != containerConnections.end())
			{
				pendingItems.push_back(boost::shared_ptr<Item>(new ChangePropertyItem(*this, instance, Instance::propParent)));
			}
			else
			{
				disconnectReplicationData(instance);

				if (!removeFromPendingNewInstances(instance.get()))
				{
					pendingItems.push_back(boost::shared_ptr<Item>(new DeleteInstanceItem(*this, instance)));
				}
			}
		}

		void Replicator::readProperties(RakNet::BitStream& stream, Instance* instance)
		{
			Reflection::PropertyIterator iter = instance->properties_begin();
			Reflection::PropertyIterator end = instance->properties_end();
			for (; iter != end; ++iter)
			{
				Reflection::Property property = *iter;
				const Reflection::PropertyDescriptor& descriptor = property.getDescriptor();
				if (descriptor.canStreamWrite() && &descriptor != &Instance::propParent)
				{
					if (typeid(bool) == descriptor.type.type)
					{
						bool value;
						stream >> value;
						if (property.getInstance())
							property.setValue<bool>(value);
						if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
							StandardOut::singleton()->print(MESSAGE_INFO, "   read %s %s, 1 bit", descriptor.type.name.c_str(), descriptor.name.c_str());
					}
					else
					{
						bool equalValues;
						stream >> equalValues;
						if (equalValues)
						{
							if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
								StandardOut::singleton()->print(MESSAGE_INFO, "   read %s %s, 1 bit (default)", descriptor.type.name.c_str(), descriptor.name.c_str());
						}
						else
						{
							int bits = stream.GetReadOffset();
							deserializeValue(stream, property);
							if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
								StandardOut::singleton()->print(MESSAGE_INFO, "   read %s %s, %d bits", descriptor.type.name.c_str(), descriptor.name.c_str(), stream.GetReadOffset() - bits + 1);
						}
					}
				}
			}
		}

		void Replicator::deserializeValue(RakNet::BitStream& stream, Reflection::Property& property)
		{
			ScopedAssign<const Reflection::Property*> assign(deserializeProperty, &property);

			if (property.getDescriptor().type == Reflection::Type::singleton<std::string>())
				getSharedDictionary(property.getDescriptor()).deserializeString(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<bool>())
			{
				bool value;
				stream >> value;
				if (property.getInstance())
					property.setValue<bool>(value);
			}
			else if (property.getDescriptor().type == Reflection::Type::singleton<int>())
			{
				int value;
				stream >> value;
				if (property.getInstance())
					property.setValue<int>(value);
			}
			else if (property.getDescriptor().type == Reflection::Type::singleton<float>())
				deserialize<float>(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<double>())
				deserialize<double>(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<BrickColor>())
				deserialize<BrickColor>(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<G3D::Color3>())
				deserialize<G3D::Color3>(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<G3D::Vector3>())
			{
				if (&property.getDescriptor() == &PartInstance::prop_Size)
				{
					G3D::Vector3 value;
					readBrickVector(stream, value);
					if (property.getInstance())
						property.setValue<G3D::Vector3>(value);
				}
				else
					deserialize<G3D::Vector3>(property, stream);
			}
			else if (property.getDescriptor().type == Reflection::Type::singleton<G3D::CoordinateFrame>())
				deserialize<G3D::CoordinateFrame>(property, stream);
			else if (dynamic_cast<const Reflection::EnumPropertyDescriptor*>(&property.getDescriptor()))
				deserializeEnum(property, stream);
			else if (dynamic_cast<const Reflection::RefPropertyDescriptor*>(&property.getDescriptor()))
				deserializeRef(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<ContentId>())
				deserialize<std::string>(property, stream);
		}

		void Replicator::readChangedProperty(RakNet::BitStream& stream)
		{
			Instance* instance;
			Guid::Data id;
			deserializeInstanceRef(stream, instance, id);

			const Reflection::PropertyDescriptor* descriptor;
			propNames.receive(stream, descriptor);

			if (NetworkSettings::singleton().printProperties)
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Replication: %s-%s.%s << %s",
					instance ? instance->getClassName().c_str() : "?",
					id.readableString(4).c_str(),
					descriptor->name.c_str(),
					remotePlayerId.ToString(true));
			}

			if (!replicates(instance))
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, "Replication rejected property: %s-%s.%s << %s",
					instance ? instance->getClassName().c_str() : "?",
					id.readableString(4).c_str(),
					descriptor->name.c_str(),
					remotePlayerId.ToString(true));
				instance = NULL;
			}

			Reflection::Property property(*descriptor, instance);
			deserializeValue(stream, property);
			lastReceivedName = &descriptor->name;
		}

#ifdef NATIVE_REPLICATOR_DESERIALIZE_REF
		void Replicator::readInstanceDelete(RakNet::BitStream& stream)
		{
			Instance* instance;
			Guid::Data id;
			if (deserializeInstanceRef(stream, instance, id))
			{
				boost::shared_ptr<Instance> hold = shared_from(instance);

				if (NetworkSettings::singleton().printInstances)
				{
					StandardOut::singleton()->print(MESSAGE_INFO, "Replication: ~%s:%d << %s",
						instance ? instance->getClassName().c_str() : "NULL",
						id.readableString(4).c_str(),
						remotePlayerId.ToString(true));
				}

				if (disconnectReplicationData(hold))
				{
					removeFromPendingNewInstances(instance);

					ScopedAssign<Instance*> assign(removingInstance, instance);
					instance->setParent(NULL);
				}
			}
			else if (NetworkSettings::singleton().printInstances)
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Replication ~??? << %s", remotePlayerId.ToString(true));
			}

			resolvePendingBindings(NULL, id);
		}
#endif

		boost::shared_ptr<Instance> Replicator::getPlayer()
		{
			return shared_from(findTargetPlayer());
		}

		bool Replicator::wantReplicate(const Instance* source) const
		{
			return dynamic_cast<const Camera*>(source) == NULL ? true : false;
		}

		void Replicator::closeConnection()
		{
			if (peer)
				peer->CloseConnection(remotePlayerId, true);
			setParent(NULL);
		}

		void Replicator::requestCharacter()
		{
			if (!peer)
				throw std::runtime_error("Attempting to send a Character request without a connection");

			Player* player = findTargetPlayer();
			if (!player)
				throw std::runtime_error("Attempting to send a Character request without a local Player");

			RakNet::BitStream bitStream;
			bitStream << (unsigned char)0x4c; // ID_REQUEST_CHARACTER

			serializeId(bitStream, player);

			if (NetworkSettings::singleton().printInstances)
			{
				// INFERRED: the target registers the guid (0049bba0) before copying it inline (+8 / +0xc).
				player->registerGuid();
				Guid::Data id;
				player->getGuid().extract(id);

				StandardOut::singleton()->print(MESSAGE_INFO, "Replicator: Requesting character for %s", id.readableString(4).c_str());
			}

			peer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, remotePlayerId, false);
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

template class std::map<const RBX::Instance*, RBX::Network::Replicator::ReplicationData>;

namespace RBX { namespace Network {
bool Replicator::canSendItems() { return receivedGlobals; }
Player* Replicator::findTargetPlayer() { return players ? players->getLocalPlayer() : 0; }
} }
