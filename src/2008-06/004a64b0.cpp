// from server: 100% by tester
namespace RakNet {
class BitStream
{
public:
    void WriteBits(const unsigned char* input, int numberOfBitsToWrite, const bool rightAlignedBits = true);

    template<class templateType>
    void Write(templateType var)
    {
        WriteBits((unsigned char*)&var, sizeof(templateType) * 8, true);
    }
};
}

namespace RBX {
namespace Network {
RakNet::BitStream& operator<<(RakNet::BitStream& stream, double value)
{
    stream.Write(value);
    return stream;
}
}
}
