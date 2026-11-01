// from server: 99% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <malloc.h>
#include <string.h>
typedef unsigned char MessageID;
typedef unsigned int BitSize_t;
typedef unsigned int RakNetTime;
typedef unsigned char RPCIndex;
#define UNDEFINED_RPC_INDEX ((RPCIndex)255)
#define MAX_ALLOCA_STACK_ALLOCATION 1048576
#define BITS_TO_BYTES(x) (((x)+7)>>3)
enum { ID_RPC_MAPPING = 7, ID_RPC_REPLY = 12, ID_TIMESTAMP = 0x19 };
enum PacketPriority { SYSTEM_PRIORITY, HIGH_PRIORITY, MEDIUM_PRIORITY, LOW_PRIORITY };
enum PacketReliability { UNRELIABLE, UNRELIABLE_SEQUENCED, RELIABLE, RELIABLE_ORDERED };
extern void* (*rakMalloc)(size_t size);
extern void (*rakFree)(void* p);
struct SystemAddress { unsigned int binaryAddress; unsigned short port; SystemAddress& operator = ( const SystemAddress& input ) { binaryAddress = input.binaryAddress; port = input.port; return *this; } };
struct NetworkID { unsigned short localSystemAddress; };
const NetworkID UNASSIGNED_NETWORK_ID = { 65535 };
class RakPeerInterface;
namespace RakNet {
class BitStream {
public:
	BitStream();
	BitStream( unsigned char* _data, const unsigned int lengthInBytes, bool _copyData );
	~BitStream();
	template <class templateType> void Write(templateType var)
	{
		if (sizeof(var)==1)
			WriteBits( ( unsigned char* ) & var, sizeof( templateType ) * 8, true );
		else
		{
			if (DoEndianSwap())
			{
				unsigned char output[sizeof(templateType)];
				ReverseBytes((unsigned char*)&var, output, sizeof(templateType));
				WriteBits( ( unsigned char* ) output, sizeof(templateType) * 8, true );
			}
			else
				WriteBits( ( unsigned char* ) & var, sizeof(templateType) * 8, true );
		}
	}
	template <class templateType> void WriteCompressed(templateType var)
	{
		if (sizeof(var)==1)
			WriteCompressed( ( unsigned char* ) & var, sizeof( templateType ) * 8, true );
		else
		{
			if (DoEndianSwap())
			{
				unsigned char output[sizeof(templateType)];
				ReverseBytes((unsigned char*)&var, output, sizeof(templateType));
				WriteCompressed( ( unsigned char* ) output, sizeof(templateType) * 8, true );
			}
			else
				WriteCompressed( ( unsigned char* ) & var, sizeof(templateType) * 8, true );
		}
	}
	template <class templateType> bool Read(templateType &var)
	{
		if (sizeof(var)==1)
			return ReadBits( ( unsigned char* ) &var, sizeof(templateType) * 8, true );
		else
		{
			if (DoEndianSwap())
			{
				unsigned char output[sizeof(templateType)];
				if (ReadBits( ( unsigned char* ) output, sizeof(templateType) * 8, true ))
				{
					ReverseBytes(output, (unsigned char*)&var, sizeof(templateType));
					return true;
				}
				return false;
			}
			else
				return ReadBits( ( unsigned char* ) & var, sizeof(templateType) * 8, true );
		}
	}
	template <class templateType> bool ReadCompressed(templateType &var);
	bool ReadNI(bool &var);
	void Write( const char* input, const unsigned int numberOfBytes );
	void WriteBits( const unsigned char* input, BitSize_t numberOfBitsToWrite, const bool rightAlignedBits = true );
	void WriteCompressed( const unsigned char* input, const unsigned int size, const bool unsignedData );
	bool ReadBits( unsigned char *output, BitSize_t numberOfBitsToRead, const bool alignBitsToRight = true );
	bool ReadCompressed( unsigned char* output, const unsigned int size, const bool unsignedData );
	void IgnoreBits( const BitSize_t numberOfBits );
	static void ReverseBytes(unsigned char *input, unsigned char *output, const unsigned int length);
	static bool DoEndianSwap(void);
	unsigned char* GetData( void ) const { return data; }
	BitSize_t GetNumberOfBitsUsed( void ) const { return numberOfBitsUsed; }
	BitSize_t GetNumberOfBytesUsed( void ) const { return BITS_TO_BYTES( numberOfBitsUsed ); }
	BitSize_t GetNumberOfUnreadBits( void ) const { return numberOfBitsUsed - readOffset; }
	BitSize_t numberOfBitsUsed;
	BitSize_t numberOfBitsAllocated;
	BitSize_t readOffset;
	unsigned char *data;
	bool copyData;
	unsigned char stackData[1024];
};
template <> inline bool BitStream::Read(bool &var)
{
	if ( readOffset + 1 > numberOfBitsUsed )
		return false;
	if ( data[ readOffset >> 3 ] & ( 0x80 >> ( readOffset & 7 ) ) )
		var = true;
	else
		var = false;
	readOffset++;
	return true;
}
template <> inline bool BitStream::Read(NetworkID &var)
{
	return Read(var.localSystemAddress);
}
template <> bool BitStream::ReadCompressed(unsigned int &var);
template <> inline bool BitStream::ReadCompressed(unsigned char &var)
{
	return ReadCompressed( ( unsigned char* ) & var, sizeof( unsigned char ) * 8, true );
}
}
struct RPCParameters
{
	unsigned char *input;
	unsigned int numberOfBitsOfData;
	SystemAddress sender;
	RakPeerInterface *recipient;
	RakNetTime remoteTimestamp;
	char *functionName;
	RakNet::BitStream *replyToSender;
};
struct RPCNode
{
	char *uniqueIdentifier;
	union
	{
		void ( *staticFunctionPointer ) ( RPCParameters *rpcParms );
		void ( *memberFunctionPointer ) ( void* _this, RPCParameters *rpcParms );
	};
	bool isPointerToMember;
};
struct RPCMap
{
	RPCNode *GetNodeFromIndex(RPCIndex index);
	RPCIndex GetIndexFromFunctionName(char *uniqueIdentifier);
	char pad[0x140];
};
class NetworkIDManager { public: void* GET_OBJECT_FROM_ID( NetworkID x ); };
class StringCompressor
{
public:
	static StringCompressor* Instance(void);
	void EncodeString( const char *input, int maxCharsToWrite, RakNet::BitStream *output, int languageID=0 );
	bool DecodeString( char *output, int maxCharsToWrite, RakNet::BitStream *input, int languageID=0 );
};
#define stringCompressor StringCompressor::Instance()
class RakPeerInterface { public: virtual ~RakPeerInterface() {} };
class RakPeer : public RakPeerInterface
{
public:
	struct RemoteSystemStruct { enum ConnectMode { NO_ACTION }; };
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
	virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual bool Send( const RakNet::BitStream * bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast );
	bool HandleRPCPacket( const char *data, int length, SystemAddress systemAddress );
	void SendBuffered( const char *data, BitSize_t numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, RemoteSystemStruct::ConnectMode connectionMode );
	RemoteSystemStruct *GetRemoteSystemFromSystemAddress( const SystemAddress systemAddress, bool calledFromNetworkThread, bool onlyActive ) const;
	char pad1[0xa40 - 4];
	RPCMap rpcMap;
	NetworkIDManager *networkIDManager;
};

