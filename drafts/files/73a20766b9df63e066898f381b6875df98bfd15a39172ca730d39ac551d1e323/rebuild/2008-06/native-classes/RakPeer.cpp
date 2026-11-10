// native-flags: /O2 /GS- /EHsc /MD /FImalloc.h /IC:\Users\colin\RoConstruct\rebuild\2008-06\native-headers /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source
// native-flags: /O2 /GS- /EHsc /MD /FImalloc.h /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source
// native-flags: /O2 /EHsc /MD /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source
// native-flags: /O2 /EHsc /MD /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source
#include "RakPeer.h"
#include "RakNetDefines.h"
#include "RakNetTypes.h"
#include "GetTime.h"
#include "MessageIdentifiers.h"
#include "DS_HuffmanEncodingTree.h"
#include "Rand.h"
#include "PluginInterface.h"
#include "StringCompressor.h"
#include "StringTable.h"
#include "NetworkIDObject.h"
#include "SHA1.h"
#include "RakSleep.h"
#include "RouterInterface.h"
#include "RakAssert.h"
#include "NetworkIDManager.h"

void RakPeer::DeallocatePacket( Packet *packet )
{
	if ( packet == 0 )
		return;

	if (packet->deleteData)
		delete [] packet->data;
	free(packet);
}

void RakPeer::RegisterAsRemoteProcedureCall( const char* uniqueID, void ( *functionPointer ) ( RPCParameters *rpcParms ) )
{
	if ( uniqueID == 0 || uniqueID[ 0 ] == 0 || functionPointer == 0 )
		return;

	rpcMap.AddIdentifierWithFunction(uniqueID, (void*)functionPointer, false);

	/*
	char uppercaseUniqueID[ 256 ];

	int counter = 0;

	while ( uniqueID[ counter ] )
	{
		uppercaseUniqueID[ counter ] = ( char ) toupper( uniqueID[ counter ] );
		counter++;
	}

	uppercaseUniqueID[ counter ] = 0;

	// Each id must be unique
//#ifdef _DEBUG
//	assert( rpcTree.IsIn( RPCNode( uppercaseUniqueID, functionName ) ) == false );
//#endif

	if (rpcTree.IsIn( RPCNode( uppercaseUniqueID, functionName ) ))
		return;

	rpcTree.Add( RPCNode( uppercaseUniqueID, functionName ) );
	*/
}

void RakPeer::RegisterClassMemberRPC( const char* uniqueID, void *functionPointer )
{
	if ( uniqueID == 0 || uniqueID[ 0 ] == 0 || functionPointer == 0 )
		return;

	rpcMap.AddIdentifierWithFunction(uniqueID, functionPointer, true);
}

void RakPeer::UnregisterAsRemoteProcedureCall( const char* uniqueID )
{
	if ( uniqueID == 0 || uniqueID[ 0 ] == 0 )
		return;

// Don't call this while running because if you remove RPCs and add them they will not match the indices on the other systems anymore
#ifdef _DEBUG
	assert(IsActive()==false);
	//assert( strlen( uniqueID ) < 256 );
#endif

	rpcMap.RemoveNode(uniqueID);

	/*
	char uppercaseUniqueID[ 256 ];

	strcpy( uppercaseUniqueID, uniqueID );

	int counter = 0;

	while ( uniqueID[ counter ] )
	{
		uppercaseUniqueID[ counter ] = ( char ) toupper( uniqueID[ counter ] );
		counter++;
	}

	uppercaseUniqueID[ counter ] = 0;

	// Unique ID must exist
#ifdef _DEBUG
	assert( rpcTree.IsIn( RPCNode( uppercaseUniqueID, 0 ) ) == true );
#endif

	rpcTree.Del( RPCNode( uppercaseUniqueID, 0 ) );
	*/
}

void RakPeer::SetOfflinePingResponse( const char *data, const unsigned int length )
{
	assert(length < 400);

	rakPeerMutexes[ offlinePingResponse_Mutex ].Lock();
	offlinePingResponse.Reset();

	if ( data && length > 0 )
		offlinePingResponse.Write( data, length );

	rakPeerMutexes[ offlinePingResponse_Mutex ].Unlock();
}

const char* RakPeer::GetLocalIP( unsigned int index )
{
#if !defined(_CONSOLE_1)
	static char ipList[ 10 ][ 16 ];

	if ( index >= 10 )
		index = 9;

	memset( ipList, 0, sizeof( char ) * 16 * 10 );

	SocketLayer::Instance()->GetMyIP( ipList );

	return ipList[ index ];
#else
	assert(0);
	return 0;
#endif
}

