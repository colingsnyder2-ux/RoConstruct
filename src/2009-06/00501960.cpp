// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned int BitSize_t;
typedef unsigned int RakNetTime;
typedef unsigned __int64 RakNetTimeNS;
typedef unsigned char MessageID;
typedef unsigned short SystemIndex;
struct SystemAddress { unsigned int binaryAddress; unsigned short port; };
enum PacketPriority { SYSTEM_PRIORITY };
enum PacketReliability { UNRELIABLE, UNRELIABLE_SEQUENCED, RELIABLE };
namespace RakNet {
class BitStream {
public:
    BitStream(const unsigned int initialBytesToAllocate);
    unsigned char* GetData(void) const { return data; }
    BitSize_t GetNumberOfBitsUsed(void) const { return numberOfBitsUsed; }
    void Write(SystemAddress var);
    BitStream(unsigned char* _data, const unsigned int lengthInBytes, bool _copyData);
    ~BitStream();
    bool ReadBits(unsigned char* inOutByteArray, BitSize_t numberOfBitsToRead, bool alignBitsToRight = true);
    void WriteBits(const unsigned char* inByteArray, BitSize_t numberOfBitsToWrite, const bool rightAlignedBits = true);
    void SetWriteOffset(const BitSize_t offset);
    static bool DoEndianSwap(void);
    static void ReverseBytes(unsigned char* input, unsigned char* output, const unsigned int length);
    template <class templateType> bool Read(templateType& var)
    {
        if (DoEndianSwap()) {
            unsigned char output[sizeof(templateType)];
            if (ReadBits((unsigned char*)output, sizeof(templateType) * 8, true)) {
                ReverseBytes(output, (unsigned char*)&var, sizeof(templateType));
                return true;
            }
            return false;
        }
        else
            return ReadBits((unsigned char*)&var, sizeof(templateType) * 8, true);
    }
    template <class templateType> void Write(templateType var)
    {
        if (sizeof(var) == 1)
            WriteBits((unsigned char*)&var, sizeof(templateType) * 8, true);
        else if (DoEndianSwap()) {
            unsigned char output[sizeof(templateType)];
            ReverseBytes((unsigned char*)&var, output, sizeof(templateType));
            WriteBits((unsigned char*)output, sizeof(templateType) * 8, true);
        }
        else
            WriteBits((unsigned char*)&var, sizeof(templateType) * 8, true);
    }
private:
    BitSize_t numberOfBitsUsed;
    BitSize_t numberOfBitsAllocated;
    BitSize_t readOffset;
    unsigned char* data;
    bool copyData;
    unsigned char stackData[1024];
};
}
namespace RakNet { RakNetTimeNS GetTimeNS(void); }
#define MAXIMUM_NUMBER_OF_INTERNAL_IDS 3
#define ID_CONNECTION_REQUEST_ACCEPTED 0xe
class RakPeer {
public:
    struct RemoteSystemStruct { bool isActive; SystemAddress systemAddress; };
    unsigned int GetIndexFromSystemAddress(const SystemAddress systemAddress, bool calledFromNetworkThread);
    bool SendImmediate(char* data, BitSize_t numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, const SystemAddress systemAddress, bool broadcast, bool useCallerDataAllocation, RakNetTimeNS currentTime);
    void OnConnectionRequest(RakPeer::RemoteSystemStruct* remoteSystem);
    char pad[0x420];
    SystemAddress mySystemAddress[MAXIMUM_NUMBER_OF_INTERNAL_IDS];
};
void RakPeer::OnConnectionRequest(RakPeer::RemoteSystemStruct* remoteSystem)
{
    RakNet::BitStream bitStream(sizeof(unsigned char)+sizeof(unsigned short)+sizeof(unsigned int)+sizeof(unsigned short)+sizeof(SystemIndex)+sizeof(unsigned int)+sizeof(unsigned int));
    bitStream.Write((MessageID)ID_CONNECTION_REQUEST_ACCEPTED);
    bitStream.Write(remoteSystem->systemAddress);
    SystemIndex systemIndex = (SystemIndex) GetIndexFromSystemAddress(remoteSystem->systemAddress, true);
    bitStream.Write(systemIndex);
    for (unsigned int i = 0; i < MAXIMUM_NUMBER_OF_INTERNAL_IDS; i++)
        bitStream.Write(mySystemAddress[i]);
    SendImmediate((char*)bitStream.GetData(), bitStream.GetNumberOfBitsUsed(), SYSTEM_PRIORITY, RELIABLE, 0, remoteSystem->systemAddress, false, false, RakNet::GetTimeNS());
}
