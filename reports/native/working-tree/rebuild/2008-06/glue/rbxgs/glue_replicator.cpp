// Rebuild glue: Network::Replicator members rbxgs declares and calls but never defines.
// Behavioural reconstruction in rbxgs's own wire format (the item types and id/string serializers in
// Replicator.cpp and Streaming.cpp); it is NOT the 2008 protocol. The 2008 Replicator differs
// (property dictionary, physics sender/receiver objects); its layout is recovered in the exact 2008
// unit for Replicator::Replicator at 0x4b9bd0 and is the base for porting this later.
#include "Replicator.h"
#include "PacketIds.h"
#include "NetworkSettings.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Mechanism.h"
#include "v8world/Assembly.h"
#include "v8world/Primitive.h"
#include "util/standardout.h"
#include "BitStream.h"
#include "GetTime.h"

namespace RBX
{
	namespace Network
	{
		void rebuildRegisterGuid(const Instance* instance);  // glue_guid_registry.cpp

		// a job sender takes mechanisms until its packet is full (SimJobStage::reportMechanisms)
		bool Replicator::JobSender::operator()(Mechanism& mechanism)
		{
			return report(mechanism);
		}

		Replicator::Item::~Item()
		{
		}

		Replicator::NewInstanceItem::NewInstanceItem(Replicator& replicator, const boost::shared_ptr<Instance>& instance)
			: Item(replicator), instance(instance)
		{
		}

		// id, class, then every streamable property in descriptor order, then the parent's id
		void Replicator::NewInstanceItem::write(RakNet::BitStream& bitStream)
		{
			if (!replicator.pendingNewInstances.erase(instance.get()))
				return;

			writeItemType(bitStream, ItemTypeNew);
			replicator.serializeId(bitStream, instance.get());
			replicator.classNames.send(bitStream, instance->getClassName());

			typedef Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor> Properties;
			const Properties& properties = instance->getDescriptor();
			for (Properties::CollectionType::const_iterator iter = properties.descriptors_begin(); iter != properties.descriptors_end(); ++iter)
				if ((*iter)->canStreamWrite())
					replicator.serializeValue(Reflection::ConstProperty(**iter, instance.get()), true, bitStream);

			replicator.serializeId(bitStream, instance->getParent());
		}

		void Replicator::serializeValue(const Reflection::ConstProperty& property, bool useDictionary, RakNet::BitStream& bitStream)
		{
			const Reflection::PropertyDescriptor& desc = property.getDescriptor();
			const Reflection::Type& type = desc.type;

			if (dynamic_cast<const Reflection::EnumPropertyDescriptor*>(&desc))
				serializeEnum(property, bitStream);
			else if (dynamic_cast<const Reflection::RefPropertyDescriptor*>(&desc))
				serializeRef(property, bitStream);
			else if (type == Reflection::Type::singleton<std::string>())
			{
				if (useDictionary)
					getSharedDictionary(desc).serializeString(property, bitStream);
				else
					bitStream << property.getValue<std::string>();
			}
			else if (type == Reflection::Type::singleton<bool>())
				bitStream << property.getValue<bool>();
			else if (type == Reflection::Type::singleton<int>())
				bitStream << property.getValue<int>();
			else if (type == Reflection::Type::singleton<float>())
				bitStream << property.getValue<float>();
			else if (type == Reflection::Type::singleton<G3D::Vector3>())
				bitStream << property.getValue<G3D::Vector3>();
			else if (type == Reflection::Type::singleton<G3D::Color3>())
				bitStream << property.getValue<G3D::Color3>();
			else if (type == Reflection::Type::singleton<G3D::CoordinateFrame>())
				bitStream << property.getValue<G3D::CoordinateFrame>();
			else if (type == Reflection::Type::singleton<BrickColor>())
				bitStream << property.getValue<BrickColor>().asInt();
			else if (type == Reflection::Type::singleton<ContentId>())
				bitStream << property.getValue<ContentId>().toString();
			else
				StandardOut::singleton()->print(MESSAGE_ERROR, "Replication: cannot send property %s", desc.name.c_str());
		}

		void Replicator::deserializeValue(RakNet::BitStream& bitStream, bool useDictionary, Reflection::Property& property)
		{
			const Reflection::PropertyDescriptor& desc = property.getDescriptor();
			const Reflection::Type& type = desc.type;

			if (dynamic_cast<const Reflection::EnumPropertyDescriptor*>(&desc))
				deserializeEnum(property, bitStream);
			else if (dynamic_cast<const Reflection::RefPropertyDescriptor*>(&desc))
				deserializeRef(property, bitStream);
			else if (type == Reflection::Type::singleton<std::string>())
			{
				if (useDictionary)
					getSharedDictionary(desc).deserializeString(property, bitStream);
				else
				{
					std::string value;
					bitStream >> value;
					property.setValue(value);
				}
			}
#define RBX_REBUILD_READ(T) \
			else if (type == Reflection::Type::singleton<T>()) \
			{ \
				T value; \
				bitStream >> value; \
				property.setValue(value); \
			}
			RBX_REBUILD_READ(bool)
			RBX_REBUILD_READ(int)
			RBX_REBUILD_READ(float)
			RBX_REBUILD_READ(G3D::Vector3)
			RBX_REBUILD_READ(G3D::Color3)
#undef RBX_REBUILD_READ
			else if (type == Reflection::Type::singleton<G3D::CoordinateFrame>())
			{
				G3D::CoordinateFrame value;
				bitStream >> value.translation;
				for (int r = 0; r < 3; ++r)
					for (int c = 0; c < 3; ++c)
						bitStream >> value.rotation[r][c];
				property.setValue(value);
			}
			else if (type == Reflection::Type::singleton<BrickColor>())
			{
				int value;
				bitStream >> value;
				property.setValue(BrickColor(value));
			}
			else if (type == Reflection::Type::singleton<ContentId>())
			{
				std::string value;
				bitStream >> value;
				property.setValue(ContentId(value));
			}
		}

