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
#include "StringCompressor.h"
#include "StringTable.h"
#include "RouterInterface.h"
bool RakPeer::Send( const char *data, const int length, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast )
{
#ifdef _DEBUG
	assert( data && length > 0 );
#endif

	if ( data == 0 || length < 0 )
		return false;

	if ( remoteSystemList == 0 || endThreads == true )
		return false;

	if ( broadcast == false && systemAddress == UNASSIGNED_SYSTEM_ADDRESS )
		return false;

	if (broadcast==false && router && IsConnected(systemAddress)==false)
	{
		return router->Send(data, BYTES_TO_BITS(length), priority, reliability, orderingChannel, systemAddress);
	}
	else
	{
		SendBuffered(data, length*8, priority, reliability, orderingChannel, systemAddress, broadcast, RemoteSystemStruct::NO_ACTION);
	}

	return true;
}

bool RakPeer::Send( const RakNet::BitStream * bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast )
{
#ifdef _DEBUG
	assert( bitStream->GetNumberOfBytesUsed() > 0 );
#endif

	if ( bitStream->GetNumberOfBytesUsed() == 0 )
		return false;

	if ( remoteSystemList == 0 || endThreads == true )
		return false;

	if ( broadcast == false && systemAddress == UNASSIGNED_SYSTEM_ADDRESS )
		return false;

	if (broadcast==false && router && IsConnected(systemAddress)==false)
	{
		return router->Send((const char*)bitStream->GetData(), bitStream->GetNumberOfBitsUsed(), priority, reliability, orderingChannel, systemAddress);
	}
	else
	{
		// Sends need to be buffered and processed in the update thread because the systemAddress associated with the reliability layer can change,
		// from that thread, resulting in a send to the wrong player!  While I could mutex the systemAddress, that is much slower than doing this
		SendBuffered((const char*)bitStream->GetData(), bitStream->GetNumberOfBitsUsed(), priority, reliability, orderingChannel, systemAddress, broadcast, RemoteSystemStruct::NO_ACTION);
	}
	
	return true;
}

void RakPeer::Ping( const char* host, unsigned short remotePort, bool onlyReplyOnAcceptingConnections, unsigned connectionSocketIndex )
{
	if ( host == 0 )
		return;

	// If this assert hits then Startup wasn't called or the call failed.
	RakAssert(connectionSocketIndex < connectionSocketsLength);

//	if ( IsActive() == false )
//		return;

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

	RakNet::BitStream bitStream( sizeof(unsigned char) + sizeof(RakNetTime) );
	if ( onlyReplyOnAcceptingConnections )
		bitStream.Write((MessageID)ID_PING_OPEN_CONNECTIONS);
	else
		bitStream.Write((MessageID)ID_PING);

	bitStream.Write(RakNet::GetTime());

	unsigned i;
	for (i=0; i < messageHandlerList.Size(); i++)
		messageHandlerList[i]->OnDirectSocketSend((const char*)bitStream.GetData(), bitStream.GetNumberOfBitsUsed(), systemAddress);
	// No timestamp for 255.255.255.255
	SocketLayer::Instance()->SendTo( connectionSockets[connectionSocketIndex], (const char*)bitStream.GetData(), bitStream.GetNumberOfBytesUsed(), ( char* ) host, remotePort );




}

void RakPeer::SendBuffered( const char *data, int numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, RemoteSystemStruct::ConnectMode connectionMode )
{
#ifdef _DEBUG
	assert(orderingChannel >=0 && orderingChannel < 32);

	// In debug, verify that this target is potentially reachable.
	assert (router!=0 || ValidSendTarget(systemAddress, broadcast));
#endif

	BufferedCommandStruct *bcs;

#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[bufferedCommands_Mutex].Lock();
#endif
	bcs=bufferedCommands.WriteLock();
	bcs->data = new char[BITS_TO_BYTES(numberOfBitsToSend)]; // Making a copy doesn't lose efficiency because I tell the reliability layer to use this allocation for its own copy
#ifdef _DEBUG
	assert(bcs->data);
#endif
	memcpy(bcs->data, data, BITS_TO_BYTES(numberOfBitsToSend));
    bcs->numberOfBitsToSend=numberOfBitsToSend;
	bcs->priority=priority;
	bcs->reliability=reliability;
	bcs->orderingChannel=orderingChannel;
	bcs->systemAddress=systemAddress;
	bcs->broadcast=broadcast;
	bcs->connectionMode=connectionMode;
	bcs->command=BufferedCommandStruct::BCS_SEND;
	bufferedCommands.WriteUnlock();

#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[bufferedCommands_Mutex].Unlock();
#endif
}