void RakPeer::SendTTL1( const char* host, unsigned short remotePort, unsigned connectionSocketIndex )
{
	char fakeData[2];
	fakeData[0]=0;
	fakeData[1]=1;
	SocketLayer::Instance()->SendToTTL1( connectionSockets[connectionSocketIndex], (char*)fakeData, 2, (char*) host, remotePort );
}

bool RakPeer::GetOutgoingFrequencyTable( unsigned int outputFrequencyTable[ 256 ] )
{
	if ( IsActive() )
		return false;

	if ( trackFrequencyTable == false )
		return false;

	memcpy( outputFrequencyTable, frequencyTable, sizeof( unsigned int ) * 256 );

	return true;
}

void RakPeer::ClearBanList( void )
{
	unsigned index;
	index = 0;
	banListMutex.Lock();

	for ( ; index < banList.Size(); index++ )
	{
		delete [] banList[ index ]->IP;
		delete [] banList[ index ];
	}

	banList.Clear();

	banListMutex.Unlock();
}

bool RakPeer::DeleteCompressionLayer( bool inputLayer )
{
	if ( IsActive() )
		return false;

	if ( inputLayer )
	{
		if ( inputTree )
		{
			delete inputTree;
			inputTree = 0;
		}
	}

	else
	{
		if ( outputTree )
		{
			delete outputTree;
			outputTree = 0;
		}
	}

	return true;
}

void RakPeer::AttachPlugin( PluginInterface *plugin )
{
	if (messageHandlerList.GetIndexOf(plugin)==MAX_UNSIGNED_LONG)
	{
		messageHandlerList.Insert(plugin);
		plugin->OnAttach(this);
	}
}

void RakPeer::DetachPlugin( PluginInterface *plugin )
{
	if (plugin==0)
		return;

	unsigned int index;
	index = messageHandlerList.GetIndexOf(plugin);
	if (index!=MAX_UNSIGNED_LONG)
	{
		messageHandlerList[index]->OnDetach(this);
		// Unordered list so delete from end for speed
		messageHandlerList[index]=messageHandlerList[messageHandlerList.Size()-1];
		messageHandlerList.RemoveFromEnd();
	}
}

int RakPeer::GetLastPing( const SystemAddress systemAddress ) const
{
	RemoteSystemStruct * remoteSystem = GetRemoteSystemFromSystemAddress( systemAddress, false, false );

	if ( remoteSystem == 0 )
		return -1;

	return (int)(remoteSystem->reliabilityLayer.GetAckPing()/(RakNetTimeNS)1000);

//	if ( remoteSystem->pingAndClockDifferentialWriteIndex == 0 )
//		return remoteSystem->pingAndClockDifferential[ PING_TIMES_ARRAY_SIZE - 1 ].pingTime;
//	else
//		return remoteSystem->pingAndClockDifferential[ remoteSystem->pingAndClockDifferentialWriteIndex - 1 ].pingTime;
}

void RakPeer::SetTimeoutTime( RakNetTime timeMS, const SystemAddress target )
{
	RemoteSystemStruct * remoteSystem = GetRemoteSystemFromSystemAddress( target, false, true );

	if ( remoteSystem != 0 )
		remoteSystem->reliabilityLayer.SetTimeoutTime(timeMS);
}

void RakPeer::CloseConnection( const SystemAddress target, bool sendDisconnectionNotification, unsigned char orderingChannel )
{
	CloseConnectionInternal(target, sendDisconnectionNotification, false, orderingChannel);

	// This only be called from the user thread, for the user shutting down.
	// From the network thread, this should occur because of ID_DISCONNECTION_NOTIFICATION and ID_CONNECTION_LOST
	unsigned j;
	for (j=0; j < messageHandlerList.Size(); j++)
	{
		messageHandlerList[j]->OnCloseConnection(this, target);
	}

}

void RakPeer::Ping( const SystemAddress target )
{
	PingInternal(target, false, UNRELIABLE);
}

unsigned int RakPeer::GetNumberOfAddresses( void )
{
#if !defined(_CONSOLE_1)
	char ipList[ 10 ][ 16 ];
	memset( ipList, 0, sizeof( char ) * 16 * 10 );
	SocketLayer::Instance()->GetMyIP( ipList );

	int i = 0;

	while ( ipList[ i ][ 0 ] )
		i++;

	return i;
#else
	assert(0);
	return 0;
#endif
}

