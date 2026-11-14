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

#include "MessageIdentifiers.h"
#include "SocketLayer.h"
#include "PluginInterface.h"
#include "BitStream.h"
void RakPeer::AdvertiseSystem( const char *host, unsigned short remotePort, const char *data, int dataLength, unsigned connectionSocketIndex )
{
	if ( IsActive() == false )
		return ;

	if (host==0)
		return;

	// If this assert hits then Startup wasn't called or the call failed.
	RakAssert(connectionSocketIndex < connectionSocketsLength);

	// This is a security measure.  Don't send data longer than this value
	assert(dataLength <= MAX_OFFLINE_DATA_LENGTH);
	assert(dataLength>=0);

	// If the host starts with something other than 0, 1, or 2 it's (probably) a domain name.
	if ( host[ 0 ] < '0' || host[ 0 ] > '2' )
	{
#if !defined(_COMPATIBILITY_1)
		host = ( char* ) SocketLayer::Instance()->DomainNameToIP( host );
#else
		return;
#endif
	}

	SystemAddress systemAddress;
	systemAddress.SetBinaryAddress(host);
	systemAddress.port=remotePort;

	RakNet::BitStream bitStream;
	bitStream.Write((MessageID)ID_ADVERTISE_SYSTEM);
	if (dataLength>0)
		bitStream.Write(data, dataLength);
	else
		bitStream.Write((unsigned char)0); // Pad

	unsigned i;
	for (i=0; i < messageHandlerList.Size(); i++)
		messageHandlerList[i]->OnDirectSocketSend((const char*)bitStream.GetData(), bitStream.GetNumberOfBitsUsed(), systemAddress);
	SocketLayer::Instance()->SendTo( connectionSockets[connectionSocketIndex], (const char*)bitStream.GetData(), bitStream.GetNumberOfBytesUsed(), ( char* ) host, remotePort );



	/*
	// If the host starts with something other than 0, 1, or 2 it's (probably) a domain name.
	if ( host[ 0 ] < '0' || host[ 0 ] > '2' )
	{
#if !defined(_COMPATIBILITY_1)
		host = ( char* ) SocketLayer::Instance()->DomainNameToIP( host );
#else
		return;
#endif
	}

	SystemAddress systemAddress;
	IPToSystemAddress( host, remotePort, &systemAddress );

	RequestedConnectionStruct *rcs;
#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[requestedConnectionList_Mutex].Lock();
#endif
	rcs = requestedConnectionList.WriteLock();
	rcs->systemAddress=systemAddress;
	rcs->nextRequestTime=RakNet::GetTime();
	rcs->requestsMade=0;
	if (data && dataLength>0)
	{
		rcs->data=new char [dataLength];
		rcs->dataLength=(unsigned short)dataLength;
		memcpy(rcs->data, data, dataLength);
	}
	else
	{
		rcs->data=0;
		rcs->dataLength=0;
	}
	rcs->actionToTake=RequestedConnectionStruct::ADVERTISE_SYSTEM;
	requestedConnectionList.WriteUnlock();
#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[requestedConnectionList_Mutex].Unlock();
#endif
	*/
}

bool RakPeer::SendConnectionRequest( const char* host, unsigned short remotePort, const char* passwordData, int passwordDataLength, unsigned connectionSocketIndex )
{
	SystemAddress systemAddress;
	systemAddress.SetBinaryAddress(host);
	systemAddress.port=remotePort;

	// Already connected?
	if (GetRemoteSystemFromSystemAddress(systemAddress, false, true))
		return false;

	assert(passwordDataLength <= 256);

#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[requestedConnectionList_Mutex].Lock();
#endif
	RequestedConnectionStruct *rcs = requestedConnectionList.WriteLock();
	rcs->systemAddress=systemAddress;
	rcs->nextRequestTime=RakNet::GetTime();
	rcs->requestsMade=0;
	rcs->data=0;
	rcs->socketIndex=connectionSocketIndex;
	rcs->actionToTake=RequestedConnectionStruct::CONNECT;
	memcpy(rcs->outgoingPassword, passwordData, passwordDataLength);
	rcs->outgoingPasswordLength=(unsigned char) passwordDataLength;
	requestedConnectionList.WriteUnlock();

#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[requestedConnectionList_Mutex].Unlock();
#endif

	return true;
}

void RakPeer::PingInternal( const SystemAddress target, bool performImmediate, PacketReliability reliability )
{
	if ( IsActive() == false )
		return ;

	RakNet::BitStream bitStream(sizeof(unsigned char)+sizeof(RakNetTime));
	bitStream.Write((MessageID)ID_INTERNAL_PING);
	RakNetTimeNS currentTimeNS = RakNet::GetTimeNS();
	RakNetTime currentTime = RakNet::GetTime();
	bitStream.Write(currentTime);
	if (performImmediate)
		SendImmediate( (char*)bitStream.GetData(), bitStream.GetNumberOfBitsUsed(), SYSTEM_PRIORITY, reliability, 0, target, false, false, currentTimeNS );
	else
		Send( &bitStream, SYSTEM_PRIORITY, reliability, 0, target, false );
}