char *RakPeer::GetRPCString( const char *data, const unsigned int bitSize, const SystemAddress systemAddress)
{
	bool nameIsEncoded;
	static char uniqueIdentifier[256];
	RPCIndex rpcIndex;
	RPCMap *_rpcMap;
	RakNet::BitStream rpcDecode((unsigned char*) data, BITS_TO_BYTES(bitSize), false);
	rpcDecode.IgnoreBits(8);
	if (data[0]==ID_TIMESTAMP)
		rpcDecode.IgnoreBits(sizeof(unsigned char)+sizeof(RakNetTime));
	rpcDecode.Read(nameIsEncoded);
	if (nameIsEncoded)
	{
		stringCompressor->DecodeString((char*)uniqueIdentifier, 256, &rpcDecode);
	}
	else
	{
		rpcDecode.ReadCompressed( rpcIndex );
		RPCNode *rpcNode;

		if (systemAddress==UNASSIGNED_SYSTEM_ADDRESS)
			_rpcMap=&rpcMap;
		else
		{
			RemoteSystemStruct *rss=GetRemoteSystemFromSystemAddress(systemAddress, false, true);
			if (rss)
				_rpcMap=&(rss->rpcMap);
			else
				_rpcMap=0;
		}

		if (_rpcMap)
			rpcNode = _rpcMap->GetNodeFromIndex(rpcIndex);
		else
			rpcNode=0;

		if (_rpcMap && rpcNode)
			strcpy((char*)uniqueIdentifier, rpcNode->uniqueIdentifier);
		else
			strcpy((char*)uniqueIdentifier, "[UNKNOWN]");
	}

	return uniqueIdentifier;
}

void RakPeer::OnConnectionRequest( RakPeer::RemoteSystemStruct *remoteSystem, unsigned char *AESKey, bool setAESKey )
{
	// Already handled by caller
	//if ( AllowIncomingConnections() )
	{
		RakNet::BitStream bitStream(sizeof(unsigned char)+sizeof(unsigned short)+sizeof(unsigned int)+sizeof(unsigned short)+sizeof(SystemIndex));
		bitStream.Write((MessageID)ID_CONNECTION_REQUEST_ACCEPTED);
		bitStream.Write(remoteSystem->systemAddress.binaryAddress);
		bitStream.Write(remoteSystem->systemAddress.port);
		bitStream.Write(( SystemIndex ) GetIndexFromSystemAddress( remoteSystem->systemAddress, true ));


		SendImmediate((char*)bitStream.GetData(), bitStream.GetNumberOfBitsUsed(), SYSTEM_PRIORITY, RELIABLE, 0, remoteSystem->systemAddress, false, false, RakNet::GetTimeNS());

		// Don't set secure connections immediately because we need the ack from the remote system to know ID_CONNECTION_REQUEST_ACCEPTED
		// As soon as a 16 byte packet arrives, we will turn on AES.  This works because all encrypted packets are multiples of 16 and the
		// packets I happen to be sending are less than 16 bytes
		remoteSystem->setAESKey=setAESKey;
		if ( setAESKey )
		{
			memcpy(remoteSystem->AESKey, AESKey, 16);
			remoteSystem->connectMode=RemoteSystemStruct::SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET;
		}
	}
	/*
	else
	{
		unsigned char c = ID_NO_FREE_INCOMING_CONNECTIONS;
		//SocketLayer::Instance()->SendTo( connectionSocket, ( char* ) & c, sizeof( char ), systemAddress.binaryAddress, systemAddress.port );

		SendImmediate((char*)&c, sizeof(c)*8, SYSTEM_PRIORITY, RELIABLE, 0, remoteSystem->systemAddress, false, false, RakNet::GetTimeNS());
		remoteSystem->connectMode=RemoteSystemStruct::DISCONNECT_ASAP_SILENTLY;
	}
	*/
}

RakPeer::RemoteSystemStruct * RakPeer::AssignSystemAddressToRemoteSystemList( const SystemAddress systemAddress, RemoteSystemStruct::ConnectMode connectionMode, unsigned connectionSocketIndex )
{
	RemoteSystemStruct * remoteSystem;
	unsigned i,j;
	RakNetTime time = RakNet::GetTime();
#ifdef _DEBUG
	assert(systemAddress!=UNASSIGNED_SYSTEM_ADDRESS);
#endif

	// remoteSystemList in user thread
	for ( i = 0; i < maximumNumberOfPeers; i++ )
	//for ( i = 0; i < remoteSystemListSize; i++ )
	{
		if ( remoteSystemList[ i ].isActive==false )
		{
			remoteSystem=remoteSystemList+i;
			remoteSystem->rpcMap.Clear();
			remoteSystem->systemAddress = systemAddress;
			remoteSystem->MTUSize = defaultMTUSize;
			remoteSystem->isActive=true; // This one line causes future incoming packets to go through the reliability layer
			remoteSystem->reliabilityLayer.SetSplitMessageProgressInterval(splitMessageProgressInterval);
			remoteSystem->reliabilityLayer.SetUnreliableTimeout(unreliableTimeout);
			remoteSystem->reliabilityLayer.SetEncryptionKey( 0 );
			remoteSystem->connectionSocketIndex=connectionSocketIndex;

			for ( j = 0; j < (unsigned) PING_TIMES_ARRAY_SIZE; j++ )
			{
				remoteSystem->pingAndClockDifferential[ j ].pingTime = 65535;
				remoteSystem->pingAndClockDifferential[ j ].clockDifferential = 0;
			}

			remoteSystem->connectMode=connectionMode;
			remoteSystem->pingAndClockDifferentialWriteIndex = 0;
			remoteSystem->lowestPing = 65535;
			remoteSystem->nextPingTime = 0; // Ping immediately
			remoteSystem->weInitiatedTheConnection = false;
			remoteSystem->connectionTime = time;
			remoteSystem->myExternalSystemAddress = UNASSIGNED_SYSTEM_ADDRESS;
			remoteSystem->setAESKey=false;
			remoteSystem->lastReliableSend=time;

			// Reserve this reliability layer for ourselves.
			remoteSystem->reliabilityLayer.Reset(true);

			/// Add this player to the lookup tree
			SystemAddressAndIndex systemAddressAndIndex;
			systemAddressAndIndex.systemAddress=systemAddress;
			systemAddressAndIndex.index=i;
			remoteSystemLookup.Insert(systemAddress,systemAddressAndIndex, true);

			return remoteSystem;
		}
	}

	return 0;
}

