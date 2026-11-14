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
#include "../native-headers/RakPeer.h"
#include "GetTime.h"
#include "NetworkIDManager.h"
#include "RakAssert.h"
#include <string.h>

void RakPeer::AddToBanList( const char *IP, RakNetTime milliseconds )
{
	unsigned index;
	RakNetTime time = RakNet::GetTime();

	if ( IP == 0 || IP[ 0 ] == 0 || strlen( IP ) > 15 )
		return ;

	// If this guy is already in the ban list, do nothing
	index = 0;

	banListMutex.Lock();

	for ( ; index < banList.Size(); index++ )
	{
		if ( strcmp( IP, banList[ index ]->IP ) == 0 )
		{
			// Already in the ban list.  Just update the time
			if (milliseconds==0)
				banList[ index ]->timeout=0; // Infinite
			else
				banList[ index ]->timeout=time+milliseconds;
			banListMutex.Unlock();
			return;
		}
	}

	banListMutex.Unlock();

	BanStruct *banStruct = new BanStruct;
	banStruct->IP = new char [ 16 ];
	if (milliseconds==0)
		banStruct->timeout=0; // Infinite
	else
		banStruct->timeout=time+milliseconds;
	strcpy( banStruct->IP, IP );
	banListMutex.Lock();
	banList.Insert( banStruct );
	banListMutex.Unlock();
}

void RakPeer::RemoveFromBanList( const char *IP )
{
	unsigned index;
	BanStruct *temp;

	if ( IP == 0 || IP[ 0 ] == 0 || strlen( IP ) > 15 )
		return ;

	index = 0;
	temp=0;

	banListMutex.Lock();

	for ( ; index < banList.Size(); index++ )
	{
		if ( strcmp( IP, banList[ index ]->IP ) == 0 )
		{
			temp = banList[ index ];
			banList[ index ] = banList[ banList.Size() - 1 ];
			banList.RemoveAtIndex( banList.Size() - 1 );
			break;
		}
	}

	banListMutex.Unlock();

	if (temp)
	{
		delete [] temp->IP;
		delete temp;
	}

}

bool RakPeer::IsBanned( const char *IP )
{
	unsigned banListIndex, characterIndex;
	RakNetTime time;
	BanStruct *temp;

	if ( IP == 0 || IP[ 0 ] == 0 || strlen( IP ) > 15 )
		return false;

	banListIndex = 0;

	if ( banList.Size() == 0 )
		return false; // Skip the mutex if possible

	time = RakNet::GetTime();

	banListMutex.Lock();

	while ( banListIndex < banList.Size() )
	{
		if (banList[ banListIndex ]->timeout>0 && banList[ banListIndex ]->timeout<time)
		{
			// Delete expired ban
			temp = banList[ banListIndex ];
			banList[ banListIndex ] = banList[ banList.Size() - 1 ];
			banList.RemoveAtIndex( banList.Size() - 1 );
			delete [] temp->IP;
			delete temp;
		}
		else
		{
			characterIndex = 0;

#ifdef _MSC_VER
#pragma warning( disable : 4127 ) // warning C4127: conditional expression is constant
#endif
			while ( true )
			{
				if ( banList[ banListIndex ]->IP[ characterIndex ] == IP[ characterIndex ] )
				{
					// Equal characters

					if ( IP[ characterIndex ] == 0 )
					{
						banListMutex.Unlock();
						// End of the string and the strings match

						return true;
					}

					characterIndex++;
				}

				else
				{
					if ( banList[ banListIndex ]->IP[ characterIndex ] == 0 || IP[ characterIndex ] == 0 )
					{
						// End of one of the strings
						break;
					}

					// Characters do not match
					if ( banList[ banListIndex ]->IP[ characterIndex ] == '*' )
					{
						banListMutex.Unlock();

						// Domain is banned.
						return true;
					}

					// Characters do not match and it is not a *
					break;
				}
			}

			banListIndex++;
		}
	}

	banListMutex.Unlock();

	// No match found.
	return false;
}

bool RakPeer::IsActive( void ) const
{
	return endThreads == false;
}
