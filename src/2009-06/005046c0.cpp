// from server: 100% by EspClaude
// roc 2009-06 005046c0  RakPeer::NotifyAndFlagForShutdown (2009: BitStream stack 1024, ID 0x13, connectMode 0x13c8)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned char MessageID;
typedef unsigned int BitSize_t;
typedef unsigned __int64 RakNetTimeNS;
enum { ID_DISCONNECTION_NOTIFICATION = 0x13 };
enum PacketPriority { SYSTEM_PRIORITY, HIGH_PRIORITY, MEDIUM_PRIORITY, LOW_PRIORITY };
enum PacketReliability { UNRELIABLE, UNRELIABLE_SEQUENCED, RELIABLE, RELIABLE_ORDERED };
struct SystemAddress
{
	unsigned int binaryAddress;
	unsigned short port;
};
namespace RakNet {
RakNetTimeNS GetTimeNS( void );
class BitStream {
public:
	BitStream( const unsigned int initialBytesToAllocate );
	~BitStream();
	template <class templateType> void Write(templateType var) { WriteBits( ( unsigned char* ) & var, sizeof( templateType ) * 8, true ); }
	void WriteBits( const unsigned char* input, BitSize_t numberOfBitsToWrite, const bool rightAlignedBits = true );
	unsigned char* GetData( void ) const { return data; }
	BitSize_t GetNumberOfBitsUsed( void ) const { return numberOfBitsUsed; }
	BitSize_t numberOfBitsUsed;
	BitSize_t numberOfBitsAllocated;
	BitSize_t readOffset;
	unsigned char *data;
	bool copyData;
	unsigned char stackData[1024];
};
}
class RakPeer
{
public:
	struct RemoteSystemStruct
	{
		char pad[0x13c8];
		enum ConnectMode { NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK, REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET, CONNECTED } connectMode;
	};
	void NotifyAndFlagForShutdown( const SystemAddress systemAddress, bool performImmediate, unsigned char orderingChannel );
	bool SendImmediate( char *data, BitSize_t numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, bool useCallerDataAllocation, RakNetTimeNS currentTime );
	void SendBuffered( const char *data, BitSize_t numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, RemoteSystemStruct::ConnectMode connectionMode );
	RemoteSystemStruct *GetRemoteSystemFromSystemAddress( const SystemAddress systemAddress, bool calledFromNetworkThread, bool onlyActive ) const;
};
void RakPeer::NotifyAndFlagForShutdown( const SystemAddress systemAddress, bool performImmediate, unsigned char orderingChannel )
{
	RakNet::BitStream temp( sizeof(unsigned char) );
	temp.Write( (MessageID)ID_DISCONNECTION_NOTIFICATION );
	if (performImmediate)
	{
		SendImmediate((char*)temp.GetData(), temp.GetNumberOfBitsUsed(), LOW_PRIORITY, RELIABLE_ORDERED, orderingChannel, systemAddress, false, false, RakNet::GetTimeNS());
		RemoteSystemStruct *rss=GetRemoteSystemFromSystemAddress(systemAddress, true, true);
		rss->connectMode=RemoteSystemStruct::DISCONNECT_ASAP;
	}
	else
	{
		SendBuffered((const char*)temp.GetData(), temp.GetNumberOfBitsUsed(), LOW_PRIORITY, RELIABLE_ORDERED, orderingChannel, systemAddress, false, RemoteSystemStruct::DISCONNECT_ASAP);
	}
}
