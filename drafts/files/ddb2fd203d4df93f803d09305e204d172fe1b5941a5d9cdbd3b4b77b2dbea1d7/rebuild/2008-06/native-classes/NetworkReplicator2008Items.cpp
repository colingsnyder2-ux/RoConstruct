// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#undef _RELEASEASSERT // 004b6d10 builds its ConstProperty without RBXASSERT(isMemberOf) (as NetworkReplicator2008StatsItem.cpp)
// 2008-06 native RBX::Network::Replicator item/sender rows (inactive): Replicator::ItemSender::~ItemSender 004aba60,
// Replicator::MarkerItem::write 004ae9a0, Replicator::remoteDeleteOnDisconnect 004ab960, ChangePropertyItem::write
// 004b6d10 (near miss), getPlayer 004ae860, closeConnection 004aafd0, requestCharacter 004b49e0 and the +0x2c38 map
// members (implicit ReplicationData destructor 004ab8c0). Shapes after the donor
// tools/rbxgs Client/Network/Replicator.cpp; declarations in native-headers/Network/Replicator2008.h.
#define UTIL_SCOPEDASSIGN_H // TRIAL1
namespace RBX { template<class T> class ScopedAssign { public: ScopedAssign(T& value, T newValue) : value(&value), oldValue(value) { value = newValue; } ~ScopedAssign() { *value = oldValue; } private: T* value; T oldValue; }; }
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "Network/Players.h"
#include "util/standardout.h"
#include "RakPeerInterface.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "v8datamodel/ModelInstance.h"
#include "BitStream.h"
#include "Network/Player.h"
#include <typeinfo>
#include "v8datamodel/PartInstance.h" // PartInstance::prop_Size (deserializeValue 004b6ab0)
#include "util/scopedassign.h"
#include "v8datamodel/Camera.h" // wantReplicate 004aaf90
#include <stdexcept>

namespace RBX
{
	// Same inline shape as the ConstIterator definition in NetworkReplicator2008StatsItem.cpp (reflection/member.h
	// only declares it); readProperties 004b6f00 inlines the checked vector-iterator increment.
	template<>
	inline Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::Iterator&
	Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::Iterator::operator++()
	{
		++iter;
		return *this;
	}

	namespace Network
	{
		// 004aba60: a partly filled packet is terminated with ItemTypeEnd and sent (peer slot 0x34 Send, MEDIUM_PRIORITY,
		// RELIABLE_ORDERED, channel 0, remotePlayerId, no broadcast), then the stream is reset.
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

		// 004ab5d0 (donor Replicator::Item::writeItemType): Delete/New/ChangeProperty are 2-bit codes, every other type is
		// the 2-bit escape 0 followed by the full 32-bit value.
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

		// 004ae9a0
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

		// 004ab960 (virtual slot 20): exact with the donor if/else inline isDescendentOf shape (helper above), which lays
		// the `mov al,1; ret 4` block first. Rejected: raw member comparison with `if (...) return true` (59 B, block
		// order swapped), locals, single `return a || b` (63 B), direct `return instance == findLocalCharacter` (63 B).
		// INFERRED: the donor v8tree/Instance.h inline isDescendentOf body (if/else form); the native Instance.h declares
		// it out of line only (00422ae0), so the inlined first level is spelled here.
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
			// The target inlines the first level of Instance::isDescendentOf (004ab960 compares the +0x104 parent with
			// players, then calls 00422ae0 on the parent).
			if (isDescendentOfInline(instance, players))
				return true;

			if (instance == Players::findLocalCharacter(instance))
				return true;

			return false;
		}

