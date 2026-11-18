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
			void serializeRef(const Reflection::ConstProperty& property, RakNet::BitStream& stream); // 004a8b90
				public:
			void deserializeId(RakNet::BitStream &,RBX::Guid::Data &);   // INFERRED: ?deserializeId@IdSerializer@Network@RBX@@QAEXAAVBitStream@RakNet@@AAUData@Guid@3@@Z (header gap, header_gap_fill.py)
};
	}
}
