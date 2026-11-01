// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef unsigned int BitSize_t;
namespace RakNet {
class BitStream {
public:
	void WriteBits( const unsigned char *input, BitSize_t numberOfBitsToWrite, const bool rightAlignedBits );
	void AddBitsAndReallocate( const BitSize_t numberOfBitsToWrite );
	BitSize_t numberOfBitsUsed;
	BitSize_t numberOfBitsAllocated;
	BitSize_t readOffset;
	unsigned char *data;
};
void BitStream::WriteBits( const unsigned char *input, BitSize_t numberOfBitsToWrite, const bool rightAlignedBits )
{
	if (numberOfBitsToWrite<=0)
		return;
	AddBitsAndReallocate( numberOfBitsToWrite );
	BitSize_t offset = 0;
	unsigned char dataByte;
	BitSize_t numberOfBitsUsedMod8;
	numberOfBitsUsedMod8 = numberOfBitsUsed & 7;
	while ( numberOfBitsToWrite > 0 )
	{
		dataByte = *( input + offset );
		if ( numberOfBitsToWrite < 8 && rightAlignedBits )
			dataByte <<= 8 - numberOfBitsToWrite;
		if ( numberOfBitsUsedMod8 == 0 )
			* ( data + ( numberOfBitsUsed >> 3 ) ) = dataByte;
		else
		{
			*( data + ( numberOfBitsUsed >> 3 ) ) |= dataByte >> ( numberOfBitsUsedMod8 );
			if ( 8 - ( numberOfBitsUsedMod8 ) < 8 && 8 - ( numberOfBitsUsedMod8 ) < numberOfBitsToWrite )
			{
				*( data + ( numberOfBitsUsed >> 3 ) + 1 ) = (unsigned char) ( dataByte << ( 8 - ( numberOfBitsUsedMod8 ) ) );
			}
		}
		if ( numberOfBitsToWrite >= 8 )
			numberOfBitsUsed += 8;
		else
			numberOfBitsUsed += numberOfBitsToWrite;
		if ( numberOfBitsToWrite >= 8 )
			numberOfBitsToWrite -= 8;
		else
			numberOfBitsToWrite = 0;
		offset++;
	}
}
}