SystemAddress RakPeer::GetInternalID( const SystemAddress systemAddress ) const
{
	if (systemAddress==UNASSIGNED_SYSTEM_ADDRESS)
		return mySystemAddress;
	else
	{

#if !defined(_COMPATIBILITY_1)
		SystemAddress returnValue;
		RemoteSystemStruct * remoteSystem = GetRemoteSystemFromSystemAddress( systemAddress, false, true );
		if (remoteSystem==0)
			return UNASSIGNED_SYSTEM_ADDRESS;
		if (connectionSockets==0)
			return UNASSIGNED_SYSTEM_ADDRESS;

		sockaddr_in sa;
		socklen_t len = sizeof(sa);
		if (getsockname(connectionSockets[remoteSystem->connectionSocketIndex], (sockaddr*)&sa, &len)!=0)
			return UNASSIGNED_SYSTEM_ADDRESS;
		returnValue.port=ntohs(sa.sin_port);
		returnValue.binaryAddress=sa.sin_addr.s_addr;
		return returnValue;

#else
		return UNASSIGNED_SYSTEM_ADDRESS;
#endif
	}
}

void RakPeer::ShiftIncomingTimestamp( unsigned char *data, SystemAddress systemAddress ) const
{
#ifdef _DEBUG
	assert( IsActive() );
	assert( data );
#endif

	RakNet::BitStream timeBS( data, sizeof(RakNetTime), false);
	RakNetTime encodedTimestamp;
	timeBS.Read(encodedTimestamp);

	encodedTimestamp = encodedTimestamp - GetBestClockDifferential( systemAddress );
	timeBS.SetWriteOffset(0);
	timeBS.Write(encodedTimestamp);
}

RakNetTime RakPeer::GetBestClockDifferential( const SystemAddress systemAddress ) const
{
	int counter, lowestPingSoFar;
	RakNetTime clockDifferential;
	RemoteSystemStruct *remoteSystem = GetRemoteSystemFromSystemAddress( systemAddress, true, true );

	if ( remoteSystem == 0 )
		return 0;

	lowestPingSoFar = 65535;

	clockDifferential = 0;

	for ( counter = 0; counter < PING_TIMES_ARRAY_SIZE; counter++ )
	{
		if ( remoteSystem->pingAndClockDifferential[ counter ].pingTime == 65535 )
			break;

		if ( remoteSystem->pingAndClockDifferential[ counter ].pingTime < lowestPingSoFar )
		{
			clockDifferential = remoteSystem->pingAndClockDifferential[ counter ].clockDifferential;
			lowestPingSoFar = remoteSystem->pingAndClockDifferential[ counter ].pingTime;
		}
	}

	return clockDifferential;
}

void RakPeer::NotifyAndFlagForShutdown( const SystemAddress systemAddress, bool performImmediate, unsigned char orderingChannel )
{
	RakNet::BitStream temp( sizeof(unsigned char) );
	temp.Write( (MessageID)ID_DISCONNECTION_NOTIFICATION );
	if (performImmediate)
	{
		SendImmediate((char*)temp.GetData(), temp.GetNumberOfBitsUsed(), LOW_PRIORITY, RELIABLE_ORDERED, orderingChannel, systemAddress, false, false, RakNet::GetTimeNS());
		RemoteSystemStruct *rss=GetRemoteSystemFromSystemAddress(systemAddress, true, true);
		rss->connectMode=RemoteSystemStruct::DISCONNECT_ASAP;
	}
	else
	{
		SendBuffered((const char*)temp.GetData(), temp.GetNumberOfBitsUsed(), LOW_PRIORITY, RELIABLE_ORDERED, orderingChannel, systemAddress, false, RemoteSystemStruct::DISCONNECT_ASAP);
	}
}

void RakPeer::ClearBufferedCommands(void)
{
	BufferedCommandStruct *bcs;

#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[bufferedCommands_Mutex].Lock();
#endif
	while ((bcs=bufferedCommands.ReadLock())!=0)
	{
		if (bcs->data)
			delete [] bcs->data;

        bufferedCommands.ReadUnlock();
	}
	bufferedCommands.Clear();
#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[bufferedCommands_Mutex].Unlock();
#endif
}

void RakPeer::ClearRequestedConnectionList(void)
{
	RequestedConnectionStruct *bcs;
#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[requestedConnectionList_Mutex].Lock();
#endif
	while ((bcs=requestedConnectionList.ReadLock())!=0)
	{
		if (bcs->data)
			delete [] bcs->data;

		requestedConnectionList.ReadUnlock();
	}
	requestedConnectionList.Clear();
#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[requestedConnectionList_Mutex].Unlock();
#endif
}

void RakPeer::AddPacketToProducer(Packet *p)
{
	Packet **packetPtr=packetSingleProducerConsumer.WriteLock();
	*packetPtr=p;
	packetSingleProducerConsumer.WriteUnlock();
}

