// from server: 100% by EspClaude
// roc 2009-06 004d9ad0  RakNet::BitStream::Write(BitStream*, BitSize_t) (2009 unsigned BitSize_t)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef unsigned int BitSize_t;
namespace RakNet {
class BitStream {
public:
	void Write( BitStream *bitStream, BitSize_t numberOfBits );
	void AddBitsAndReallocate( const BitSize_t numberOfBitsToWrite );
	BitSize_t numberOfBitsUsed;
	BitSize_t numberOfBitsAllocated;
	BitSize_t readOffset;
	unsigned char *data;
};
void BitStream::Write( BitStream *bitStream, BitSize_t numberOfBits )
{
	AddBitsAndReallocate( numberOfBits );
	BitSize_t numberOfBitsMod8;

	while (numberOfBits-->0 && bitStream->readOffset + 1 <= bitStream->numberOfBitsUsed)
	{
		numberOfBitsMod8 = numberOfBitsUsed & 7;
		if ( numberOfBitsMod8 == 0 )
		{
			if (bitStream->data[ bitStream->readOffset >> 3 ] & ( 0x80 >> ( bitStream->readOffset & 7 ) ) )
				data[ numberOfBitsUsed >> 3 ] = 0x80;
			else
				data[ numberOfBitsUsed >> 3 ] = 0;
		}
		else
		{
			if (bitStream->data[ bitStream->readOffset >> 3 ] & ( 0x80 >> ( bitStream->readOffset & 7 ) ) )
				data[ numberOfBitsUsed >> 3 ] |= 0x80 >> ( numberOfBitsMod8 );
		}

		bitStream->readOffset++;
		numberOfBitsUsed++;
	}
}
}
