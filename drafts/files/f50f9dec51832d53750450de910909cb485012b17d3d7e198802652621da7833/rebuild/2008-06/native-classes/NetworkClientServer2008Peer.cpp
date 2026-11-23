// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Peer (inactive); evidence in native-headers/Network/Peer2008.h.
// Verified by tests/record_native_network_client_server2008.py. Original bodies: constructor 004b4640, destructor
// 004ac830, deleting destructor 004ad7a0, classDescriptor 0049ea10 (atexit 007fba70).
#include "Network/Peer2008.h"

namespace RBX
{
	namespace Network
	{
		const char sPeer[] = "NetworkPeer"; // 008244d8 (classDescriptor 0049ea10)

		Peer::Peer()
			: profilePacketsThread(new Profiling::CodeProfiler("Packets Thread"))
		{
			rakPeer.reset(new ProfiledRakPeer(profilePacketsThread.get()));
			rakPeer->AttachPlugin(this);
		}

		Peer::~Peer()
		{
			rakPeer->DetachPlugin(this);
		}

		// 00609a30 (identical-code folded; donor Replicator.cpp Peer::peerInterface)
		RakPeerInterface* Peer::peerInterface()
		{
			return rakPeer.get();
		}
	}
}

// 004ac9e0 Peer::logPackets (INFERRED name; registry placeholder func_004ac9e0): the setter of the reflected function
// BoundFuncDesc<Peer, void(bool), 1> "LogPackets" ("value" 00822468; static init 007f2260 -> 004b4240, descriptor
// 009716c8). The 2007 OpenRBX analog is Peer::updateLogger (NetworkSettings::logPackets); the 2008 body takes the flag
// and replaces the logger unconditionally when enabling: new(0x210) FilePacketLogger(this) 004ab630, rakPeer slot 58
// AttachPlugin (+0xe8); disabling calls slot 59 DetachPlugin (+0xec) before the scoped_ptr reset.
// BLOCKED (guard below): Network/Peer2008.h (not this batch's file) does not declare logPackets; the proposal adds
// `void logPackets(bool value);` to Peer (public, after updateNetworkSimulator) and defines
// PEER_HEADER_DECLARES_LOGPACKETS (measured against a scratch copy, batch 43 nr03).
#ifdef PEER_HEADER_DECLARES_LOGPACKETS
// Unit-local redeclaration of native-headers/Replicator.h FilePacketLogger (that header redefines Peer, so it cannot be
// included next to Network/Peer2008.h); identical to the Replicator.h declaration.
class FilePacketLogger : public PacketLogger
{
private:
	FILE* packetLogFile;
	
public:
	FilePacketLogger(RBX::Network::Peer*);
	virtual ~FilePacketLogger();
	virtual void OnAttach(RakPeerInterface* peer);
	virtual void WriteLog(const char*);
	// INFERRED: 004aae00 is the UserIDTOString vftable override identified by class RTTI and link order.
	virtual char* UserIDTOString(unsigned char id);
};

namespace RBX
{
	namespace Network
	{
		void Peer::logPackets(bool value)
		{
			if (!value)
			{
				if (logger)
				{
					rakPeer->DetachPlugin(logger.get());
					logger.reset();
				}
			}
			else
			{
				logger.reset(new FilePacketLogger(this));
				rakPeer->AttachPlugin(logger.get());
			}
		}
	}
}
#endif

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::scoped_ptr<PacketLogger>;
template class boost::scoped_ptr<RBX::Profiling::CodeProfiler>;
