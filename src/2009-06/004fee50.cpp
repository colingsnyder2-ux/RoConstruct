// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
struct SystemAddress
{
	unsigned int binaryAddress;
	unsigned short port;
	bool operator==( const SystemAddress& right ) const;
	bool operator!=( const SystemAddress& right ) const;
};
class RakPeer
{
public:
	struct RemoteSystemStruct
	{
		bool isActive;
		SystemAddress systemAddress;
		char pad[0x13c8-0xc];
		enum ConnectMode {NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK, REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET, CONNECTED} connectMode;
		int pad2;
	};
protected:
	bool ValidSendTarget(SystemAddress systemAddress, bool broadcast);
public:
	char pad0[8];
	unsigned short maximumNumberOfPeers;
	char pad1[0x53c-0xa];
	RemoteSystemStruct* remoteSystemList;
};
bool RakPeer::ValidSendTarget(SystemAddress systemAddress, bool broadcast)
{
	unsigned remoteSystemIndex;
	for ( remoteSystemIndex = 0; remoteSystemIndex < maximumNumberOfPeers; remoteSystemIndex++ )
	{
		if ( remoteSystemList[ remoteSystemIndex ].isActive &&
			remoteSystemList[ remoteSystemIndex ].connectMode==RakPeer::RemoteSystemStruct::CONNECTED &&
			( ( broadcast == false && remoteSystemList[ remoteSystemIndex ].systemAddress == systemAddress ) ||
			( broadcast == true && remoteSystemList[ remoteSystemIndex ].systemAddress != systemAddress ) )
			)
			return true;
	}
	return false;
}
