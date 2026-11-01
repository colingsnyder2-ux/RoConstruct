// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef unsigned int BitSize_t;
namespace RakNet {
class BitStream {
public:
	template <class templateType> void Write(templateType var);
	void Write0( void );
	void Write1( void );
	void AddBitsAndReallocate( const BitSize_t numberOfBitsToWrite );
	BitSize_t numberOfBitsUsed;
	BitSize_t numberOfBitsAllocated;
	BitSize_t readOffset;
	unsigned char *data;
};
inline void BitStream::Write0( void )
{
	AddBitsAndReallocate( 1 );
	if ( ( numberOfBitsUsed & 7 ) == 0 )
		data[ numberOfBitsUsed >> 3 ] = 0;
	numberOfBitsUsed++;
}
inline void BitStream::Write1( void )
{
	AddBitsAndReallocate( 1 );
	BitSize_t numberOfBitsMod8 = numberOfBitsUsed & 7;
	if ( numberOfBitsMod8 == 0 )
		data[ numberOfBitsUsed >> 3 ] = 0x80;
	else
		data[ numberOfBitsUsed >> 3 ] |= 0x80 >> ( numberOfBitsMod8 );
	numberOfBitsUsed++;
}
template <>
void BitStream::Write(bool var)
{
	if ( var )
		Write1();
	else
		Write0();
}
}
