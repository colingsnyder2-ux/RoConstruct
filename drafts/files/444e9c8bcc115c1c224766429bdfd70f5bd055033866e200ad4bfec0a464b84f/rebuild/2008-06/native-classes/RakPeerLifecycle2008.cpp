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
#include "SHA1.h"
#include "RakSleep.h"
#include "Rand.h"
#include <process.h>
unsigned __stdcall UpdateNetworkLoop(LPVOID arguments);
static const int MAX_OFFLINE_DATA_LENGTH=400;
Packet *AllocPacket(unsigned dataSize);
bool RakPeer::Connect( const char* host, unsigned short remotePort, const char* passwordData, int passwordDataLength, unsigned connectionSocketIndex )
{
	// If endThreads is true here you didn't call Startup() first.
	if ( host == 0 || endThreads || connectionSocketIndex>=connectionSocketsLength )
		return false;

	unsigned numberOfFreeSlots;

	numberOfFreeSlots = 0;

	//if (passwordDataLength>MAX_OFFLINE_DATA_LENGTH)
	//	passwordDataLength=MAX_OFFLINE_DATA_LENGTH;
	if (passwordDataLength>255)
		passwordDataLength=255;

	if (passwordData==0)
		passwordDataLength=0;

	// Not threadsafe but it's not important enough to lock.  Who is going to change the password a lot during runtime?
	// It won't overflow at least because outgoingPasswordLength is an unsigned char
//	if (passwordDataLength>0)
//		memcpy(outgoingPassword, passwordData, passwordDataLength);
//	outgoingPasswordLength=(unsigned char) passwordDataLength;

	// If the host starts with something other than 0, 1, or 2 it's (probably) a domain name.
	if ( host[ 0 ] < '0' || host[ 0 ] > '2' )
	{
#if !defined(_COMPATIBILITY_1)
		host = ( char* ) SocketLayer::Instance()->DomainNameToIP( host );
#else
		return false;
#endif
		if (host==0)
			return false;
	}

	// Connecting to ourselves in the same instance of the program?
	if ( ( strcmp( host, "127.0.0.1" ) == 0 || strcmp( host, "0.0.0.0" ) == 0 ) && remotePort == mySystemAddress.port )
		return false;

	return SendConnectionRequest( host, remotePort, passwordData, passwordDataLength, connectionSocketIndex );
}

