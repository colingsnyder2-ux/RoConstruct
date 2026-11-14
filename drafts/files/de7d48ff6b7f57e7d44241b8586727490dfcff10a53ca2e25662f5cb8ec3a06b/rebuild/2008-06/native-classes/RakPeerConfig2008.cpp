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

void RakPeer::SetMaximumIncomingConnections( unsigned short numberAllowed )
{
	maximumIncomingConnections = numberAllowed;
}

unsigned short RakPeer::GetMaximumIncomingConnections( void ) const
{
	return maximumIncomingConnections;
}

void RakPeer::SetIncomingPassword( const char* passwordData, int passwordDataLength )
{
	//if (passwordDataLength > MAX_OFFLINE_DATA_LENGTH)
	//	passwordDataLength=MAX_OFFLINE_DATA_LENGTH;

	if (passwordDataLength > 255)
		passwordDataLength=255;

	if (passwordData==0)
		passwordDataLength=0;

	// Not threadsafe but it's not important enough to lock.  Who is going to change the password a lot during runtime?
	// It won't overflow at least because incomingPasswordLength is an unsigned char
	if (passwordDataLength>0)
		memcpy(incomingPassword, passwordData, passwordDataLength);
	incomingPasswordLength=(unsigned char)passwordDataLength;
}

void RakPeer::GetIncomingPassword( char* passwordData, int *passwordDataLength  )
{
	if (passwordData==0)
	{
		*passwordDataLength=incomingPasswordLength;
		return;
	}

	if (*passwordDataLength > incomingPasswordLength)
		*passwordDataLength=incomingPasswordLength;

	if (*passwordDataLength>0)
		memcpy(passwordData, incomingPassword, *passwordDataLength);
}

void RakPeer::SetNetworkIDManager( NetworkIDManager *manager )
{
	networkIDManager=manager;
}

NetworkIDManager* RakPeer::GetNetworkIDManager(void) const
{
	return networkIDManager;
}

unsigned short RakPeer::GetMaximumNumberOfPeers( void ) const
{
	return maximumNumberOfPeers;
}

SystemAddress RakPeer::GetSystemAddressFromIndex( int index )
{
	// remoteSystemList in user thread
	//if ( index >= 0 && index < remoteSystemListSize )
	if ( index >= 0 && index < maximumNumberOfPeers )
		if (remoteSystemList[ index ].connectMode==RakPeer::RemoteSystemStruct::CONNECTED) // Don't give the user players that aren't fully connected, since sends will fail
			return remoteSystemList[ index ].systemAddress;

	return UNASSIGNED_SYSTEM_ADDRESS;
}

void RakPeer::SetOccasionalPing( bool doPing )
{
	occasionalPing = doPing;
}

SystemAddress RakPeer::GetExternalID( const SystemAddress target ) const
{
	unsigned i;
	SystemAddress inactiveExternalId;

	inactiveExternalId=UNASSIGNED_SYSTEM_ADDRESS;

	// First check for active connection with this systemAddress
	for ( i = 0; i < maximumNumberOfPeers; i++ )
	{
		if (remoteSystemList[ i ].systemAddress == target || target==UNASSIGNED_SYSTEM_ADDRESS )
		{
			if ( remoteSystemList[ i ].isActive )
				return remoteSystemList[ i ].myExternalSystemAddress;
			else
				inactiveExternalId=remoteSystemList[ i ].myExternalSystemAddress;
		}
	}

	return inactiveExternalId;
}

bool RakPeer::SetMTUSize( int size )
{
	if ( IsActive() )
		return false;

	if ( size < 512 )
		size = 512;
	else if ( size > MAXIMUM_MTU_SIZE )
		size = MAXIMUM_MTU_SIZE;

	defaultMTUSize = size;

	return true;
}

void RakPeer::AllowConnectionResponseIPMigration( bool allow )
{
	allowConnectionResponseIPMigration = allow;
}

void RakPeer::SetSplitMessageProgressInterval(int interval)
{
	RakAssert(interval>=0);
	splitMessageProgressInterval=interval;
	for ( unsigned short i = 0; i < maximumNumberOfPeers; i++ )
		remoteSystemList[ i ].reliabilityLayer.SetSplitMessageProgressInterval(splitMessageProgressInterval);
}

void RakPeer::SetCompileFrequencyTable( bool doCompile )
{
	trackFrequencyTable = doCompile;
}

void RakPeer::SetRouterInterface( RouterInterface *routerInterface )
{
	router=routerInterface;
}

void RakPeer::RemoveRouterInterface( RouterInterface *routerInterface )
{
	if (router==routerInterface)
		router=0;
}

bool RakPeer::IsNetworkSimulatorActive( void )
{
    return _maxSendBPS>0 || _minExtraPing>0 || _extraPingVariance>0;
}

unsigned short RakPeer::GetNumberOfRemoteInitiatedConnections( void ) const
{
	unsigned short i, numberOfIncomingConnections;

	if ( remoteSystemList == 0 || endThreads == true )
		return 0;

	numberOfIncomingConnections = 0;

	// remoteSystemList in network thread
	for ( i = 0; i < maximumNumberOfPeers; i++ )
	//for ( i = 0; i < remoteSystemListSize; i++ )
	{
		if ( remoteSystemList[ i ].isActive && remoteSystemList[ i ].weInitiatedTheConnection == false && remoteSystemList[i].connectMode==RemoteSystemStruct::CONNECTED)
			numberOfIncomingConnections++;
	}

	return numberOfIncomingConnections;
}



