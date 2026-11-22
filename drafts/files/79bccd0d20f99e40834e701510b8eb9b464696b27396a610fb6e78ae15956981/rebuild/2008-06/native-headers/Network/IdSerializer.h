#pragma once
// 2008-06 native RBX::Network::IdSerializer and its string dictionaries (inactive). Shape after the donor
// tools/rbxgs/Client/Network/Streaming.h; every base, field and size below is read from the 2008-06 binary:
//   RTTI       vtable 0082534c .?AVIdSerializer@Network@RBX@@ (18 bases): Instance only (no Described or
//              factory base; slots 2 and 3 are _purecall 0068e880, so IdSerializer is abstract).
//   size       0x2b74: Replicator (RTTI 008254fc) places PluginInterface at +0x2b74, directly after it.
//   fields     constructor 004b94a0 / destructor 004b9440:
//              +0x130 SharedStringDictionary scopeNames (constructor 004b3d10, destructor 004b3d70),
//              +0x2b54 std::map<Guid::Data, std::vector<WaitItem> > waitItems (map constructor 00699b30 called
//              with key_compare/allocator temporaries, destructor 004b93d0; _Myhead at +0x18 of the map).
//   StringSender: constructor 004b3c90 / destructor 004b36f0: +0x00 std::map dictionary (0x20 bytes),
//              +0x20 std::string strings[128] (eh vector 0x1c x 0x80), +0xe20 int lastIndex (constructed as 1).
//   StringReceiver: 2008 keeps a plain array, std::string strings[256] (SharedStringDictionary constructor
//              004b3d10 eh-vector-constructs 0x100 x 0x1c at +0xe24, destructor 004b3d70 destroys it before
//              calling ~StringSender 004b36f0); the donor's map<unsigned char, std::string> is a later shape.
#include "v8tree/Instance.h"
#include "util/Guid.h"
#include <boost/noncopyable.hpp>
#include <map>
#include <string>
#include <vector>

struct NativeReplicatorLayout;

namespace RakNet
{
	class BitStream;
}

namespace RBX
{
	class Name;

	namespace Reflection
	{
		class RefPropertyDescriptor;
		class ConstProperty;
		class Property;
	}

	namespace Network
	{
		class StringSender
		{
			friend struct ::NativeReplicatorLayout; // tests/NativeReplicatorLayout.cpp offset asserts
		private:
			std::map<std::string, unsigned char> dictionary;                          // +0x00
			std::string strings[128];                                                 // +0x20
			int lastIndex;                                                            // +0xe20

		public:
			StringSender()                                                            // 004b3c90
				: lastIndex(1)
			{
			}

			// Bodies in native-classes/AppUnit49C_2008IdSerializerTemplates.cpp (Network/Streaming.cpp unit).
			bool trySend(RakNet::BitStream& stream, const std::string& value);       // 004a7ba0
			void send(RakNet::BitStream& stream, const std::string& value);          // 004a7e20
			// Donor Streaming.h StringSender::serializeString (thiscall, ret 8; caller Replicator::serializeValue
			// 004b6890 passes getSharedDictionary 004b6730's result, StringSender at +0 of SharedStringDictionary).
			void serializeString(const Reflection::ConstProperty& property, RakNet::BitStream& stream); // 004a83e0
		};

		class StringReceiver
		{
			friend struct ::NativeReplicatorLayout;
		private:
			std::string strings[256];                                                 // +0x00

		public:
			// Bodies in native-classes/AppUnit49C_2008IdSerializerTemplates.cpp (Network/Streaming.cpp unit).
			void receive(RakNet::BitStream& stream, std::string& value);             // 004a6e20
			void receive(RakNet::BitStream& stream, const Name*& value);             // 004a6f70
		public:
			void deserializeString(Reflection::Property& property, RakNet::BitStream& bitStream);   // INFERRED (header-add): evidence: ?deserializeString@StringReceiver@Network@RBX@@QAEXAAVProperty@Reflection@3@AAVBitStream@RakNet@@@Z - byte-proved by 004a7150
		};

		class SharedStringDictionary : public StringSender, public StringReceiver, private boost::noncopyable
		{
		};

