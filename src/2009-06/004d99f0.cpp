// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
extern void* (*rakMalloc)(size_t);
#define BITS_TO_BYTES(x) (((x)+7)>>3)
namespace RakNet {
class BitStream {
public:
    unsigned int CopyData( unsigned char** _data ) const;
    unsigned int numberOfBitsUsed;
    unsigned int numberOfBitsAllocated;
    unsigned int readOffset;
    unsigned char* data;
    bool copyData;
};
unsigned int BitStream::CopyData( unsigned char** _data ) const
{
	*_data = (unsigned char*) rakMalloc( BITS_TO_BYTES( numberOfBitsUsed ) );
	memcpy( *_data, data, sizeof(unsigned char) * ( BITS_TO_BYTES( numberOfBitsUsed ) ) );
	return numberOfBitsUsed;
}
}
