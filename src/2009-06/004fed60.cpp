// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class RakPeer {
public:
	struct RemoteSystemStruct
	{
		bool isActive;
		char pad[0x1350-1];
		bool weInitiatedTheConnection;
		char pad2[0x13c8-0x1351];
		enum ConnectMode {NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK, REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET, CONNECTED} connectMode;
		int pad3;
	};
	virtual ~RakPeer();
protected:
	unsigned short GetNumberOfRemoteInitiatedConnections( void ) const;
	volatile bool endThreads; char padEt[3];
	unsigned short maximumNumberOfPeers;
	char pad0a[0x53c - 0xa];
	RemoteSystemStruct* remoteSystemList;
};
unsigned short RakPeer::GetNumberOfRemoteInitiatedConnections( void ) const
{
	unsigned short i, numberOfIncomingConnections;

	if ( remoteSystemList == 0 || endThreads == true )
		return 0;

	numberOfIncomingConnections = 0;

	for ( i = 0; i < maximumNumberOfPeers; i++ )
	{
		if ( remoteSystemList[ i ].isActive && remoteSystemList[ i ].weInitiatedTheConnection == false && remoteSystemList[i].connectMode==RemoteSystemStruct::CONNECTED)
			numberOfIncomingConnections++;
	}

	return numberOfIncomingConnections;
}
