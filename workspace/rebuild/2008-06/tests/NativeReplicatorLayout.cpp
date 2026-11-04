// Layout probe for the inactive native Network::IdSerializer / string dictionaries / Marker headers;
// tests/record_native_replicator.py checks each function body is `mov eax, imm32; ret` with the value from the binary:
//   sizeof(StringSender) 0xe24          SharedStringDictionary constructor 004b3d10 builds StringReceiver at +0xe24
//   sizeof(SharedStringDictionary) 0x2a24  IdSerializer constructor 004b94a0: scopeNames +0x130, waitItems +0x2b54
//   sizeof(IdSerializer) 0x2b74         Replicator RTTI 008254fc: PluginInterface at +0x2b74
//   sizeof(Marker) 0x10                 newMarker 004b9190 allocates 0x10
// Field offsets are compile-time asserts (NativeReplicatorLayout is a friend of each class). Built with only
// native headers.
#include <stddef.h>
#include "Network/IdSerializer.h"
#include "Network/ReplicatorMarker.h"

struct NativeReplicatorLayout
{
	typedef RBX::Network::StringSender S;
	typedef RBX::Network::IdSerializer I;
	typedef RBX::Network::Marker M;
	typedef char SenderDictionary[offsetof(S, dictionary) == 0x0 ? 1 : -1];
	typedef char SenderStrings[offsetof(S, strings) == 0x20 ? 1 : -1];
	typedef char SenderLastIndex[offsetof(S, lastIndex) == 0xe20 ? 1 : -1];
	typedef char ReceiverStrings[offsetof(RBX::Network::StringReceiver, strings) == 0x0 ? 1 : -1];
	typedef char ScopeNames[offsetof(I, scopeNames) == 0x130 ? 1 : -1];
	typedef char WaitItems[offsetof(I, waitItems) == 0x2b54 ? 1 : -1];
	typedef char WaitItemSize[sizeof(I::WaitItem) == 0xc ? 1 : -1];
	typedef char Returned[offsetof(M, returned) == 0xc ? 1 : -1];
};

int nativeStringSenderSize() { return sizeof(RBX::Network::StringSender); }
int nativeStringReceiverOffset() { return (int)(size_t)static_cast<RBX::Network::StringReceiver*>((RBX::Network::SharedStringDictionary*)0x1000) - 0x1000; }
int nativeSharedStringDictionarySize() { return sizeof(RBX::Network::SharedStringDictionary); }
int nativeIdSerializerSize() { return sizeof(RBX::Network::IdSerializer); }
int nativeMarkerSize() { return sizeof(RBX::Network::Marker); }