		void Replicator::readInstanceNew(RakNet::BitStream& bitStream)
		{
			Guid::Data id;
			deserializeId(bitStream, id);
			const Name* className = NULL;
			classNames.receive(bitStream, className);

			boost::shared_ptr<Instance> instance = AbstractFactoryProduct<Instance>::create(*className);
			if (!instance)
				throw std::runtime_error("Replication: unknown class " + className->toString());
			instance->assignGuid(id);
			rebuildRegisterGuid(instance.get());

			typedef Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor> Properties;
			const Properties& properties = instance->getDescriptor();
			for (Properties::CollectionType::const_iterator iter = properties.descriptors_begin(); iter != properties.descriptors_end(); ++iter)
			{
				if ((*iter)->canStreamWrite())
				{
					Reflection::Property property(**iter, instance.get());
					deserializeValue(bitStream, true, property);
				}
			}

			Instance* parent = NULL;
			deserializeInstanceRef(bitStream, parent);
			setCameFromRemotePlayer(instance.get());
			instance->setParent(parent);
			resolvePendingBindings(instance.get(), id);
		}

		void Replicator::readInstanceDelete(RakNet::BitStream& bitStream)
		{
			Instance* instance = NULL;
			if (deserializeInstanceRef(bitStream, instance) && instance)
				instance->setParent(NULL);
		}

		void Replicator::readChangedProperty(RakNet::BitStream& bitStream)
		{
			Instance* instance = NULL;
			deserializeInstanceRef(bitStream, instance);
			const Name* propName = NULL;
			propNames.receive(bitStream, propName);

			if (!instance)
			{
				skipValue(bitStream);
				return;
			}
			Reflection::PropertyIterator iter = instance->findProperty(*propName);
			if (iter == instance->properties_end())
			{
				skipValue(bitStream);
				return;
			}
			Reflection::Property property = *iter;
			deserializeValue(bitStream, true, property);
		}

		// unknown value: the stream cannot be resynchronised, so drop the rest of the packet
		void Replicator::skipValue(RakNet::BitStream& bitStream)
		{
			bitStream.IgnoreBits(bitStream.GetNumberOfUnreadBits());
		}

		void Replicator::sendPhysicsData(RakNet::BitStream& bitStream, const Mechanism& mechanism)
		{
			const std::set<Assembly*>& assemblies = mechanism.getAssemblies();
			for (std::set<Assembly*>::const_iterator iter = assemblies.begin(); iter != assemblies.end(); ++iter)
				sendPhysicsData(bitStream, **iter);
		}

		// root part id, frame, velocity
		void Replicator::sendPhysicsData(RakNet::BitStream& bitStream, const Assembly& assembly)
		{
			const PartInstance* part = PartInstance::fromPrimitiveConst(assembly.getAssemblyPrimitiveConst());
			if (!part || !trySerializeId(bitStream, part))
				return;
			bitStream << part->getCoordinateFrame();
			bitStream << part->getVelocity().linear;
			bitStream << part->getVelocity().rotational;
		}

		PluginReceiveResult Replicator::OnReceive_ID_TIMESTAMP(Packet* packet)
		{
			RakNet::BitStream bitStream(packet->data, packet->length, false);
			unsigned char id;
			RakNetTime time;
			bitStream >> id;
			bitStream.Read(time);
			bitStream >> id;
			if (id != ID_PHYSICS)
				return RR_CONTINUE_PROCESSING;

			Profiling::Mark mark(*profilePhysicsIn, false);
			while (true)
			{
				Instance* instance = NULL;
				if (!deserializeInstanceRef(bitStream, instance) || !instance)
					break;
				G3D::CoordinateFrame frame;
				Velocity velocity;
				bitStream >> frame.translation;
				for (int r = 0; r < 3; ++r)
					for (int c = 0; c < 3; ++c)
						bitStream >> frame.rotation[r][c];
				bitStream >> velocity.linear;
				bitStream >> velocity.rotational;
				if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
					part->setPhysics(frame, velocity);
			}
			return RR_STOP_PROCESSING_AND_DEALLOCATE;
		}

		PluginReceiveResult Replicator::OnReceive(RakPeerInterface* peer, Packet* packet)
		{
			if (packet->systemAddress != remotePlayerId)
				return RR_CONTINUE_PROCESSING;

			switch (packet->data[0])
			{
			case ID_DATA:
				receiveData(packet);
				return RR_STOP_PROCESSING_AND_DEALLOCATE;
			case ID_TIMESTAMP:
				return OnReceive_ID_TIMESTAMP(packet);
			default:
				return RR_CONTINUE_PROCESSING;
			}
		}

		// a replicator is a live connection, never part of a saved place
		XmlElement* Replicator::write()
		{
			return NULL;
		}

		void Replicator::onSentMarker(long)
		{
		}

		// instances this connection created are removed when it drops
		bool Replicator::remoteDeleteOnDisconnect(const Instance* instance) const
		{
			return getCameFromRemotePlayer(instance);
		}

		void Replicator::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			Instance::onServiceProvider(oldProvider, newProvider);
			if (newProvider)
				connectToReplicationContainers();
			else
				disconnectAllPropertyChangedConnections();
		}
	}
}
