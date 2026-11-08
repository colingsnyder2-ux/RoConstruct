#pragma once
// 2008-06 native RBX::Network::Client (inactive). Shape after the donor tools/rbxgs Client/Network/Client.h; every
// base, field and virtual below is read from the 2008-06 binary:
//   RTTI       vtable 00822f4c .?AVClient@Network@RBX@@ (27 bases) -> DescribedCreatable<Client, Peer, sClient> (name
//              mangled $1?sClient@23@3PADA, a non-const char array in .data at 00938c88 holding "NetworkClient":
//              classDescriptor 0049eb30, constructor setName), the empty Service (mdisp 0x148) and
//              Listener<ServiceProvider, Closing> (mdisp 0x144, vtable 00822e88; MSVC places the vfptr-carrying
//              Listener first).
//   size       0x150: Creatable<Instance>::create<Client> 0049a1e0 allocates 0x150 (malloc) and calls the constructor
//              004a0990 (DescribedCreatable<Client> 0049ff10 -> FactoryProduct<Client> 0049eef0 -> Peer 004b4640,
//              then setName(sClient)).
//   fields     +0x148 SystemAddress serverId: the destructor 0049f2e0 and onEvent(Closing) 0049f130 pass +0x148/+0x14c
//              to rakPeer->CloseConnection(serverId, true, 0) (RakPeerInterface slot 25, +0x64).
//   vtable     slot 12 onServiceProvider 0049fe50, slot 14 write 00416690 (ICF-shared `return NULL`), PluginInterface
//              slot 5 OnReceive 004a1070, Listener<ServiceProvider, Closing> slot 0 onEvent 0049f130 (all declared
//              only); destructor 0049f2e0 (deleting 0049f4e0, adjustor thunks 0049f3b0..0049f450, 0049f420).
//   disconnect 0049f0f0: removeAllChildren 0055afd0, rakPeer->CloseConnection(serverId, true, 0),
//              rakPeer->Shutdown(blockDuration, 0) (slot 10, +0x28); onEvent(Closing) 0049f130 inlines it with 3000.
//   statics    clientIsPresent 0049fe20: ServiceProvider::find<Client>(findServiceProvider(context)) != NULL
//              (findServiceProvider 004898d0, ServiceProvider::find<Client> 0049fc50).
#include "Network/Peer2008.h"
#include "v8tree/Service.h"
#include "RakNetTypes.h"

class XmlElement;

namespace RBX
{
	namespace Network
	{
		extern char sClient[];

		class Client : public DescribedCreatable<Client, Peer, sClient>,
					   public Service,
					   public Listener<ServiceProvider, Closing>
		{
			friend struct ::NativeNetworkClientServer2008Layout; // NetworkClientServer2008Layout.cpp offset asserts

		private:
			SystemAddress serverId;                                                 // +0x148

		public:
			Client();                                                               // 004a0990
			virtual ~Client();                                                      // 0049f2e0
			virtual PluginReceiveResult OnReceive(RakPeerInterface* peer, Packet* packet); // 004a1070
			virtual XmlElement* write();                                            // 00416690 (ICF)
			void disconnect(int blockDuration);                                     // 0049f0f0 (inlined in 0049f130)

		protected:
			virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 0049fe50
			virtual void onEvent(const ServiceProvider* source, Closing event);    // 0049f130

		public:
			// 0049fe20 (evidence name ?clientIsPresent@Client@Network@RBX@@SA_NPBVInstance@3@_N@Z; the bool is not read)
			static bool clientIsPresent(const Instance* context, bool testInDatamodel);
		};
	}
}
