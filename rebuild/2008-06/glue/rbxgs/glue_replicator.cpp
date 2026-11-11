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

		// a job sender takes jobs until its packet is full (SimJobStage::reportJobs)
		bool Replicator::JobSender::operator()(SimJob& mechanism)
		{
			return report(mechanism);
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

		void Replicator::sendPhysicsData(RakNet::BitStream& bitStream, const SimJob& mechanism)
		{
			if (mechanism.getAssembly())
				sendPhysicsData(bitStream, *mechanism.getAssembly());
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


		// a replicator is a live connection, never part of a saved place
		// instances this connection created are removed when it drops

	}
}
