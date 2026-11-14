/// \file
///
/// This file is part of RakNet Copyright 2003 Kevin Jenkins.
///
/// Usage of RakNet is subject to the appropriate license agreement.
/// Creative Commons Licensees are subject to the
/// license found at
/// http://creativecommons.org/licenses/by-nc/2.5/
/// Single application licensees are subject to the license found at
/// http://www.rakkarsoft.com/SingleApplicationLicense.html
/// Custom license users are subject to the terms therein.
/// GPL license users are subject to the GNU General Public
/// License as published by the Free
/// Software Foundation; either version 2 of the License, or (at your
/// option) any later version.

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /FImalloc.h /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "../native-headers/ReliabilityLayer.h"
#include "SHA1.h"
#include <string.h>
void ReliabilityLayer::GetSHA1( unsigned char * const buffer, unsigned int
							   nbytes, char code[ SHA1_LENGTH ] )
{
	CSHA1 sha1;

	sha1.Reset();
	sha1.Update( ( unsigned char* ) buffer, nbytes );
	sha1.Final();
	memcpy( code, sha1.GetHash(), SHA1_LENGTH );
}

bool ReliabilityLayer::CheckSHA1( char code[ SHA1_LENGTH ], unsigned char *
								 const buffer, unsigned int nbytes )
{
	char code2[ SHA1_LENGTH ];
	GetSHA1( buffer, nbytes, code2 );

	for ( int i = 0; i < SHA1_LENGTH; i++ )
		if ( code[ i ] != code2[ i ] )
			return false;

	return true;
}

void ReliabilityLayer::DeleteSequencedPacketsInList( unsigned char orderingChannel, DataStructures::List<InternalPacket*>&theList, int splitPacketId )
{
	unsigned i = 0;

	while ( i < theList.Size() )
	{
		if ( ( theList[ i ]->reliability == RELIABLE_SEQUENCED || theList[ i ]->reliability == UNRELIABLE_SEQUENCED ) &&
			theList[ i ]->orderingChannel == orderingChannel && ( splitPacketId == -1 || theList[ i ]->splitPacketId != (unsigned int) splitPacketId ) )
		{
			InternalPacket * internalPacket = theList[ i ];
			theList.RemoveAtIndex( i );
			delete [] internalPacket->data;
			internalPacketPool.Release( internalPacket );
		}

		else
			i++;
	}
}

void ReliabilityLayer::DeleteSequencedPacketsInList( unsigned char orderingChannel, DataStructures::Queue<InternalPacket*>&theList )
{
	InternalPacket * internalPacket;
	int listSize = theList.Size();
	int i = 0;

	while ( i < listSize )
	{
		if ( ( theList[ i ]->reliability == RELIABLE_SEQUENCED || theList[ i ]->reliability == UNRELIABLE_SEQUENCED ) && theList[ i ]->orderingChannel == orderingChannel )
		{
			internalPacket = theList[ i ];
			theList.RemoveAtIndex( i );
			delete [] internalPacket->data;
			internalPacketPool.Release( internalPacket );
			listSize--;
		}

		else
			i++;
	}
}



void ReliabilityLayer::SendAcknowledgementPacket( const MessageNumberType messageNumber, RakNetTimeNS time )
{
	statistics.acknowlegementsSent++;
	acknowlegements.Insert(messageNumber);
}

void ReliabilityLayer::KillConnection( void )
{
	deadConnection=true;
}
