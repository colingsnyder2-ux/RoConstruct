// =============================================================================
// IdSerializer.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/include/network/IdSerializer.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
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

			bool trySend(RakNet::BitStream& stream, const std::string& value);       // 004a7ba0
			void send(RakNet::BitStream& stream, const std::string& value);          // 004a7e20
			void serializeString(const Reflection::ConstProperty& property, RakNet::BitStream& stream); // 004a83e0
		};

		class StringReceiver
		{
			friend struct ::NativeReplicatorLayout;
		private:
			std::string strings[256];                                                 // +0x00

		public:
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

			void serializeId(RakNet::BitStream& stream, const Instance* instance);
			bool trySerializeId(RakNet::BitStream& stream, const Instance* instance);
			void serializeRef(const Reflection::ConstProperty& property, RakNet::BitStream& stream); // 004a8b90
			void deserializeId(RakNet::BitStream& stream, Guid::Data& id);           // 004a70b0
			void resolvePendingBindings(Instance* instance, Guid::Data id);          // 004a9250
			bool deserializeInstanceRef(RakNet::BitStream& stream, Instance*& instance, Guid::Data& id); // 004a8b60
			void deserializeRef(Reflection::Property& property, RakNet::BitStream& stream); // 004a9440
		protected:
			static void setRefValue(WaitItem& wi, Instance* instance);              // 004a6de0
		};
	}
}
