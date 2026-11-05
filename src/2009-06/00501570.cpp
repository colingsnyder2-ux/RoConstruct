// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string.h>
#define BITS_TO_BYTES(x) (((x)+7)>>3)
typedef unsigned char RPCIndex;
enum { ID_TIMESTAMP = 0x19 };
typedef unsigned int RakNetTime;
namespace RakNet {
class BitStream {
public:
    BitStream(unsigned char* _data, const unsigned int lengthInBytes, bool _copyData);
    ~BitStream();
    void IgnoreBits(const unsigned int numberOfBits);
    bool ReadCompressed(unsigned char* output, const unsigned int size, const bool unsignedData);
    template<class T> bool ReadCompressed(T& var) { return ReadCompressed((unsigned char*)&var, sizeof(T) * 8, true); }
    bool Read(bool& var)
    {
        if (readOffset + 1 > numberOfBitsUsed)
            return false;
        if (data[readOffset >> 3] & (0x80 >> (readOffset & 7)))
            var = true;
        else
            var = false;
        readOffset++;
        return true;
    }
    unsigned int numberOfBitsUsed;
    unsigned int numberOfBitsAllocated;
    unsigned int readOffset;
    unsigned char* data;
    bool copyData;
    unsigned char stackData[1024];
};
}
struct SystemAddress {
    unsigned int binaryAddress;
    unsigned short port;
    bool operator==(const SystemAddress& right) const;
};
extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;
struct RPCNode { char* uniqueIdentifier; };
struct RPCMap { RPCNode* GetNodeFromIndex(RPCIndex index); };
class StringCompressor {
public:
    static StringCompressor* Instance();
    bool DecodeString(char* output, int maxCharsToWrite, RakNet::BitStream* input, int languageID = 0);
};
#define stringCompressor StringCompressor::Instance()
struct RemoteSystemStruct { char pad[0x13a8]; RPCMap rpcMap; };
class RakPeer {
public:
    virtual char* GetRPCString(const char* data, const unsigned int bitSize, const SystemAddress systemAddress);
    RemoteSystemStruct* GetRemoteSystemFromSystemAddress(const SystemAddress systemAddress, bool calledFromNetworkThread, bool onlyActive) const;
    char pad[0xa40 - 4];
    RPCMap rpcMap;
};
char *RakPeer::GetRPCString( const char *data, const unsigned int bitSize, const SystemAddress systemAddress)
{
	bool nameIsEncoded=false;
	static char uniqueIdentifier[256];
	RPCIndex rpcIndex;
	RPCMap *_rpcMap;
	RakNet::BitStream rpcDecode((unsigned char*) data, BITS_TO_BYTES(bitSize), false);
	rpcDecode.IgnoreBits(8);
	if (data[0]==ID_TIMESTAMP)
		rpcDecode.IgnoreBits(sizeof(unsigned char)+sizeof(RakNetTime));
	rpcDecode.Read(nameIsEncoded);
	if (nameIsEncoded)
	{
		stringCompressor->DecodeString((char*)uniqueIdentifier, 256, &rpcDecode);
	}
	else
	{
		rpcDecode.ReadCompressed( rpcIndex );
		RPCNode *rpcNode;

		if (systemAddress==UNASSIGNED_SYSTEM_ADDRESS)
			_rpcMap=&rpcMap;
		else
		{
			RemoteSystemStruct *rss=GetRemoteSystemFromSystemAddress(systemAddress, false, true);
			if (rss)
				_rpcMap=&(rss->rpcMap);
			else
				_rpcMap=0;
		}

		if (_rpcMap)
			rpcNode = _rpcMap->GetNodeFromIndex(rpcIndex);
		else
			rpcNode=0;

		if (_rpcMap && rpcNode)
			strcpy((char*)uniqueIdentifier, rpcNode->uniqueIdentifier);
		else
			strcpy((char*)uniqueIdentifier, "[UNKNOWN]");
	}

	return uniqueIdentifier;
}
