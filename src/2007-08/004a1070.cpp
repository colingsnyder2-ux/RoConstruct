// from server: 100% by EspClaude
// roc 2007-08 004a1070  RBX::Network::operator>>(RakNet::BitStream&, BrickColor&) (Streaming.cpp; 2007 has no read-failure throw)
// roc-flags: /O2 /GS /EHsc /MD
#include <vector>
namespace RakNet {
class BitStream {
public:
    bool ReadBits(unsigned char* output, int numberOfBitsToRead, const bool alignBitsToRight = true);
};
}
namespace RBX {
class BrickColor {
public:
    int number;
    static const std::vector<BrickColor>& colorPalette();
};
namespace Network {
RakNet::BitStream& operator>>(RakNet::BitStream& stream, BrickColor& value)
{
    unsigned int index = 0;
    stream.ReadBits((unsigned char*)&index, 5);
    value = BrickColor::colorPalette()[index];
    return stream;
}
}
}