bool RakPeer::HandleRPCPacket( const char *data, int length, SystemAddress systemAddress )
{
	RakNet::BitStream incomingBitStream( (unsigned char *) data, length, false );
	char uniqueIdentifier[ 256 ];
	unsigned char *userData;
	bool nameIsEncoded, networkIDIsEncoded;
	RPCIndex rpcIndex;
	RPCNode *node;
	RPCParameters rpcParms;
	NetworkID networkID = UNASSIGNED_NETWORK_ID;
	bool blockingCommand;
	RakNet::BitStream replyToSender;
	rpcParms.replyToSender=&replyToSender;

	rpcParms.recipient=this;
	rpcParms.sender=systemAddress;

	incomingBitStream.IgnoreBits(8);
	if (data[0]==ID_TIMESTAMP)
	{
		incomingBitStream.IgnoreBits(8*(sizeof(RakNetTime)+sizeof(MessageID)));
		memcpy(&rpcParms.remoteTimestamp, data+sizeof(MessageID), sizeof(RakNetTime));
	}
	else
		rpcParms.remoteTimestamp=0;
	if ( incomingBitStream.Read( nameIsEncoded ) == false )
		return false;

	if (nameIsEncoded)
	{
		if ( stringCompressor->DecodeString(uniqueIdentifier, 256, &incomingBitStream) == false )
			return false;
		rpcIndex = rpcMap.GetIndexFromFunctionName(uniqueIdentifier);
	}
	else
	{
		if ( incomingBitStream.ReadCompressed( rpcIndex ) == false )
			return false;
	}
	if ( incomingBitStream.Read( blockingCommand ) == false )
		return false;
	if ( incomingBitStream.ReadCompressed( rpcParms.numberOfBitsOfData ) == false )
		return false;
	if ( incomingBitStream.Read( networkIDIsEncoded ) == false )
		return false;
	if (networkIDIsEncoded)
	{
		if ( incomingBitStream.Read( networkID ) == false )
			return false;
	}
	if (rpcIndex==UNDEFINED_RPC_INDEX)
		return false;

	node = rpcMap.GetNodeFromIndex(rpcIndex);
	if (node==0)
		return false;
	if (node->isPointerToMember==true && networkIDIsEncoded==false)
		return false;
	if (node->isPointerToMember==false && networkIDIsEncoded==true)
		return false;

	if (nameIsEncoded && GetRemoteSystemFromSystemAddress(systemAddress, false, true))
	{
		RakNet::BitStream rpcMapBitStream;
		rpcMapBitStream.Write((MessageID)ID_RPC_MAPPING);
		stringCompressor->EncodeString(node->uniqueIdentifier, 256, &rpcMapBitStream);
		rpcMapBitStream.WriteCompressed(rpcIndex);
		SendBuffered( (const char*)rpcMapBitStream.GetData(), rpcMapBitStream.GetNumberOfBitsUsed(), HIGH_PRIORITY, UNRELIABLE, 0, systemAddress, false, RemoteSystemStruct::NO_ACTION );
	}

	rpcParms.functionName=node->uniqueIdentifier;

	if ( rpcParms.numberOfBitsOfData == 0 )
	{
		rpcParms.input=0;
		if (networkIDIsEncoded)
		{
			if (networkIDManager)
			{
				void *object = networkIDManager->GET_OBJECT_FROM_ID(networkID);
				if (object)
					(node->memberFunctionPointer(object, &rpcParms));
			}
		}
		else
		{
			node->staticFunctionPointer( &rpcParms );
		}
	}
	else
	{
		if ( incomingBitStream.GetNumberOfUnreadBits() == 0 )
			return false;

		bool usedAlloca;
		if (BITS_TO_BYTES( incomingBitStream.GetNumberOfUnreadBits() ) < MAX_ALLOCA_STACK_ALLOCATION)
		{
			userData = ( unsigned char* ) alloca( BITS_TO_BYTES( incomingBitStream.GetNumberOfUnreadBits() ) );
			usedAlloca=true;
		}
		else
		{
			userData = (unsigned char*) rakMalloc(BITS_TO_BYTES(incomingBitStream.GetNumberOfUnreadBits()));
			usedAlloca=false;
		}

		if ( incomingBitStream.ReadBits( ( unsigned char* ) userData, rpcParms.numberOfBitsOfData, false ) == false )
			return false;

		rpcParms.input=userData;
		if (networkIDIsEncoded)
		{
			if (networkIDManager)
			{
				void *object = networkIDManager->GET_OBJECT_FROM_ID(networkID);
				if (object)
					(node->memberFunctionPointer(object, &rpcParms));
			}
		}
		else
		{
			node->staticFunctionPointer( &rpcParms );
		}

		if (usedAlloca==false)
			rakFree(userData);
	}

	if (blockingCommand)
	{
		RakNet::BitStream reply;
		reply.Write((MessageID)ID_RPC_REPLY);
		reply.Write((char*)replyToSender.GetData(), replyToSender.GetNumberOfBytesUsed());
		Send(&reply, HIGH_PRIORITY, RELIABLE, 0, systemAddress, false);
	}

	return true;
}
