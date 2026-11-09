// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned int RakNetTime;
typedef unsigned __int64 RakNetTimeNS;
struct SystemAddress
{
	unsigned int binaryAddress;
	unsigned short port;
	SystemAddress& operator = ( const SystemAddress& input )
	{
		binaryAddress = input.binaryAddress;
		port = input.port;
		return *this;
	}
};
extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;
namespace RakNet { RakNetTime GetTime( void ); }
#define PING_TIMES_ARRAY_SIZE 5
class RPCMap { public: void Clear(void); };
class ReliabilityLayer {
public:
	void SetSplitMessageProgressInterval(int interval);
	void SetUnreliableTimeout(RakNetTime timeoutMS);
	void SetTimeoutTime(RakNetTime time);
	void SetEncryptionKey(const unsigned char *key);
	void Reset(bool resetVariables);
	char pad[0x1320];
};
namespace DataStructures {
template <class list_type> class List {
public:
	list_type* listArray; unsigned list_size; unsigned allocation_size;
	void Insert(const list_type input, const unsigned position);
	void Insert(const list_type input);
	unsigned Size(void) const { return list_size; }
};
template <class key_type, class data_type>
int defaultOrderedListComparison(const key_type &a, const data_type &b);
template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)=defaultOrderedListComparison<key_type, data_type> >
class OrderedList {
public:
	unsigned GetIndexFromKey(const key_type &key, bool *objectExists, int (*cf)(const key_type&, const data_type&)=default_comparison_function) const;
	unsigned Insert(const key_type &key, const data_type &data, bool assertOnDuplicate, int (*cf)(const key_type&, const data_type&)=default_comparison_function)
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists, cf);

		if (objectExists)
		{
			return (unsigned)-1;
		}

		if (index>=orderedList.Size())
		{
			orderedList.Insert(data);
			return orderedList.Size()-1;
		}
		else
		{
			orderedList.Insert(data,index);
			return index;
		}
	}
	List<data_type> orderedList;
};
}
struct SystemAddressAndIndex
{
	SystemAddress systemAddress;
	unsigned index;
};
int SystemAddressAndIndexComp( const SystemAddress &key, const SystemAddressAndIndex &data );
class RakPeer
{
public:
	struct PingAndClockDifferential
	{
		unsigned short pingTime;
		RakNetTime clockDifferential;
	};
	struct RemoteSystemStruct
	{
		bool isActive;
		SystemAddress systemAddress;
		SystemAddress myExternalSystemAddress;
		char pad0[0x30 - 0x14];
		ReliabilityLayer reliabilityLayer;
		bool weInitiatedTheConnection;
		PingAndClockDifferential pingAndClockDifferential[ PING_TIMES_ARRAY_SIZE ];
		int pingAndClockDifferentialWriteIndex;
		unsigned short lowestPing;
		RakNetTime nextPingTime;
		RakNetTime lastReliableSend;
		RakNetTime connectionTime;
		char pad1[0x13a0 - 0x1390];
		bool setAESKey;
		unsigned connectionSocketIndex;
		RPCMap rpcMap;
		char pad2[0x13c4 - 0x13a9];
		int MTUSize;
		enum ConnectMode {NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK, REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET, CONNECTED} connectMode;
		char pad3[0x13d0 - 0x13cc];
	};
	char pad0[8];
	unsigned short maximumNumberOfPeers;
	char pad1[0x53c - 0xa];
	RemoteSystemStruct* remoteSystemList;
	DataStructures::OrderedList<SystemAddress, SystemAddressAndIndex, SystemAddressAndIndexComp> remoteSystemLookup;
	char pad2[0xa4c - 0x54c];
	int defaultMTUSize;
	char pad3[0xa74 - 0xa50];
	RakNetTime defaultTimeoutTime;
	char pad4[0xb50 - 0xa78];
	int splitMessageProgressInterval;
	RakNetTime unreliableTimeout;
	RemoteSystemStruct *AssignSystemAddressToRemoteSystemList( const SystemAddress systemAddress, RemoteSystemStruct::ConnectMode connectionMode, unsigned connectionSocketIndex );
};
RakPeer::RemoteSystemStruct * RakPeer::AssignSystemAddressToRemoteSystemList( const SystemAddress systemAddress, RemoteSystemStruct::ConnectMode connectionMode, unsigned connectionSocketIndex )
{
	RemoteSystemStruct * remoteSystem;
	unsigned i,j;
	RakNetTime time = RakNet::GetTime();
	for ( i = 0; i < maximumNumberOfPeers; i++ )
	{
		if ( remoteSystemList[ i ].isActive==false )
		{
			remoteSystem=remoteSystemList+i;
			remoteSystem->rpcMap.Clear();
			remoteSystem->systemAddress = systemAddress;
			remoteSystem->MTUSize = defaultMTUSize;
			remoteSystem->isActive=true;
			remoteSystem->reliabilityLayer.SetSplitMessageProgressInterval(splitMessageProgressInterval);
			remoteSystem->reliabilityLayer.SetUnreliableTimeout(unreliableTimeout);
			remoteSystem->reliabilityLayer.SetTimeoutTime(defaultTimeoutTime);
			remoteSystem->reliabilityLayer.SetEncryptionKey( 0 );
			remoteSystem->connectionSocketIndex=connectionSocketIndex;

			for ( j = 0; j < (unsigned) PING_TIMES_ARRAY_SIZE; j++ )
			{
				remoteSystem->pingAndClockDifferential[ j ].pingTime = 65535;
				remoteSystem->pingAndClockDifferential[ j ].clockDifferential = 0;
			}

			remoteSystem->connectMode=connectionMode;
			remoteSystem->pingAndClockDifferentialWriteIndex = 0;
			remoteSystem->lowestPing = 65535;
			remoteSystem->nextPingTime = 0;
			remoteSystem->weInitiatedTheConnection = false;
			remoteSystem->connectionTime = time;
			remoteSystem->myExternalSystemAddress = UNASSIGNED_SYSTEM_ADDRESS;
			remoteSystem->setAESKey=false;
			remoteSystem->lastReliableSend=time;

			remoteSystem->reliabilityLayer.Reset(true);

			SystemAddressAndIndex systemAddressAndIndex;
			systemAddressAndIndex.systemAddress=systemAddress;
			systemAddressAndIndex.index=i;
			remoteSystemLookup.Insert(systemAddress,systemAddressAndIndex, true);

			return remoteSystem;
		}
	}

	return 0;
}