		// 004b6d10 (donor Replicator::ChangePropertyItem::write; statement order after the server-verified mined analog
		// src/2008-06/004b6d10.cpp). The 2008 replication-scope test is a lookup of the instance in the +0x2c38 map
		// (find 004adfd0) instead of the donor isInReplicationScope; writeItemType 004ab5d0, serializeId 004a8ae0,
		// propNames.send 004aeba0, NetworkSettings printProperties (+0x132), registerGuid 0049bba0,
		// Guid::readableString 004aadd0, "Replication: %s:%s.%s >> %s" 0082501c, serializeValue 004b6890.
		// NEAR MISS (nw04 b23, parked after 3 hypotheses): 491 B vs 490 B. The target loads the instance pointer once into
		// edi before registerGuid and keeps it (lea ebp,[edi+0x10] for getClassName, lea ecx,[edi+8] for the guid); this
		// compile reloads [esi+0xc] after the call. Rejected: (1) separate registerGuid statement on instance.get()
		// (515 B, plus an RBXASSERT compare fixed by the #undef above); (2) a local Instance* for registerGuid /
		// getClassName / getGuid (482 B, lea ebp computed after the call); (3) this comma form inside the argument list.
		// Likely needs the 2008 GuidItem::getGuid() that registers itself (util/GuidItem.h proposal).
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
					// Guid::readableString reads it inline (the 2008 getGuid() registers first; util/GuidItem.h proposal).
					StandardOut::singleton()->print(MESSAGE_INFO, "Replication: %s:%s.%s >> %s",
						instance->getClassName().c_str(),
						(const_cast<Instance*>(instance.get())->registerGuid(), instance->getGuid()).readableString(4).c_str(),
						desc.name.c_str(),
						replicator.remotePlayerId.ToString(true));
				}

				replicator.serializeValue(Reflection::ConstProperty(desc, instance.get()), true, bitStream);
			}
		}

		// 004afc70 (donor Replicator::NewInstanceItem constructor; identity: stores vtable 00824b20 whose slot 1 is the
		// write 004b8620, called from the descendant-added handler 004aff70 after new(0x10)). The 2008 constructor also
		// records the instance in pendingNewInstances +0x2c90 (set insert 005e8c40, identical-code folded).
		Replicator::NewInstanceItem::NewInstanceItem(Replicator& replicator, const boost::shared_ptr<Instance>& instance)
			: Item(replicator),
			  instance(instance)
		{
			replicator.pendingNewInstances.insert(instance.get());
		}

		// 004afe90 (donor Replicator::DeleteInstanceItem constructor; vtable 00824b2c, slot 1 write 004b47b0, which
		// erases the instance from pendingDeleteInstances as the donor DeleteInstanceItem::write does). The 2008
		// constructor records the instance in pendingDeleteInstances +0x2cb0 (same folded set insert 005e8c40).
		Replicator::DeleteInstanceItem::DeleteInstanceItem(Replicator& replicator, const boost::shared_ptr<const Instance>& instance)
			: Item(replicator),
			  instance(instance)
		{
			replicator.pendingDeleteInstances.insert(instance.get());
		}

		// INFERRED: donor Replicator.cpp inline helper (no standalone body in the client: onParentChanged 004b01e0
		// tests the set erase 005e9f60 result through `setne al; test al,al`).
		inline bool Replicator::removeFromPendingNewInstances(const Instance* instance)
		{
			bool removed = pendingNewInstances.erase(instance) != 0;
			return removed;
		}

		// 004b01e0 (donor Replicator::onParentChanged; identity: the parent lookup in the +0x2c38 map (find
		// 004adfd0 on instance +0x104), new(0x14) ChangePropertyItem with Instance::propParent 00973d34 and
		// shared_ptr<Item> 004ac160, else disconnectReplicationData 004afd00, pendingNewInstances erase and new(0x10)
		// DeleteInstanceItem 004afe90 with shared_ptr<Item> 004ac1f0; list push_back 004ad860 / 004acb50).
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

		// 004b6f00 (donor Replicator::readProperties; identity: the reader twin of writeProperties 004b7f20, strings
		// "   read %s %s, 1 bit" 00825070, "   read %s %s, 1 bit (default)" 00825050, "   read %s %s, %d bits"
		// 00825038; operator>>(bool) 004a5b30, setValue<bool> 004ad1e0, deserializeValue 004b6ab0, NetworkSettings
		// printInstances +0x131 / printProperties +0x132, StandardOut::print 005693a0). Every streamed property except
		// Instance::propParent: a bool is read in place, any other first reads the "equals default" bit.
		// NEAR MISS (nw01 b26, parked): 791 of 846 bytes, identical except that the target expands the StandardOut
		// shared_ptr release after the "1 bit" print (lock xadd pair) where this compile calls ~shared_ptr 00600660,
		// the same residual as writeProperties 004b7f20. Rejected: (1) every read through property.getDescriptor()
		// (815 B, frame 4 bytes short, stream kept in ebx); (2) the named descriptor reference below fixed the frame.
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

		// 004b6ab0 (donor Replicator::deserializeValue; identity: the mirror of serializeValue 004b6890 with the same
		// Type::singleton order 0056cdf0 .. 0056cd80, reading through operator>> 004a5b30 / 004a6250 and the
		// deserialize<T> instances 004adac0 (float), 004ae7d0 (double), 004a75b0 (BrickColor), 004adaf0 (Color3),
		// 004acdb0 (Vector3), 004adb20 (CoordinateFrame), deserializeEnum 004a5a70, StringReceiver::deserializeString
		// 004a7150 at SharedStringDictionary +0xe24, readBrickVector 004a67c0 for PartInstance::prop_Size 00976148 and
		// deserialize<std::string> 004a6d60 for ContentId). ScopedAssign<const Property*> over deserializeProperty
		// +0x2cd4 (restored at the shared exit). bool / int are expanded in place (setValue<bool> 004ad1e0, <int>
		// 004ad240 behind the property.getInstance() test), the other types call their deserialize<T>.
		// The Ref branch calls IdSerializer::deserializeRef (thiscall 004a9440, declared in Network/IdSerializer.h).
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

		// 004b7a30 (donor Replicator::readChangedProperty; identity: strings "Replication: %s-%s.%s << %s" 0082515c
		// and "Replication rejected property: %s-%s.%s << %s" 0082512c, deserializeInstanceRef 004a8b60, the inline
		// propNames receive (+0x2c30 bits, +0x2c24 descriptors), printProperties +0x132, Guid::Data::readableString
		// 005a8440, SystemAddress::ToString 004a98b0, virtual slot 16 (replicates) on the instance, deserializeValue
		// 004b6ab0). The 2008 body reads a rejected property into a property without instance (the value is still
		// consumed from the stream) instead of the donor skipValue, and records the property name at +0x2d60.
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

