// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RakNet {
class BitStream {
public:
    BitStream(unsigned char* _data, const unsigned int lengthInBytes, bool _copyData);
    ~BitStream();
    void IgnoreBits(const unsigned int numberOfBits);
    unsigned int numberOfBitsUsed;
    unsigned int numberOfBitsAllocated;
    unsigned int readOffset;
    unsigned char* data;
    bool copyData;
    unsigned char stackData[1024];
};
}
struct Packet { char pad[0x1c]; unsigned int length; unsigned int bitSize; unsigned char* data; };
namespace RBX { namespace Network {
class Replicator {
public:
    void receiveData(Packet* packet);
    void deserializeData(RakNet::BitStream& bitStream);
};
void Replicator::receiveData(Packet* packet)
{
    RakNet::BitStream bitStream(packet->data, packet->length, false);
    bitStream.IgnoreBits(8);
    deserializeData(bitStream);
}
}}
