// =============================================================================
// CheckSum.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/raknet30/source/CheckSum.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

/**
* @file
* @brief CheckSum implementation from http://www.flounder.com/checksum.htm
*
*/
#include "CheckSum.h"

/****************************************************************************
*        CheckSum::add
* Inputs:
*   unsigned int d: word to add
* Result: void
*
* Effect:
*   Adds the bytes of the unsigned int to the CheckSum
****************************************************************************/

void CheckSum::Add ( unsigned int value )
{
	union
	{
		unsigned int value;
		unsigned char bytes[ 4 ];
	}

	data;
	data.value = value;

	for ( unsigned int i = 0; i < sizeof( data.bytes ); i++ )
		Add ( data.bytes[ i ] )

		;
} // CheckSum::add(unsigned int)

/****************************************************************************
*       CheckSum::add
* Inputs:
*   unsigned short value:
* Result: void
*
* Effect:
*   Adds the bytes of the unsigned short value to the CheckSum
****************************************************************************/

void CheckSum::Add ( unsigned short value )
{
	union
	{
		unsigned short value;
		unsigned char bytes[ 2 ];
	}

	data;
	data.value = value;

	for ( unsigned int i = 0; i < sizeof( data.bytes ); i++ )
		Add ( data.bytes[ i ] )

		;
} // CheckSum::add(unsigned short)

/****************************************************************************
*       CheckSum::add
* Inputs:
*   unsigned char value:
* Result: void
*
* Effect:
*   Adds the byte to the CheckSum
****************************************************************************/

void CheckSum::Add ( unsigned char value )
{
	unsigned char cipher = (unsigned char)( value ^ ( r >> 8 ) );
	r = ( cipher + r ) * c1 + c2;
	sum += cipher;
} // CheckSum::add(unsigned char)

/****************************************************************************
*       CheckSum::add
* Inputs:
*   LPunsigned char b: pointer to byte array
*   unsigned int length: count
* Result: void
*
* Effect:
*   Adds the bytes to the CheckSum
****************************************************************************/

void CheckSum::Add ( unsigned char *b, unsigned int length )
{
	for ( unsigned int i = 0; i < length; i++ )
		Add ( b[ i ] )

		;
} // CheckSum::add(LPunsigned char, unsigned int)
