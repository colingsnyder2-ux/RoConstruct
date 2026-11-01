// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet roc_espclaude_68dbe7e72397cc88.cpp

// Candidate translation unit (score above; library headers required).
#define __DATA_BLOCK_ENCRYPTOR_H
#include "Rijndael.h"
namespace RakNet { class RakNetRandom { public: unsigned int RandomMT(void); }; }
class DataBlockEncryptor
{
public:
	DataBlockEncryptor();
	~DataBlockEncryptor();
	bool IsKeySet( void ) const;
	void SetKey( const unsigned char key[ 16 ] );
	void UnsetKey( void );
	void Encrypt( unsigned char *input, unsigned int inputLength, unsigned char *output, unsigned int *outputLength, RakNet::RakNetRandom *rnr );
protected:
 	keyInstance keyEncrypt;
	keyInstance keyDecrypt;
	cipherInstance cipherInst;
	bool keySet;
};
#include "CheckSum.h"
#include "GetTime.h"
#include "Rand.h"
#include <assert.h>
#include <string.h>
#include "Types.h"
#define RakAssert assert
void DataBlockEncryptor::Encrypt( unsigned char *input, unsigned int inputLength, unsigned char *output, unsigned int *outputLength, RakNet::RakNetRandom *rnr )
{
	unsigned index, byteIndex, lastBlock;
	unsigned int checkSum;
	unsigned char paddingBytes;
	unsigned char encodedPad;
	unsigned char randomChar;
	CheckSum checkSumCalculator;

#ifdef _DEBUG

	RakAssert( keySet );
#endif

	RakAssert( input && inputLength );


	// randomChar will randomize the data so the same data sent twice will not look the same
	randomChar = (unsigned char) rnr->RandomMT();

	// 16-(((x-1) % 16)+1)

	// # of padding bytes is 16 -(((input_length + extra_data -1) % 16)+1)
	paddingBytes = (unsigned char) ( 16 - ( ( ( inputLength + sizeof( randomChar ) + sizeof( checkSum ) + sizeof( encodedPad ) - 1 ) % 16 ) + 1 ) );

	// Randomize the pad size variable
	encodedPad = (unsigned char) rnr->RandomMT();
	encodedPad <<= 4;
	encodedPad |= paddingBytes;

	*outputLength = inputLength + sizeof( randomChar ) + sizeof( checkSum ) + sizeof( encodedPad ) + paddingBytes;

	// Write the data first, in case we are overwriting ourselves

	if ( input == output )
		memmove( output + sizeof( checkSum ) + sizeof( randomChar ) + sizeof( encodedPad ) + paddingBytes, input, inputLength );
	else
		memcpy( output + sizeof( checkSum ) + sizeof( randomChar ) + sizeof( encodedPad ) + paddingBytes, input, inputLength );

	// Write the random char
	memcpy( output + sizeof( checkSum ), ( char* ) & randomChar, sizeof( randomChar ) );

	// Write the pad size variable
	memcpy( output + sizeof( checkSum ) + sizeof( randomChar ), ( char* ) & encodedPad, sizeof( encodedPad ) );

	// Write the padding
	for ( index = 0; index < paddingBytes; index++ )
		*( output + sizeof( checkSum ) + sizeof( randomChar ) + sizeof( encodedPad ) + index ) = (unsigned char) rnr->RandomMT();

	// Calculate the checksum on the data
	checkSumCalculator.Add( output + sizeof( checkSum ), inputLength + sizeof( randomChar ) + sizeof( encodedPad ) + paddingBytes );

	checkSum = checkSumCalculator.Get();

	// Write checksum
#ifdef HOST_ENDIAN_IS_BIG
	output[0] = checkSum&0xFF;
	output[1] = (checkSum>>8)&0xFF;
	output[2] = (checkSum>>16)&0xFF;
	output[3] = (checkSum>>24)&0xFF;
#else
	memcpy( output, ( char* ) & checkSum, sizeof( checkSum ) );
#endif

	// AES on the first block
//	secretKeyAES128.encrypt16( output );
	blockEncrypt(&cipherInst, &keyEncrypt, output, 16, output);

	lastBlock = 0;

	// Now do AES on every other block from back to front
	for ( index = *outputLength - 16; index >= 16; index -= 16 )
	{
		for ( byteIndex = 0; byteIndex < 16; byteIndex++ )
			output[ index + byteIndex ] ^= output[ lastBlock + byteIndex ];

		//secretKeyAES128.encrypt16( output + index );
		blockEncrypt(&cipherInst, &keyEncrypt, output+index, 16, output+index);

		lastBlock = index;
	}
}

