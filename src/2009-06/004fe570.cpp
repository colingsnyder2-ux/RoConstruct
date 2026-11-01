// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct SystemAddress {
	unsigned int binaryAddress;
	unsigned short port;
};
extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;
class RakPeer {
public:
	struct RemoteSystemStruct {
		bool isActive;
		SystemAddress systemAddress;
		char pad[0x13c8 - 0xc];
		enum ConnectMode { NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK, REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET, CONNECTED } connectMode;
		int tail;
	};
	virtual SystemAddress GetSystemAddressFromIndex(int index);
	int endThreads;
	unsigned short maximumNumberOfPeers;
	char pad[0x53c - 0xc];
	RemoteSystemStruct* remoteSystemList;
};
SystemAddress RakPeer::GetSystemAddressFromIndex(int index)
{
	if (index >= 0 && index < maximumNumberOfPeers)
		if (remoteSystemList[index].isActive && remoteSystemList[index].connectMode == RakPeer::RemoteSystemStruct::CONNECTED)
			return remoteSystemList[index].systemAddress;
	return UNASSIGNED_SYSTEM_ADDRESS;
}