#define NATIVE_REPLICATOR_DESERIALIZE_REF // TRIAL
#ifdef NATIVE_REPLICATOR_DESERIALIZE_REF
		// 004b0800 (donor Replicator::readInstanceDelete; identity: strings "Replication: ~%s:%d << %s" 00824b4c,
		// "NULL" 00824858, "Replication ~??? << %s" 00824b34, deserializeInstanceRef 004a8b60, shared_from<Instance>
		// 00618a40, printInstances +0x131, disconnectReplicationData 004afd00, pendingNewInstances erase 005e9f60,
		// ScopedAssign of removingInstance +0x2cd8 around Instance::setParent(NULL) 0055a8f0, then
		// IdSerializer::resolvePendingBindings(NULL, id) 004a9250). The 2008 print guards the class name against a
		// NULL instance and prints the received id rather than the instance guid.
		// NEAR MISS, parked (nw01 b27; all callees now declared, compiled with the guard defined): 623 of 627 B. The
		// target reloads `instance` ([esp+0x54]) after the ScopedAssign store `mov [esi],ecx` and before setParent;
		// this compile reuses ecx (downstream: the hold shared_ptr release blocks are laid out in the other order).
		// Rejected: (1) pendingNewInstances.erase(instance) instead of the inline helper (608 B); (2) a
		// `const Instance*` removingInstance with ScopedAssign<const Instance*> (scratch header; still 623 B);
		// (3) `Instance* instance = NULL` (632 B, prologue differs). Guarded only because it is not exact.
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

		// 004ae860 (donor Replicator.h inline getPlayer; findTargetPlayer slot 17, shared_from<Player> 00618a40)
		boost::shared_ptr<Instance> Replicator::getPlayer()
		{
			return shared_from(findTargetPlayer());
		}

		// 004aaf90 (donor Replicator::wantReplicate, vtable 008254fc slot 18; identity: decorated name
		// ?wantReplicate@Replicator@Network@RBX@@MBE_NPBVInstance@3@@Z, __RTDynamicCast from Instance 0092907c to
		// Camera 0093ab54, `sete al`, ret 4).
		bool Replicator::wantReplicate(const Instance* source) const
		{
			return dynamic_cast<const Camera*>(source) == NULL ? true : false;
		}

		// 004aafd0 (donor Replicator::closeConnection; the 2008 body tests peer first): CloseConnection slot 0x64.
		void Replicator::closeConnection()
		{
			if (peer)
				peer->CloseConnection(remotePlayerId, true);
			setParent(NULL);
		}

		// 004b49e0 (donor Replicator::requestCharacter; the 2008 body first throws without a connection):
		// "Attempting to send a Character request without a connection" 00824da8 / "... without a local Player"
		// 00824d68, operator<<(uchar) 004a6350 with 0x4c (2008 ID_REQUEST_CHARACTER), serializeId 004a8ae0,
		// printInstances (+0x131), registerGuid 0049bba0, Guid::Data::readableString 005a8440,
		// "Replicator: Requesting character for %s" 00824d40, Send(MEDIUM_PRIORITY, RELIABLE_ORDERED, 0).
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

		// 004ab850 (static; template-instance caller: for_each over containerConnections +0x2c38)
		void Replicator::closeReplicationItem(const std::pair<const Instance* const, ReplicationData>& item)
		{
			item.second.connection0.disconnect();
			item.second.connection1.disconnect();
			if (item.second.removeOnClose)
				item.second.instance->setParent(NULL);
		}
	}
}

// Template members emitted by this unit: the containerConnections (+0x2c38) map, whose node destruction emits the
// implicit Replicator::ReplicationData destructor 004ab8c0 (two ~connection 00595370, then the shared_ptr release).
template class std::map<const RBX::Instance*, RBX::Network::Replicator::ReplicationData>;
