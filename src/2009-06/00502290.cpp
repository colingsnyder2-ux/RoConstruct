// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned char MessageID;
typedef unsigned int RakNetTime;
typedef unsigned __int64 RakNetTimeNS;
enum { ID_INTERNAL_PING = 0 };
enum PacketPriority { SYSTEM_PRIORITY, HIGH_PRIORITY };
enum PacketReliability { UNRELIABLE };
namespace RakNet {
class BitStream {
public:
    BitStream(const unsigned int initialBytesToAllocate);
    ~BitStream();
    void WriteBits(const unsigned char* input, unsigned int numberOfBitsToWrite, const bool rightAlignedBits = true);
    void Write(MessageID var) { WriteBits(&var, sizeof(var) * 8, true); }
    void Write(RakNetTime var);
    unsigned char* GetData() const { return data; }
    unsigned int GetNumberOfBitsUsed() const { return numberOfBitsUsed; }
    unsigned int numberOfBitsUsed;
    unsigned int numberOfBitsAllocated;
    unsigned int readOffset;
    unsigned char* data;
    bool copyData;
    unsigned char stackData[1024];
};
RakNetTimeNS GetTimeNS();
RakNetTime GetTime();
}
struct SystemAddress {
    unsigned int binaryAddress;
    unsigned short port;
};
class RakPeer {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual bool IsActive() const;
    virtual void v15();
    virtual bool Send(const RakNet::BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast);
    bool SendImmediate(char* data, unsigned int numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, bool useCallerDataAllocation, RakNetTimeNS currentTime);
    void PingInternal(const SystemAddress target, bool performImmediate, PacketReliability reliability);
};
void RakPeer::PingInternal(const SystemAddress target, bool performImmediate, PacketReliability reliability)
{
    if (IsActive() == false)
        return;

    RakNet::BitStream bitStream(sizeof(unsigned char) + sizeof(RakNetTime));
    bitStream.Write((MessageID)ID_INTERNAL_PING);
    RakNetTimeNS currentTimeNS = RakNet::GetTimeNS();
    RakNetTime currentTime = RakNet::GetTime();
    bitStream.Write(currentTime);
    if (performImmediate)
        SendImmediate((char*)bitStream.GetData(), bitStream.GetNumberOfBitsUsed(), SYSTEM_PRIORITY, reliability, 0, target, false, false, currentTimeNS);
    else
        Send(&bitStream, SYSTEM_PRIORITY, reliability, 0, target, false);
}
