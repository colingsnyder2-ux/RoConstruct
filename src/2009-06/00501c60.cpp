// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned int BitSize_t;
typedef unsigned int RakNetTime;
namespace RakNet {
class BitStream {
public:
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
        if (DoEndianSwap()) {
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
struct SystemAddress { unsigned int binaryAddress; unsigned short port; };
class RakPeer {
public:
    int GetBestClockDifferential(const SystemAddress systemAddress) const;
    void ShiftIncomingTimestamp(unsigned char* data, SystemAddress systemAddress) const;
};
void RakPeer::ShiftIncomingTimestamp(unsigned char* data, SystemAddress systemAddress) const
{
    RakNet::BitStream timeBS(data, sizeof(RakNetTime), false);
    RakNetTime encodedTimestamp;
    timeBS.Read(encodedTimestamp);
    encodedTimestamp = encodedTimestamp - GetBestClockDifferential(systemAddress);
    timeBS.SetWriteOffset(0);
    timeBS.Write(encodedTimestamp);
}