void RakPeer::CloseConnectionInternal( const SystemAddress target, bool sendDisconnectionNotification, bool performImmediate, unsigned char orderingChannel )
{
	unsigned i;

#ifdef _DEBUG
	assert(orderingChannel >=0 && orderingChannel < 32);
#endif

	if (target==UNASSIGNED_SYSTEM_ADDRESS)
		return;

	if ( remoteSystemList == 0 || endThreads == true )
		return;

	if (sendDisconnectionNotification)
	{
		NotifyAndFlagForShutdown(target, performImmediate, orderingChannel);
	}
	else
	{
		if (performImmediate)
		{
			// remoteSystemList in user thread
			for ( i=0; i < maximumNumberOfPeers; i++ )
				//for ( ; i < remoteSystemListSize; i++ )
			{
				if ( remoteSystemList[ i ].isActive && remoteSystemList[ i ].systemAddress == target )
				{
					// Found the index to stop
					remoteSystemList[ i ].isActive=false;

					// Reserve this reliability layer for ourselves
					//remoteSystemList[ i ].systemAddress = UNASSIGNED_SYSTEM_ADDRESS;
					
					// Clear any remaining messages
					remoteSystemList[ i ].reliabilityLayer.Reset(false);

					// Remove from the lookup list
					remoteSystemLookup.Remove(target);

					break;
				}
			}
		}
		else
		{
			BufferedCommandStruct *bcs;
#ifdef _RAKNET_THREADSAFE
			rakPeerMutexes[bufferedCommands_Mutex].Lock();
#endif
			bcs=bufferedCommands.WriteLock();
			bcs->command=BufferedCommandStruct::BCS_CLOSE_CONNECTION;
			bcs->systemAddress=target;
			bcs->data=0;
			bcs->orderingChannel=orderingChannel;
			bufferedCommands.WriteUnlock();
#ifdef _RAKNET_THREADSAFE
			rakPeerMutexes[bufferedCommands_Mutex].Unlock();
#endif
		}
	}
}

bool RakPeer::AllowIncomingConnections(void) const
{
	return GetNumberOfRemoteInitiatedConnections() < GetMaximumIncomingConnections();
}

void RakPeer::ParseConnectionRequestPacket( RakPeer::RemoteSystemStruct *remoteSystem, SystemAddress systemAddress, const char *data, int byteSize )
{
	// If we are full tell the sender.
	if ( !AllowIncomingConnections() )
	{
		unsigned char c = ID_NO_FREE_INCOMING_CONNECTIONS;
		SendImmediate(( char* ) & c, sizeof( char )*8, SYSTEM_PRIORITY, RELIABLE, 0, systemAddress, false, false, RakNet::GetTimeNS());
		remoteSystem->connectMode=RemoteSystemStruct::DISCONNECT_ASAP_SILENTLY;
	}
	else
	{
		const char *password = data + sizeof(unsigned char);
		int passwordLength = byteSize - sizeof(unsigned char);

		if ( incomingPasswordLength == passwordLength &&
			memcmp( password, incomingPassword, incomingPasswordLength ) == 0 )
		{
			remoteSystem->connectMode=RemoteSystemStruct::HANDLING_CONNECTION_REQUEST;

#if !defined(_COMPATIBILITY_1)
			if ( usingSecurity == false )
#endif
			{
#ifdef _TEST_AES
				unsigned char AESKey[ 16 ];
				// Save the AES key
				for ( i = 0; i < 16; i++ )
					AESKey[ i ] = i;

				OnConnectionRequest( remoteSystem, AESKey, true );
#else
				// Connect this player assuming we have open slots
				OnConnectionRequest( remoteSystem, 0, false );
#endif
			}
#if !defined(_COMPATIBILITY_1)
			else
				SecuredConnectionResponse( systemAddress );
#endif
		}
		else
		{
			// This one we only send once since we don't care if it arrives.
			unsigned char c = ID_INVALID_PASSWORD;
			SendImmediate(( char* ) & c, sizeof( char )*8, SYSTEM_PRIORITY, RELIABLE, 0, systemAddress, false, false, RakNet::GetTimeNS());
			remoteSystem->connectMode=RemoteSystemStruct::DISCONNECT_ASAP_SILENTLY;
		}
	}
}
