// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
typedef unsigned int BitSize_t;
extern void* (*rakMalloc)(size_t);
extern void* (*rakRealloc)(void*, size_t);
#define BITS_TO_BYTES(x) (((x)+7)>>3)
#define BITSTREAM_STACK_ALLOCATION_SIZE 1024
namespace RakNet {
class BitStream {
public:
	void AddBitsAndReallocate( const BitSize_t numberOfBitsToWrite );
	BitSize_t numberOfBitsUsed;
	BitSize_t numberOfBitsAllocated;
	BitSize_t readOffset;
	unsigned char *data;
	bool copyData;
	unsigned char stackData[BITSTREAM_STACK_ALLOCATION_SIZE];
};
void BitStream::AddBitsAndReallocate( const BitSize_t numberOfBitsToWrite )
{
	if ( numberOfBitsToWrite <= 0 )
		return;
	BitSize_t newNumberOfBitsAllocated = numberOfBitsToWrite + numberOfBitsUsed;
	if ( numberOfBitsToWrite + numberOfBitsUsed > 0 && ( ( numberOfBitsAllocated - 1 ) >> 3 ) < ( ( newNumberOfBitsAllocated - 1 ) >> 3 ) )
	{
		newNumberOfBitsAllocated = ( numberOfBitsToWrite + numberOfBitsUsed ) * 2;
		if (newNumberOfBitsAllocated - ( numberOfBitsToWrite + numberOfBitsUsed ) > 1048576 )
			newNumberOfBitsAllocated = numberOfBitsToWrite + numberOfBitsUsed + 1048576;
		BitSize_t amountToAllocate = BITS_TO_BYTES( newNumberOfBitsAllocated );
		if (data==(unsigned char*)stackData)
		{
			if (amountToAllocate > BITSTREAM_STACK_ALLOCATION_SIZE)
			{
				data = ( unsigned char* ) rakMalloc( amountToAllocate );
				memcpy ((void *)data, (void *)stackData, BITS_TO_BYTES( numberOfBitsAllocated ));
			}
		}
		else
		{
			data = ( unsigned char* ) rakRealloc( data, amountToAllocate );
		}
	}
	if ( newNumberOfBitsAllocated > numberOfBitsAllocated )
		numberOfBitsAllocated = newNumberOfBitsAllocated;
}
}