void RakPeer::Shutdown( unsigned int blockDuration, unsigned char orderingChannel )
{
	unsigned i,j;
	bool anyActive;
	RakNetTime startWaitingTime;
//	SystemAddress systemAddress;
	RakNetTime time;
	//unsigned short systemListSize = remoteSystemListSize; // This is done for threading reasons
	unsigned short systemListSize = maximumNumberOfPeers;

	if ( blockDuration > 0 )
	{
		for ( i = 0; i < systemListSize; i++ )
		{
			// remoteSystemList in user thread
			if (remoteSystemList[i].isActive)
				NotifyAndFlagForShutdown(remoteSystemList[i].systemAddress, false, orderingChannel);
		}

		time = RakNet::GetTime();
		startWaitingTime = time;
		while ( time - startWaitingTime < blockDuration )
		{
			anyActive=false;
			for (j=0; j < systemListSize; j++)
			{
				// remoteSystemList in user thread
				if (remoteSystemList[j].isActive)
				{
					anyActive=true;
					break;
				}
			}

			// If this system is out of packets to send, then stop waiting
			if ( anyActive==false )
				break;

			// This will probably cause the update thread to run which will probably
			// send the disconnection notification

			RakSleep(15);
			time = RakNet::GetTime();
		}
	}

	for (i=0; i < messageHandlerList.Size(); i++)
	{
		messageHandlerList[i]->OnShutdown(this);
	}

	while ( isMainLoopThreadActive )
	{
		// Stop the threads
		endThreads = true;
		RakSleep(15);
	}

	// remoteSystemList in Single thread
	for ( i = 0; i < systemListSize; i++ )
	{
		// Reserve this reliability layer for ourselves
		remoteSystemList[ i ].isActive = false;

		// Remove any remaining packets
		remoteSystemList[ i ].reliabilityLayer.Reset(false);
	}

	// Clear the lookup table.  Safe to call from the user thread since the network thread is now stopped
	remoteSystemLookup.Clear();

	// Setting maximumNumberOfPeers to 0 allows remoteSystemList to be reallocated in Initialize.
	// Setting remoteSystemListSize prevents threads from accessing the reliability layer
	maximumNumberOfPeers = 0;
	//remoteSystemListSize = 0;

	// Free any packets the user didn't deallocate
	Packet **packet;
#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[transferToPacketQueue_Mutex].Lock();
#endif
	packet=packetSingleProducerConsumer.ReadLock();
	while (packet)
	{
		DeallocatePacket(*packet);
		packetSingleProducerConsumer.ReadUnlock();
		packet=packetSingleProducerConsumer.ReadLock();
	}
	packetSingleProducerConsumer.Clear();
#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[transferToPacketQueue_Mutex].Unlock();
#endif

#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[packetPool_Mutex].Lock();
#endif
	for (i=0; i < packetPool.Size(); i++)
		DeallocatePacket(packetPool[i]);
	packetPool.Clear();
#ifdef _RAKNET_THREADSAFE
	rakPeerMutexes[packetPool_Mutex].Unlock();
#endif

	blockOnRPCReply=false;

	for (i=0; i<connectionSocketsLength; i++)
		closesocket(connectionSockets[i]);
	if (connectionSockets)
		delete [] connectionSockets;
	connectionSockets=0;
	connectionSocketsLength=0;

	ClearBufferedCommands();
	bytesSentPerSecond = bytesReceivedPerSecond = 0;

	ClearRequestedConnectionList();

	/*
#if defined (_WIN32) && defined(USE_WAIT_FOR_MULTIPLE_EVENTS)
	if (recvEvent!=INVALID_HANDLE_VALUE)
	{
		CloseHandle( recvEvent );
		recvEvent = INVALID_HANDLE_VALUE;
	}	
#endif
	*/

	// Clear out the reliability layer list in case we want to reallocate it in a successive call to Init.
	RemoteSystemStruct * temp = remoteSystemList;
	remoteSystemList = 0;
	delete [] temp;
}

Packet* RakPeer::Receive( void )
{
	Packet *packet = ReceiveIgnoreRPC();
	while (packet && (packet->data[ 0 ] == ID_RPC || (packet->length>sizeof(unsigned char)+sizeof(RakNetTime) && packet->data[0]==ID_TIMESTAMP && packet->data[sizeof(unsigned char)+sizeof(RakNetTime)]==ID_RPC)))
	{
		// Do RPC calls from the user thread, not the network update thread
		// If we are currently blocking on an RPC reply, send ID_RPC to the blocker to handle rather than handling RPCs automatically
		HandleRPCPacket( ( char* ) packet->data, packet->length, packet->systemAddress );
		DeallocatePacket( packet );

		packet = ReceiveIgnoreRPC();
	}

    return packet;
}