void RakPeer::DisableSecurity( void )
{
#if !defined(_CONSOLE_1)
	if ( endThreads == false )
		return ;

	usingSecurity = false;
#endif
}

unsigned short RakPeer::NumberOfConnections(void) const
{
	unsigned short i, count=0;
	for (i=0; i < maximumNumberOfPeers; i++)
		if (remoteSystemList[i].isActive)
			count++;
	return count;
}

bool RakPeer::GetConnectionList( SystemAddress *remoteSystems, unsigned short *numberOfSystems ) const
{
	int count, index;
	count=0;

	if ( remoteSystemList == 0 || endThreads == true )
	{
		*numberOfSystems = 0;
		return false;
	}

	// This is called a lot so I unrolled the loop
	if ( remoteSystems )
	{
		// remoteSystemList in user thread
		//for ( count = 0, index = 0; index < remoteSystemListSize; ++index )
		for ( count = 0, index = 0; index < maximumNumberOfPeers; ++index )
			if ( remoteSystemList[ index ].isActive && remoteSystemList[ index ].connectMode==RemoteSystemStruct::CONNECTED)
			{
				if ( count < *numberOfSystems )
					remoteSystems[ count ] = remoteSystemList[ index ].systemAddress;

				++count;
			}
	}
	else
	{
		// remoteSystemList in user thread
		//for ( count = 0, index = 0; index < remoteSystemListSize; ++index )
		for ( count = 0, index = 0; index < maximumNumberOfPeers; ++index )
			if ( remoteSystemList[ index ].isActive && remoteSystemList[ index ].connectMode==RemoteSystemStruct::CONNECTED)
				++count;
	}

	*numberOfSystems = ( unsigned short ) count;

	return 0;
}

void RakPeer::SetUnreliableTimeout(RakNetTime timeoutMS)
{
	RakAssert(timeoutMS>=0);
	unreliableTimeout=timeoutMS;
	for ( unsigned short i = 0; i < maximumNumberOfPeers; i++ )
		remoteSystemList[ i ].reliabilityLayer.SetUnreliableTimeout(unreliableTimeout);
}

bool RakPeer::ValidSendTarget(SystemAddress systemAddress, bool broadcast)
{
	unsigned remoteSystemIndex;

	// remoteSystemList in user thread.  This is slow so only do it in debug
	for ( remoteSystemIndex = 0; remoteSystemIndex < maximumNumberOfPeers; remoteSystemIndex++ )
	//for ( remoteSystemIndex = 0; remoteSystemIndex < remoteSystemListSize; remoteSystemIndex++ )
	{
		if ( remoteSystemList[ remoteSystemIndex ].isActive &&
			remoteSystemList[ remoteSystemIndex ].connectMode==RakPeer::RemoteSystemStruct::CONNECTED && // Not fully connected players are not valid user-send targets because the reliability layer wasn't reset yet
			( ( broadcast == false && remoteSystemList[ remoteSystemIndex ].systemAddress == systemAddress ) ||
			( broadcast == true && remoteSystemList[ remoteSystemIndex ].systemAddress != systemAddress ) )
			)
			return true;
	}

	return false;
}

void RakPeer::PushBackPacket( Packet *packet, bool pushAtHead)
{
	if (packet==0)
		return;

#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[packetPool_Mutex].Lock();
#endif
	RakAssert(packet);
	if (pushAtHead)
		packetPool.PushAtHead(packet);
	else
		packetPool.Push(packet);
#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[packetPool_Mutex].Unlock();
#endif
}

int RakPeer::GetIndexFromSystemAddress( const SystemAddress systemAddress, bool calledFromNetworkThread )
{
	unsigned i;

	if ( systemAddress == UNASSIGNED_SYSTEM_ADDRESS )
		return -1;

	if (calledFromNetworkThread)
	{
		bool objectExists;
		unsigned index;
		index = remoteSystemLookup.GetIndexFromKey(systemAddress, &objectExists);
		if (objectExists)
		{
			assert(remoteSystemList[remoteSystemLookup[index].index].systemAddress==systemAddress);
			return remoteSystemLookup[index].index;
		}
		else
			return -1;
	}
	else
	{
		// remoteSystemList in user and network thread
		for ( i = 0; i < maximumNumberOfPeers; i++ )
			if ( remoteSystemList[ i ].isActive && remoteSystemList[ i ].systemAddress == systemAddress )
				return i;
	}

	return -1;
}