		class IdSerializer : public Instance
		{
			friend struct ::NativeReplicatorLayout;
		protected:
			// 0xc bytes: _Destroy_range<WaitItem> 004a79e0 (called from ~vector<WaitItem> 004a7fa0) steps by 0xc
			// and releases the shared_ptr count at +8 (instance at +4).
			struct WaitItem
			{
				const Reflection::RefPropertyDescriptor* desc;
				boost::shared_ptr<Instance> instance;
			};

		private:
			SharedStringDictionary scopeNames;                                        // +0x130
		protected:
			std::map<Guid::Data, std::vector<WaitItem> > waitItems;                   // +0x2b54

		public:
			IdSerializer() {}                                                         // 004b94a0

			// 004a8ae0 (donor Streaming.cpp IdSerializer::serializeId; thiscall, ret 8). No body yet: it reads the
			// argument's Guid after GuidItem<Instance>::registerGuid 0049bba0 (Guid::Data at +0x8/+0xc), and the
			// GuidItem<Instance> accessor for that guid is not declared in util/GuidItem.h.
			void serializeId(RakNet::BitStream& stream, const Instance* instance);
			// 004a8cc0 (registry placeholder func_004a8cc0; donor Streaming.h IdSerializer::trySerializeId): thiscall, ret 8,
			// returns bool in al; registerGuid 0049bba0, scopeNames +0x130 StringSender::trySend 004a7ba0 / send 004a7e20
			// (Name::getNullName 00554270), WriteBits 004a5600 (24 bits). Caller RoundRobinPhysicsSender::sendPhysicsData
			// 004caaf0 (this = [sender+0x4] = Replicator*, IdSerializer at +0). Body in native-classes/IdSerializerTrySerializeId.cpp.
			bool trySerializeId(RakNet::BitStream& stream, const Instance* instance);
			// Donor Streaming.h IdSerializer::serializeRef (thiscall, ret 8; caller Replicator::serializeValue 004b6890
			// passes the Replicator this unadjusted: IdSerializer at +0). Body in AppUnit49C_2008IdSerializerTemplates.cpp.
			void serializeRef(const Reflection::ConstProperty& property, RakNet::BitStream& stream); // 004a8b90
			// Donor Streaming.h IdSerializer::deserializeId (thiscall, ret 8): StringReceiver::receive(const Name*&)
			// 004a6f70 on scopeNames +0x130 + StringReceiver +0xe24 (= +0xf54). Body in AppUnit49C_2008IdSerializerTemplates.cpp.
			void deserializeId(RakNet::BitStream& stream, Guid::Data& id);           // 004a70b0
			// Donor Streaming.h IdSerializer::resolvePendingBindings (thiscall, ret 0xc: Guid::Data by value; callers
			// Replicator::readInstanceDelete 004b0800 / readInstanceNew 004b7250). Body in AppUnit49C_2008IdSerializerTemplates.cpp.
			void resolvePendingBindings(Instance* instance, Guid::Data id);          // 004a9250
			// Donor Streaming.h overload (thiscall, ret 0xc): deserializeId 004a70b0 with `this` passed through, then the
			// GuidItem<Instance> registry lookup 0049ba80; callers Replicator::readChangedProperty 004b7a30 and
			// readInstanceDelete 004b0800.
			bool deserializeInstanceRef(RakNet::BitStream& stream, Instance*& instance, Guid::Data& id); // 004a8b60
			// Donor Streaming.h IdSerializer::deserializeRef (thiscall, ret 8; caller Replicator::deserializeValue 004b6ab0).
			void deserializeRef(Reflection::Property& property, RakNet::BitStream& stream); // 004a9440
		protected:
			// Donor Streaming.h static IdSerializer::setRefValue (cdecl: 004a6de0 reads both arguments from the stack;
			// RefPropertyDescriptor slot 0x34 setRefValue with NULL-checked +0x14 adjustments). resolvePendingBindings
			// 004a9250 passes its address to std::for_each 004a7920 through boost::bind.
			static void setRefValue(WaitItem& wi, Instance* instance);              // 004a6de0
		};
	}
}