void RakPeer::InitializeSecurity(const char *pubKeyE, const char *pubKeyN, const char *privKeyP, const char *privKeyQ )
{
#if !defined(_COMPATIBILITY_1)
	if ( endThreads == false )
		return ;

	// Setting the client key is e,n,
	// Setting the server key is p,q
	if ( //( privKeyP && privKeyQ && ( pubKeyE || pubKeyN ) ) ||
		//( pubKeyE && pubKeyN && ( privKeyP || privKeyQ ) ) ||
		( privKeyP && privKeyQ == 0 ) ||
		( privKeyQ && privKeyP == 0 ) ||
		( pubKeyE && pubKeyN == 0 ) ||
		( pubKeyN && pubKeyE == 0 ) )
	{
		// Invalid parameters
		assert( 0 );
	}

	seedMT( (unsigned int) RakNet::GetTime() );

	GenerateSYNCookieRandomNumber();

	usingSecurity = true;

	if ( privKeyP == 0 && privKeyQ == 0 && pubKeyE == 0 && pubKeyN == 0 )
	{
		keysLocallyGenerated = true;
		rsacrypt.generateKeys();
	}

	else
	{
		if ( pubKeyE && pubKeyN )
		{
			// Save public keys
			memcpy( ( char* ) & publicKeyE, pubKeyE, sizeof( publicKeyE ) );
			memcpy( publicKeyN, pubKeyN, sizeof( publicKeyN ) );
		}

		if ( privKeyP && privKeyQ )
		{
			BIGHALFSIZE( RSA_BIT_SIZE, p );
			BIGHALFSIZE( RSA_BIT_SIZE, q );
			memcpy( p, privKeyP, sizeof( p ) );
			memcpy( q, privKeyQ, sizeof( q ) );
			// Save private keys
			rsacrypt.setPrivateKey( p, q );
		}

		keysLocallyGenerated = false;
	}
#endif
}

void RakPeer::SecuredConnectionResponse( const SystemAddress systemAddress )
{
#if !defined(_COMPATIBILITY_1)
	CSHA1 sha1;
	RSA_BIT_SIZE n;
	big::u32 e;
	unsigned char connectionRequestResponse[ 1 + sizeof( big::u32 ) + sizeof( RSA_BIT_SIZE ) + 20 ];
	connectionRequestResponse[ 0 ] = ID_SECURED_CONNECTION_RESPONSE;

	if ( randomNumberExpirationTime < RakNet::GetTime() )
		GenerateSYNCookieRandomNumber();

	// Hash the SYN-Cookie
	// s2c syn-cookie = SHA1_HASH(source ip address + source port + random number)
	sha1.Reset();
	sha1.Update( ( unsigned char* ) & systemAddress.binaryAddress, sizeof( systemAddress.binaryAddress ) );
	sha1.Update( ( unsigned char* ) & systemAddress.port, sizeof( systemAddress.port ) );
	sha1.Update( ( unsigned char* ) & ( newRandomNumber ), 20 );
	sha1.Final();

	// Write the cookie
	memcpy( connectionRequestResponse + 1, sha1.GetHash(), 20 );

	// Write the public keys
	rsacrypt.getPublicKey( e, n );
#ifdef HOST_ENDIAN_IS_BIG
	// Mangle the keys on a Big-endian machine before sending
	BSWAPCPY( (unsigned char *)(connectionRequestResponse + 1 + 20),
		(unsigned char *)&e, sizeof( big::u32 ) );
	BSWAPCPY( (unsigned char *)(connectionRequestResponse + 1 + 20 + sizeof( big::u32 ) ),
		(unsigned char *)n, sizeof( RSA_BIT_SIZE ) );
#else
	memcpy( connectionRequestResponse + 1 + 20, ( char* ) & e, sizeof( big::u32 ) );
	memcpy( connectionRequestResponse + 1 + 20 + sizeof( big::u32 ), n, sizeof( RSA_BIT_SIZE ) );
#endif

	// s2c public key, syn-cookie
	//SocketLayer::Instance()->SendTo( connectionSocket, ( char* ) connectionRequestResponse, 1 + sizeof( big::u32 ) + sizeof( RSA_BIT_SIZE ) + 20, systemAddress.binaryAddress, systemAddress.port );
	// All secure connection requests are unreliable because the entire process needs to be restarted if any part fails.
	// Connection requests are resent periodically
	SendImmediate(( char* ) connectionRequestResponse, (1 + sizeof( big::u32 ) + sizeof( RSA_BIT_SIZE ) + 20) *8, SYSTEM_PRIORITY, UNRELIABLE, 0, systemAddress, false, false, RakNet::GetTimeNS());
#endif
}
