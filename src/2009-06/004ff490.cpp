// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned int BitSize_t;
typedef unsigned int RakNetTime;
typedef unsigned __int64 RakNetTimeNS;
typedef unsigned char MessageID;
typedef unsigned short SystemIndex;
struct SystemAddress { void SetBinaryAddress(const char* str); unsigned int binaryAddress; unsigned short port; };
enum PacketPriority { SYSTEM_PRIORITY };
enum PacketReliability { UNRELIABLE, UNRELIABLE_SEQUENCED, RELIABLE };
namespace RakNet {
class BitStream {
public:
    BitStream(const unsigned int initialBytesToAllocate);
    unsigned char* GetData(void) const { return data; }
    BitSize_t GetNumberOfBitsUsed(void) const { return numberOfBitsUsed; }
    void Write(RakNetTime var);
    void WriteAlignedBytes(const unsigned char* inByteArray, const unsigned int numberOfBytesToWrite);
    BitSize_t GetNumberOfBytesUsed(void) const { return ((numberOfBitsUsed) + 7) >> 3; }
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
namespace RakNet { RakNetTime GetTime(void); }
typedef unsigned int SOCKET;
class SocketLayer {
public:
    static inline SocketLayer* Instance() { return &I; }
    const char* DomainNameToIP(const char* domainName);
    int SendTo(SOCKET s, const char* data, int length, char ip[], unsigned short port, bool skip);
private:
    static SocketLayer I;
};
extern const unsigned char OFFLINE_MESSAGE_DATA_ID[16];
#define ID_PING 1
#define ID_PING_OPEN_CONNECTIONS 2
class PluginInterface {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void OnDirectSocketSend(const char* data, const BitSize_t bitsUsed, SystemAddress remoteSystemAddress);
};
template <class T> struct List {
    T* listArray; unsigned int list_size; unsigned int allocation_size;
    T& operator[](const unsigned int position) const { return listArray[position]; }
    unsigned int Size(void) const { return list_size; }
};
struct SocketEntry { SOCKET s; bool skip; };
class RakPeer {
public:
    virtual bool Ping(const char* host, unsigned short remotePort, bool onlyReplyOnAcceptingConnections, unsigned connectionSocketIndex);
    char pad[0x5bc - 4];
    List<PluginInterface*> messageHandlerList;
    char pad2[0xa58 - 0x5c8];
    SocketEntry* connectionSockets;
};
bool RakPeer::Ping(const char* host, unsigned short remotePort, bool onlyReplyOnAcceptingConnections, unsigned connectionSocketIndex)
{
    if (host == 0)
        return false;
    if (host[0] < '0' || host[0] > '9')
    {
        host = (char*)SocketLayer::Instance()->DomainNameToIP(host);
        if (host == 0)
            return false;
    }
    SystemAddress systemAddress;
    systemAddress.SetBinaryAddress(host);
    systemAddress.port = remotePort;
    RakNet::BitStream bitStream(sizeof(unsigned char) + sizeof(RakNetTime));
    if (onlyReplyOnAcceptingConnections)
        bitStream.Write((MessageID)ID_PING_OPEN_CONNECTIONS);
    else
        bitStream.Write((MessageID)ID_PING);
    bitStream.Write(RakNet::GetTime());
    bitStream.WriteAlignedBytes((const unsigned char*)OFFLINE_MESSAGE_DATA_ID, sizeof(OFFLINE_MESSAGE_DATA_ID));
    unsigned i;
    for (i = 0; i < messageHandlerList.Size(); i++)
        messageHandlerList[i]->OnDirectSocketSend((const char*)bitStream.GetData(), bitStream.GetNumberOfBitsUsed(), systemAddress);
    SocketLayer::Instance()->SendTo(connectionSockets[connectionSocketIndex].s, (const char*)bitStream.GetData(), (int)bitStream.GetNumberOfBytesUsed(), (char*)host, remotePort, connectionSockets[connectionSocketIndex].skip);
    return true;
}
