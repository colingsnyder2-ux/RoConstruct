// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
typedef unsigned int BitSize_t;
#define BITS_TO_BYTES(x) (((x)+7)>>3)
namespace RakNet {
class BitStream {
public:
    bool ReadBits(unsigned char* inOutByteArray, BitSize_t numberOfBitsToRead, const bool alignBitsToRight = true);
    BitSize_t numberOfBitsUsed;
    BitSize_t numberOfBitsAllocated;
    BitSize_t readOffset;
    unsigned char* data;
};
bool BitStream::ReadBits( unsigned char *inOutByteArray, BitSize_t numberOfBitsToRead, const bool alignBitsToRight )
{
	if (numberOfBitsToRead<=0)
		return false;
	if ( readOffset + numberOfBitsToRead > numberOfBitsUsed )
		return false;
	BitSize_t readOffsetMod8;
	BitSize_t offset = 0;
	memset( inOutByteArray, 0, (size_t) BITS_TO_BYTES( numberOfBitsToRead ) );
	readOffsetMod8 = readOffset & 7;
	while ( numberOfBitsToRead > 0 )
	{
		*( inOutByteArray + offset ) |= *( data + ( readOffset >> 3 ) ) << ( readOffsetMod8 );
		if ( readOffsetMod8 > 0 && numberOfBitsToRead > 8 - ( readOffsetMod8 ) )
			*( inOutByteArray + offset ) |= *( data + ( readOffset >> 3 ) + 1 ) >> ( 8 - ( readOffsetMod8 ) );
		if (numberOfBitsToRead>=8)
		{
			numberOfBitsToRead -= 8;
			readOffset += 8;
			offset++;
		}
		else
		{
			int neg = (int) numberOfBitsToRead - 8;
			if ( neg < 0 )
			{
				if ( alignBitsToRight )
					* ( inOutByteArray + offset ) >>= -neg;
				readOffset += 8 + neg;
			}
			else
				readOffset += 8;
			offset++;
			numberOfBitsToRead=0;
		}
	}
	return true;
}
}
