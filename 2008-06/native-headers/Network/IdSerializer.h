#pragma once
// >>> native-status (generated) -- do not edit >>>
// IdSerializer | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src b62f39fd | roc native-status --write
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

namespace RBX
{
	namespace Reflection
	{
		class RefPropertyDescriptor;
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
		};

		class StringReceiver
		{
			friend struct ::NativeReplicatorLayout;
		private:
			std::string strings[256];                                                 // +0x00
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
		};
	}
}
