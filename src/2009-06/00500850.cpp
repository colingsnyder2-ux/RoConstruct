// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <malloc.h>
typedef unsigned int RakNetTime;
typedef unsigned __int64 RakNetTimeNS;
#define BITS_TO_BYTES(x) (((x)+7)>>3)
enum PacketPriority { SYSTEM_PRIORITY, HIGH_PRIORITY, MEDIUM_PRIORITY, LOW_PRIORITY, NUMBER_OF_PRIORITIES };
enum PacketReliability { UNRELIABLE, UNRELIABLE_SEQUENCED, RELIABLE, RELIABLE_ORDERED, RELIABLE_SEQUENCED };
struct SystemAddress {
    unsigned int binaryAddress;
    unsigned short port;
    bool operator!=(const SystemAddress& right) const;
};
extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;
namespace RakNet {
class BitStream {
public:
    BitStream(const unsigned int initialBytesToAllocate);
    ~BitStream();
    unsigned int GetNumberOfBitsUsed() const { return numberOfBitsUsed; }
    unsigned int GetNumberOfBytesUsed() const { return BITS_TO_BYTES(numberOfBitsUsed); }
    unsigned char* GetData() const { return data; }
private:
    unsigned int numberOfBitsUsed;
    unsigned int numberOfBitsAllocated;
    unsigned int readOffset;
    unsigned char* data;
    bool copyData;
    unsigned char stackData[1024];
};
}
class HuffmanEncodingTree {
public:
    void EncodeArray(unsigned char* input, unsigned sizeInBytes, RakNet::BitStream* output);
};
class ReliabilityLayer {
public:
    bool Send(char* data, unsigned int numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, unsigned char orderingChannel, bool makeDataCopy, int MTUSize, RakNetTimeNS currentTime);
};
struct RemoteSystemStruct {
    bool isActive;
    SystemAddress systemAddress;
    char pad0[0x30 - 0xc];
    ReliabilityLayer reliabilityLayer;
    char pad1[0x1388 - 0x31];
    RakNetTime lastReliableSend;
    char pad2[0x13c4 - 0x138c];
    int MTUSize;
    enum ConnectMode { NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK, REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET, CONNECTED } connectMode;
    char pad3[0x13d0 - 0x13cc];
};
class RakPeer {
public:
    virtual ~RakPeer();
    int endThreads;
    unsigned short maximumNumberOfPeers;
    char p1[0x53c - 0xa];
    RemoteSystemStruct* remoteSystemList;
    char p2[0x5f4 - 0x540];
    unsigned int frequencyTable[256];
    HuffmanEncodingTree* inputTree;
    HuffmanEncodingTree* outputTree;
    unsigned int rawBytesSent;
    unsigned int rawBytesReceived;
    unsigned int compressedBytesSent;
    char p3[0xa50 - 0xa08];
    bool trackFrequencyTable;
    unsigned GetIndexFromSystemAddress(const SystemAddress systemAddress, bool calledFromNetworkThread);
    bool SendImmediate(char* data, unsigned int numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, bool useCallerDataAllocation, RakNetTimeNS currentTime);
};
bool RakPeer::SendImmediate( char *data, unsigned int numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, bool useCallerDataAllocation, RakNetTimeNS currentTime )
{
	unsigned *sendList;
	unsigned sendListSize;
	bool callerDataAllocationUsed;
	unsigned remoteSystemIndex, sendListIndex;
	unsigned numberOfBytesUsed = BITS_TO_BYTES(numberOfBitsToSend);
	callerDataAllocationUsed=false;

	sendListSize=0;

	if (broadcast==false)
	{
		sendList=(unsigned *)alloca(sizeof(unsigned));
		remoteSystemIndex=GetIndexFromSystemAddress( systemAddress, true );
		if (remoteSystemIndex!=(unsigned)-1 &&
			remoteSystemList[remoteSystemIndex].isActive &&
			remoteSystemList[remoteSystemIndex].connectMode!=RemoteSystemStruct::DISCONNECT_ASAP && 
			remoteSystemList[remoteSystemIndex].connectMode!=RemoteSystemStruct::DISCONNECT_ASAP_SILENTLY && 
			remoteSystemList[remoteSystemIndex].connectMode!=RemoteSystemStruct::DISCONNECT_ON_NO_ACK)
		{
			sendList[0]=remoteSystemIndex;
			sendListSize=1;
		}
	}
	else
	{
		sendList=(unsigned *)alloca(sizeof(unsigned)*maximumNumberOfPeers);

		for ( remoteSystemIndex = 0; remoteSystemIndex < maximumNumberOfPeers; remoteSystemIndex++ )
		{
			if ( remoteSystemList[ remoteSystemIndex ].isActive && remoteSystemList[ remoteSystemIndex ].systemAddress != systemAddress && remoteSystemList[ remoteSystemIndex ].systemAddress != UNASSIGNED_SYSTEM_ADDRESS )
				sendList[sendListSize++]=remoteSystemIndex;
		}
	}

	if (sendListSize==0)
	{
		return false;
	}

	for (sendListIndex=0; sendListIndex < sendListSize; sendListIndex++)
	{
		if ( trackFrequencyTable )
		{
			unsigned i;
			for (i=0 ; i < numberOfBytesUsed; i++ )
				frequencyTable[ (unsigned char)(data[i]) ]++;
		}

		if ( outputTree )
		{
			RakNet::BitStream bitStreamCopy( numberOfBytesUsed );
			outputTree->EncodeArray( (unsigned char*) data, numberOfBytesUsed, &bitStreamCopy );
			rawBytesSent += numberOfBytesUsed;
			compressedBytesSent += bitStreamCopy.GetNumberOfBytesUsed();
			remoteSystemList[sendList[sendListIndex]].reliabilityLayer.Send( (char*) bitStreamCopy.GetData(), bitStreamCopy.GetNumberOfBitsUsed(), priority, reliability, orderingChannel, true, remoteSystemList[sendList[sendListIndex]].MTUSize, currentTime );
		}
		else
		{
			bool useData = useCallerDataAllocation && callerDataAllocationUsed==false && sendListIndex+1==sendListSize;
			remoteSystemList[sendList[sendListIndex]].reliabilityLayer.Send( data, numberOfBitsToSend, priority, reliability, orderingChannel, useData==false, remoteSystemList[sendList[sendListIndex]].MTUSize, currentTime );
			if (useData)
				callerDataAllocationUsed=true;
		}

		if (reliability==RELIABLE || reliability==RELIABLE_ORDERED || reliability==RELIABLE_SEQUENCED)
			remoteSystemList[sendList[sendListIndex]].lastReliableSend=(RakNetTime)(currentTime/(RakNetTimeNS)1000);
	}

	return callerDataAllocationUsed;
}
