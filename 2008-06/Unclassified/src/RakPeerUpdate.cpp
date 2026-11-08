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

// >>> native-status (generated) -- do not edit >>>
// RakPeerUpdate | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src f612fe7c | roc native-status --write
#include "RakNetDefines.h"
#include "RakPeer.h"
#include "RakNetTypes.h"

#ifdef _WIN32
//#include <Shlwapi.h>
#include <process.h>
#else
#define closesocket close
#include <unistd.h>
#include <pthread.h>
#endif
#include <ctype.h> // toupper
#include <string.h>
#include "GetTime.h"
#include "MessageIdentifiers.h"
#include "DS_HuffmanEncodingTree.h"
#include "Rand.h"
#include "PluginInterface.h"
#include "StringCompressor.h"
#include "StringTable.h"
#include "NetworkIDManager.h"
#include "RakNetTypes.h"
#include "SHA1.h"
#include "RakSleep.h"
#include "RouterInterface.h"
#include "RakAssert.h"

#if !defined ( __APPLE__ ) && !defined ( __APPLE_CC__ )
#include <malloc.h>
#endif

#ifdef _COMPATIBILITY_1
//
#elif defined(_WIN32)
//
#elif defined(_COMPATIBILITY_2)
#include "Compatibility2Includes.h"
#include <stdlib.h>
#else
#include <stdlib.h>
#endif

#ifdef _MSC_VER
#pragma warning( push )
#endif

#ifdef _WIN32
unsigned __stdcall UpdateNetworkLoop( LPVOID arguments );
#else
void* UpdateNetworkLoop( void* arguments );
#endif

// FUNCTION: WEBSERVICE 0x101af8a0

Packet *AllocPacket(unsigned dataSize)
{
	Packet *p = (Packet *)malloc(sizeof(Packet)+dataSize);
	p->data=(unsigned char*)p+sizeof(Packet);
	p->length=dataSize;
	p->deleteData=false;
	return p;
}

// FUNCTION: WEBSERVICE 0x101af900
Packet *AllocPacket(unsigned dataSize, unsigned char *data)
{
	Packet *p = (Packet *)malloc(sizeof(Packet));
	p->data=data;
	p->length=dataSize;
	p->deleteData=true;
	return p;
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool RakPeer::RunUpdateCycle( void )
{
	RakPeer::RemoteSystemStruct * remoteSystem;
	unsigned remoteSystemIndex;
	Packet *packet;
	RakNetTime ping, lastPing;
	// int currentSentBytes,currentReceivedBytes;
//	unsigned numberOfBytesUsed;
	unsigned numberOfBitsUsed;
	//SystemAddress authoritativeClientSystemAddress;
	int bitSize, byteSize;
	unsigned char *data;
	int errorCode;
	int gotData;
	RakNetTimeNS timeNS;
	RakNetTime timeMS;
	SystemAddress systemAddress;
	BufferedCommandStruct *bcs;
	bool callerDataAllocationUsed;
	RakNetStatistics *rnss;
	unsigned connectionSocketIndex;

	for (connectionSocketIndex=0; connectionSocketIndex < connectionSocketsLength; connectionSocketIndex++)
	{
		do
		{
			// Read a packet
			gotData = SocketLayer::Instance()->RecvFrom( connectionSockets[connectionSocketIndex], this, &errorCode, connectionSocketIndex );

			if ( gotData == SOCKET_ERROR )
			{
#ifdef _WIN32
				if ( errorCode == WSAECONNRESET )
				{
					gotData=false;
					// 11/14/05 - RecvFrom now calls HandlePortUnreachable rather than PushPortRefused
					//PushPortRefused( UNASSIGNED_SYSTEM_ADDRESS );
					//closesocket(peer->connectionSocket);

					//peer->connectionSocket = SocketLayer::Instance()->CreateBoundSocket(peer->mySystemAddress.port, true);
				}
				else
					if ( errorCode != 0 && endThreads == false )
					{
#ifdef _DO_PRINTF
						printf( "Server RecvFrom critical failure!\n" );
#endif
						// Some kind of critical error
						// peer->isRecvfromThreadActive=false;
						endThreads = true;
						Shutdown( 0, 0 );
						return false;
					}

#else
				if ( errorCode == -1 )
				{
					// isRecvfromThreadActive=false;
					endThreads = true;
					Shutdown( 0 );
					return false;
				}
#endif
			}

			if ( endThreads )
				return false;
		}
		while ( gotData>0 ); // Read until there is nothing left
	}
	
	timeNS=0;
	timeMS=0;

	// Process all the deferred user thread Send and connect calls
	while ((bcs=bufferedCommands.ReadLock())!=0)
	{
		if (bcs->command==BufferedCommandStruct::BCS_SEND)
		{
			// GetTime is a very slow call so do it once and as late as possible
			if (timeNS==0)
				timeNS = RakNet::GetTimeNS();

			callerDataAllocationUsed=SendImmediate((char*)bcs->data, bcs->numberOfBitsToSend, bcs->priority, bcs->reliability, bcs->orderingChannel, bcs->systemAddress, bcs->broadcast, true, timeNS);
			if ( callerDataAllocationUsed==false )
				delete bcs->data;

			// Set the new connection state AFTER we call sendImmediate in case we are setting it to a disconnection state, which does not allow further sends
			if (bcs->connectionMode!=RemoteSystemStruct::NO_ACTION && bcs->systemAddress!=UNASSIGNED_SYSTEM_ADDRESS)
			{
				remoteSystem=GetRemoteSystemFromSystemAddress( bcs->systemAddress, true, true );
				if (remoteSystem)
					remoteSystem->connectMode=bcs->connectionMode;
			}
		}
		else
		{
#ifdef _DEBUG
			assert(bcs->command==BufferedCommandStruct::BCS_CLOSE_CONNECTION);
#endif
			CloseConnectionInternal(bcs->systemAddress, false, true, bcs->orderingChannel);
		}

#ifdef _DEBUG
		bcs->data=0;
#endif

		bufferedCommands.ReadUnlock();
	}

	// Process connection attempts
	RequestedConnectionStruct *rcsFirst, *rcs;
	bool condition1, condition2;
    rcsFirst = requestedConnectionList.ReadLock();
	rcs=rcsFirst;
	while (rcs)
	{
		if (timeNS==0)
		{
			timeNS = RakNet::GetTimeNS();
			timeMS = (RakNetTime)(timeNS/(RakNetTimeNS)1000);
		}

		if (rcs->nextRequestTime < timeMS)
		{
			condition1=rcs->requestsMade==6;
			condition2=(bool)((rcs->systemAddress==UNASSIGNED_SYSTEM_ADDRESS)==1);
			// If too many requests made or a hole then remove this if possible, otherwise invalidate it
			if (condition1 || condition2)
			{
				if (rcs->data)
				{
					delete [] rcs->data;
					rcs->data=0;
				}

				if (condition1 && !condition2 && rcs->actionToTake==RequestedConnectionStruct::CONNECT)
				{
					// Tell user of connection attempt failed
					packet=AllocPacket(sizeof( char ));
					packet->data[ 0 ] = ID_CONNECTION_ATTEMPT_FAILED; // Attempted a connection and couldn't
					packet->bitSize = ( sizeof( char ) * 8);
					packet->systemAddress = rcs->systemAddress;
					packet->systemIndex = 65535;
					AddPacketToProducer(packet);
				}

				// Remove this if possible
				if (rcs==rcsFirst)
				{
					requestedConnectionList.ReadUnlock();
					rcsFirst = requestedConnectionList.ReadLock();
					rcs=rcsFirst;
				}
				else
				{
					// Hole in the middle
					rcs->systemAddress=UNASSIGNED_SYSTEM_ADDRESS;
					rcs=requestedConnectionList.ReadLock();
				}

				continue;
			}

			rcs->requestsMade++;
			rcs->nextRequestTime=timeMS+1000;
			char c[2];
			c[0] = ID_OPEN_CONNECTION_REQUEST;
			c[1] = 0; // Pad - apparently some routers block 1 byte packets

			unsigned i;
			for (i=0; i < messageHandlerList.Size(); i++)
				messageHandlerList[i]->OnDirectSocketSend((char*)&c, 16, rcs->systemAddress);
			SocketLayer::Instance()->SendTo( connectionSockets[rcs->socketIndex], (char*)&c, 2, rcs->systemAddress.binaryAddress, rcs->systemAddress.port );
		}

		rcs=requestedConnectionList.ReadLock();
	}

	if (rcsFirst)
		requestedConnectionList.CancelReadLock(rcsFirst);

	 
	// remoteSystemList in network thread
	for ( remoteSystemIndex = 0; remoteSystemIndex < maximumNumberOfPeers; ++remoteSystemIndex )
	//for ( remoteSystemIndex = 0; remoteSystemIndex < remoteSystemListSize; ++remoteSystemIndex )
	{
		// I'm using systemAddress from remoteSystemList but am not locking it because this loop is called very frequently and it doesn't
		// matter if we miss or do an extra update.  The reliability layers themselves never care which player they are associated with
		//systemAddress = remoteSystemList[ remoteSystemIndex ].systemAddress;
		// Allow the systemAddress for this remote system list to change.  We don't care if it changes now.
	//	remoteSystemList[ remoteSystemIndex ].allowSystemAddressAssigment=true;
		if ( remoteSystemList[ remoteSystemIndex ].isActive )
		{
			systemAddress = remoteSystemList[ remoteSystemIndex ].systemAddress;
			RakAssert(systemAddress!=UNASSIGNED_SYSTEM_ADDRESS);

			// Found an active remote system
			remoteSystem = remoteSystemList + remoteSystemIndex;
			// Update is only safe to call from the same thread that calls HandleSocketReceiveFromConnectedPlayer,
			// which is this thread

			if (timeNS==0)
			{
				timeNS = RakNet::GetTimeNS();
				timeMS = (RakNetTime)(timeNS/(RakNetTimeNS)1000);
				//printf("timeNS = %I64i timeMS=%i\n", timeNS, timeMS);
			}


			if (timeMS > remoteSystem->lastReliableSend && timeMS-remoteSystem->lastReliableSend > 5000 && remoteSystem->connectMode==RemoteSystemStruct::CONNECTED)
			{
				// If no reliable packets are waiting for an ack, do a one byte reliable send so that disconnections are noticed
				rnss=remoteSystem->reliabilityLayer.GetStatistics();
				if (rnss->messagesOnResendQueue==0)
				{
					PingInternal( systemAddress, true, RELIABLE );
					remoteSystem->lastReliableSend=timeMS;
				}
			}

			// A separate probe, gated on the congestion control having settled: the send rate was
			// decreased recently, has not been increased recently, and nothing is queued.
			if (timeMS - remoteSystem->connectionTime < 60000 &&
				timeNS - remoteSystem->reliabilityLayer.GetLastTimeBetweenPacketsDecrease() < 2000000 &&
				timeNS - remoteSystem->reliabilityLayer.GetLastTimeBetweenPacketsIncrease() > 2000000 &&
				remoteSystem->reliabilityLayer.IsOutgoingDataWaiting()==false)
			{
				unsigned char keepAlive=ID_DETECT_LOST_CONNECTIONS;
				SendImmediate((char*)&keepAlive,8,LOW_PRIORITY, RELIABLE, 0, remoteSystem->systemAddress, false, false, timeNS);
			}

			remoteSystem->reliabilityLayer.Update( connectionSockets[remoteSystem->connectionSocketIndex], systemAddress, remoteSystem->MTUSize, timeNS, maxOutgoingBPS, messageHandlerList ); // systemAddress only used for the internet simulator test

			// Check for failure conditions
			if ( remoteSystem->reliabilityLayer.IsDeadConnection() ||
				((remoteSystem->connectMode==RemoteSystemStruct::DISCONNECT_ASAP || remoteSystem->connectMode==RemoteSystemStruct::DISCONNECT_ASAP_SILENTLY) && remoteSystem->reliabilityLayer.IsOutgoingDataWaiting()==false) ||
				(remoteSystem->connectMode==RemoteSystemStruct::DISCONNECT_ON_NO_ACK && (remoteSystem->reliabilityLayer.AreAcksWaiting()==false || remoteSystem->reliabilityLayer.AckTimeout(timeNS)==true)) ||
				((
				(remoteSystem->connectMode==RemoteSystemStruct::REQUESTED_CONNECTION ||
				remoteSystem->connectMode==RemoteSystemStruct::HANDLING_CONNECTION_REQUEST ||
				remoteSystem->connectMode==RemoteSystemStruct::UNVERIFIED_SENDER ||
				remoteSystem->connectMode==RemoteSystemStruct::SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET)
				&& timeMS > remoteSystem->connectionTime && timeMS - remoteSystem->connectionTime > 10000))
				)
			{
			//	printf("timeMS=%i remoteSystem->connectionTime=%i\n", timeMS, remoteSystem->connectionTime );

				// Failed.  Inform the user?
				if (remoteSystem->connectMode==RemoteSystemStruct::CONNECTED || remoteSystem->connectMode==RemoteSystemStruct::REQUESTED_CONNECTION
					|| remoteSystem->connectMode==RemoteSystemStruct::DISCONNECT_ASAP || remoteSystem->connectMode==RemoteSystemStruct::DISCONNECT_ON_NO_ACK)
				{
					packet=AllocPacket(sizeof( char ) );
					if (remoteSystem->connectMode==RemoteSystemStruct::REQUESTED_CONNECTION)
						packet->data[ 0 ] = ID_CONNECTION_ATTEMPT_FAILED; // Attempted a connection and couldn't
					else if (remoteSystem->connectMode==RemoteSystemStruct::CONNECTED)
						packet->data[ 0 ] = ID_CONNECTION_LOST; // DeadConnection
					else
						packet->data[ 0 ] = ID_DISCONNECTION_NOTIFICATION; // DeadConnection

					packet->bitSize = ( sizeof( char ) ) * 8;
					packet->systemAddress = systemAddress;
					packet->systemIndex = ( SystemIndex ) remoteSystemIndex;

					AddPacketToProducer(packet);
				}
				// else connection shutting down, don't bother telling the user

#ifdef _DO_PRINTF
				printf("Connection dropped for player %i:%i\n", systemAddress.binaryAddress, systemAddress.port);
#endif
				CloseConnectionInternal( systemAddress, false, true, 0 );
				continue;
			}

			// Did the reliability layer detect a modified packet?
			if ( remoteSystem->reliabilityLayer.IsCheater() )
			{
				packet=AllocPacket(sizeof(char));
				packet->bitSize=8;
				packet->data[ 0 ] = (MessageID)ID_MODIFIED_PACKET;
				packet->systemAddress = systemAddress;
				packet->systemIndex = ( SystemIndex ) remoteSystemIndex;
				AddPacketToProducer(packet);
				continue;
			}

			// Ping this guy if it is time to do so
			if ( remoteSystem->connectMode==RemoteSystemStruct::CONNECTED && timeMS > remoteSystem->nextPingTime && ( occasionalPing || remoteSystem->lowestPing == (unsigned short)-1 ) )
			{
				remoteSystem->nextPingTime = timeMS + 5000;
				PingInternal( systemAddress, true, UNRELIABLE );
			}

			// Find whoever has the lowest player ID
			//if (systemAddress < authoritativeClientSystemAddress)
			// authoritativeClientSystemAddress=systemAddress;

			// Does the reliability layer have any packets waiting for us?
			// To be thread safe, this has to be called in the same thread as HandleSocketReceiveFromConnectedPlayer
			bitSize = remoteSystem->reliabilityLayer.Receive( &data );

			while ( bitSize > 0 )
			{
				// These types are for internal use and should never arrive from a network packet
				if (data[0]==ID_CONNECTION_ATTEMPT_FAILED && data[0]==ID_MODIFIED_PACKET)
				{
					RakAssert(0);
					continue;
				}

				// Put the input through compression if necessary
				if ( inputTree )
				{
					RakNet::BitStream dataBitStream( MAXIMUM_MTU_SIZE );
					// Since we are decompressing input, we need to copy to a bitstream, decompress, then copy back to a probably
					// larger data block.  It's slow, but the user should have known that anyway
					dataBitStream.Reset();
					dataBitStream.WriteAlignedBytes( ( unsigned char* ) data, BITS_TO_BYTES( bitSize ) );
					rawBytesReceived += dataBitStream.GetNumberOfBytesUsed();

//					numberOfBytesUsed = dataBitStream.GetNumberOfBytesUsed();
					numberOfBitsUsed = dataBitStream.GetNumberOfBitsUsed();
					//rawBytesReceived += numberOfBytesUsed;
					// Decompress the input data.

					if (numberOfBitsUsed>0)
					{
						unsigned char *dataCopy = new unsigned char[ dataBitStream.GetNumberOfBytesUsed() ];
						memcpy( dataCopy, dataBitStream.GetData(), dataBitStream.GetNumberOfBytesUsed() );
						dataBitStream.Reset();
						inputTree->DecodeArray( dataCopy, numberOfBitsUsed, &dataBitStream );
						compressedBytesReceived += dataBitStream.GetNumberOfBytesUsed();
						delete [] dataCopy;

						byteSize = dataBitStream.GetNumberOfBytesUsed();

						if ( byteSize > BITS_TO_BYTES( bitSize ) )   // Probably the case - otherwise why decompress?
						{
							delete [] data;
							data = new unsigned char [ byteSize ];
						}
						memcpy( data, dataBitStream.GetData(), byteSize );
					}
					else
						byteSize=0;
				}
				else
					// Fast and easy - just use the data that was returned
					byteSize = BITS_TO_BYTES( bitSize );

				// For unknown senders we only accept a few specific packets
				if (remoteSystem->connectMode==RemoteSystemStruct::UNVERIFIED_SENDER)
				{
					if ( (unsigned char)(data)[0] == ID_CONNECTION_REQUEST )
					{
						ParseConnectionRequestPacket(remoteSystem, systemAddress, (const char*)data, byteSize);
						delete [] data;
					}
					else
					{
						CloseConnectionInternal( systemAddress, false, true, 0 );
#ifdef _DO_PRINTF
						printf("Temporarily banning %i:%i for sending nonsense data\n", systemAddress.binaryAddress, systemAddress.port);
#endif
#if !defined(_COMPATIBILITY_1)
						AddToBanList(systemAddress.ToString(false), remoteSystem->reliabilityLayer.GetTimeoutTime());
#endif

						delete [] data;
					}
				}
				else
				{
					// However, if we are connected we still take a connection request in case both systems are trying to connect to each other
					// at the same time
					if ( (unsigned char)(data)[0] == ID_CONNECTION_REQUEST )
					{
						// 04/27/06 This is wrong.  With cross connections, we can both have initiated the connection are in state REQUESTED_CONNECTION
						// 04/28/06 Downgrading connections from connected will close the connection due to security at ((remoteSystem->connectMode!=RemoteSystemStruct::CONNECTED && time > remoteSystem->connectionTime && time - remoteSystem->connectionTime > 10000))
						if (remoteSystem->connectMode==RemoteSystemStruct::REQUESTED_CONNECTION)
							ParseConnectionRequestPacket(remoteSystem, systemAddress, (const char*)data, byteSize);
						delete [] data;
					}
					else if ( (unsigned char) data[ 0 ] == ID_NEW_INCOMING_CONNECTION && byteSize == sizeof(unsigned char)+sizeof(unsigned int)+sizeof(unsigned short) )
					{
#ifdef _DEBUG
						// This assert can be ignored since it could hit from duplicate packets.
						// It's just here for internal testing since it should only happen rarely and will mostly be from bugs
//						assert(remoteSystem->connectMode==RemoteSystemStruct::HANDLING_CONNECTION_REQUEST);
#endif
						if (remoteSystem->connectMode==RemoteSystemStruct::HANDLING_CONNECTION_REQUEST ||
							remoteSystem->connectMode==RemoteSystemStruct::SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET ||
							systemAddress==mySystemAddress) // local system connect
						{
							remoteSystem->connectMode=RemoteSystemStruct::CONNECTED;
							PingInternal( systemAddress, true, UNRELIABLE );

							RakNet::BitStream inBitStream((unsigned char *) data, byteSize, false);
							SystemAddress bsSystemAddress;

							inBitStream.IgnoreBits(8);
							inBitStream.Read(bsSystemAddress.binaryAddress);
							inBitStream.Read(bsSystemAddress.port);

							// Overwrite the data in the packet
							//					NewIncomingConnectionStruct newIncomingConnectionStruct;
							//					RakNet::BitStream nICS_BS( data, NewIncomingConnectionStruct_Size, false );
							//					newIncomingConnectionStruct.Deserialize( nICS_BS );
							remoteSystem->myExternalSystemAddress = bsSystemAddress;

							// Send this info down to the game

							packet=AllocPacket(byteSize, data);
							packet->bitSize = bitSize;
							packet->systemAddress = systemAddress;
							packet->systemIndex = ( SystemIndex ) remoteSystemIndex;
							AddPacketToProducer(packet);
						}
						else
							delete [] data;
					}
					else if ( (unsigned char) data[ 0 ] == ID_CONNECTED_PONG && byteSize == sizeof(unsigned char)+sizeof(RakNetTime)*2 )
					{
						RakNetTime sendPingTime, sendPongTime;

						// Copy into the ping times array the current time - the value returned
						// First extract the sent ping
						RakNet::BitStream inBitStream( (unsigned char *) data, byteSize, false );
						//PingStruct ps;
						//ps.Deserialize(psBS);
						inBitStream.IgnoreBits(8);
						inBitStream.Read(sendPingTime);
						inBitStream.Read(sendPongTime);

						timeNS = RakNet::GetTimeNS(); // Update the time value to be accurate
						timeMS = (RakNetTime)(timeNS/(RakNetTimeNS)1000);
						if (timeMS > sendPingTime)
							ping = timeMS - sendPingTime;
						else
							ping=0;
						lastPing = remoteSystem->pingAndClockDifferential[ remoteSystem->pingAndClockDifferentialWriteIndex ].pingTime;

						// Ignore super high spikes in the average
						if ( lastPing <= 0 || ( ( ping < ( lastPing * 3 ) ) && ping < 1200 ) )
						{
							remoteSystem->pingAndClockDifferential[ remoteSystem->pingAndClockDifferentialWriteIndex ].pingTime = ( unsigned short ) ping;
							// Thanks to Chris Taylor (cat02e@fsu.edu) for the improved timestamping algorithm
							remoteSystem->pingAndClockDifferential[ remoteSystem->pingAndClockDifferentialWriteIndex ].clockDifferential = sendPongTime - timeMS / 2 - sendPingTime / 2;

							if ( remoteSystem->lowestPing == (unsigned short)-1 || remoteSystem->lowestPing > (int) ping )
								remoteSystem->lowestPing = (unsigned short) ping;

							// Most packets should arrive by the ping time.
							assert(ping < 10000); // Sanity check - could hit due to negative pings causing the var to overflow

							if ( ++( remoteSystem->pingAndClockDifferentialWriteIndex ) == PING_TIMES_ARRAY_SIZE )
								remoteSystem->pingAndClockDifferentialWriteIndex = 0;
						}

						delete [] data;
					}
					else if ( (unsigned char)data[0] == ID_INTERNAL_PING && byteSize == sizeof(unsigned char)+sizeof(RakNetTime) )
					{
						RakNet::BitStream inBitStream( (unsigned char *) data, byteSize, false );
 						inBitStream.IgnoreBits(8);
						RakNetTime sendPingTime;
						inBitStream.Read(sendPingTime);

						RakNet::BitStream outBitStream;
						outBitStream.Write((MessageID)ID_CONNECTED_PONG);
						outBitStream.Write(sendPingTime);
						timeMS = RakNet::GetTime();
						timeNS = RakNet::GetTimeNS();
						outBitStream.Write(timeMS);
						SendImmediate( (char*)outBitStream.GetData(), outBitStream.GetNumberOfBitsUsed(), SYSTEM_PRIORITY, UNRELIABLE, 0, systemAddress, false, false, timeNS );

						delete [] data;
					}
					else if ( (unsigned char) data[ 0 ] == ID_DISCONNECTION_NOTIFICATION )
					{
						// We shouldn't close the connection immediately because we need to ack the ID_DISCONNECTION_NOTIFICATION
						remoteSystem->connectMode=RemoteSystemStruct::DISCONNECT_ON_NO_ACK;
						delete [] data;

					//	AddPacketToProducer(packet);
					}
					else if ( (unsigned char) data[ 0 ] == ID_RPC_MAPPING )
					{
						RakNet::BitStream inBitStream( (unsigned char *) data, byteSize, false );
						RPCIndex index;
						char output[256];
						inBitStream.IgnoreBits(8);
						stringCompressor->DecodeString(output, 255, &inBitStream);
						inBitStream.ReadCompressed(index);
                        remoteSystem->rpcMap.AddIdentifierAtIndex((char*)output,index);
						delete [] data;
					}
#if !defined(_COMPATIBILITY_1)
					else if ( (unsigned char)(data)[0] == ID_SECURED_CONNECTION_RESPONSE &&
						byteSize == 1 + sizeof( big::u32 ) + sizeof( RSA_BIT_SIZE ) + 20 )
					{
						SecuredConnectionConfirmation( remoteSystem, (char*)data );
						delete [] data;
					}
					else if ( (unsigned char)(data)[0] == ID_SECURED_CONNECTION_CONFIRMATION &&
						byteSize == 1 + 20 + sizeof( RSA_BIT_SIZE ) )
					{
						CSHA1 sha1;
						bool confirmedHash, newRandNumber;

						confirmedHash = false;

						// Hash the SYN-Cookie
						// s2c syn-cookie = SHA1_HASH(source ip address + source port + random number)
						sha1.Reset();
						sha1.Update( ( unsigned char* ) & systemAddress.binaryAddress, sizeof( systemAddress.binaryAddress ) );
						sha1.Update( ( unsigned char* ) & systemAddress.port, sizeof( systemAddress.port ) );
						sha1.Update( ( unsigned char* ) & ( newRandomNumber ), 20 );
						sha1.Final();

						newRandNumber = false;

						// Confirm if
						//syn-cookie ?= HASH(source ip address + source port + last random number)
						//syn-cookie ?= HASH(source ip address + source port + current random number)
						if ( memcmp( sha1.GetHash(), data + 1, 20 ) == 0 )
						{
							confirmedHash = true;
						}
						else
						{
							sha1.Reset();
							sha1.Update( ( unsigned char* ) & systemAddress.binaryAddress, sizeof( systemAddress.binaryAddress ) );
							sha1.Update( ( unsigned char* ) & systemAddress.port, sizeof( systemAddress.port ) );
							sha1.Update( ( unsigned char* ) & ( oldRandomNumber ), 20 );
							sha1.Final();

							if ( memcmp( sha1.GetHash(), data + 1, 20 ) == 0 )
								confirmedHash = true;
						}
						if ( confirmedHash )
						{
							int i;
							unsigned char AESKey[ 16 ];
							RSA_BIT_SIZE message, encryptedMessage;

							// On connection accept, AES key is c2s RSA_Decrypt(random number) XOR s2c syn-cookie
							// Get the random number first
							#ifdef HOST_ENDIAN_IS_BIG
								BSWAPCPY( (unsigned char *) encryptedMessage, (unsigned char *)(data + 1 + 20), sizeof( RSA_BIT_SIZE ) );
							#else
								memcpy( encryptedMessage, data + 1 + 20, sizeof( RSA_BIT_SIZE ) );
							#endif
							rsacrypt.decrypt( encryptedMessage, message );
							#ifdef HOST_ENDIAN_IS_BIG
								BSWAPSELF( (unsigned char *) message, sizeof( RSA_BIT_SIZE ) );
							#endif

							// Save the AES key
							for ( i = 0; i < 16; i++ )
								AESKey[ i ] = data[ 1 + i ] ^ ( ( unsigned char* ) ( message ) ) [ i ];

							// Connect this player assuming we have open slots
							OnConnectionRequest( remoteSystem, AESKey, true );
						}
						delete [] data;
					}
#endif // #if !defined(_COMPATIBILITY_1)
					else if ( (unsigned char)(data)[0] == ID_DETECT_LOST_CONNECTIONS && byteSize == sizeof(unsigned char) )
					{
						// Do nothing
						delete [] data;
					}
					else if ( (unsigned char)(data)[0] == ID_CONNECTION_REQUEST_ACCEPTED && byteSize == sizeof(unsigned char)+sizeof(unsigned int)+sizeof(unsigned short)+sizeof(SystemIndex) )
					{
						// Make sure this connection accept is from someone we wanted to connect to
						bool allowConnection, alreadyConnected;

						if (remoteSystem->connectMode==RemoteSystemStruct::HANDLING_CONNECTION_REQUEST || remoteSystem->connectMode==RemoteSystemStruct::REQUESTED_CONNECTION || allowConnectionResponseIPMigration)
							allowConnection=true;
						else
							allowConnection=false;
						if (remoteSystem->connectMode==RemoteSystemStruct::HANDLING_CONNECTION_REQUEST)
							alreadyConnected=true;
						else
							alreadyConnected=false;

						if ( allowConnection )
						{
							SystemAddress externalID;
							SystemIndex systemIndex;

							RakNet::BitStream inBitStream((unsigned char *) data, byteSize, false);
							inBitStream.IgnoreBits(8); // ID_CONNECTION_REQUEST_ACCEPTED
						//	inBitStream.Read(remotePort);
							inBitStream.Read(externalID.binaryAddress);
							inBitStream.Read(externalID.port);
							inBitStream.Read(systemIndex);

							// Find a free remote system struct to use
							//						RakNet::BitStream casBitS(data, byteSize, false);
							//						ConnectionAcceptStruct cas;
							//						cas.Deserialize(casBitS);
						//	systemAddress.port = remotePort;

							// The remote system told us our external IP, so save it
							remoteSystem->myExternalSystemAddress = externalID;
							remoteSystem->connectMode=RemoteSystemStruct::CONNECTED;


							if (alreadyConnected==false)
							{
								// Use the stored encryption key
								if (remoteSystem->setAESKey)
									remoteSystem->reliabilityLayer.SetEncryptionKey( remoteSystem->AESKey );
								else
									remoteSystem->reliabilityLayer.SetEncryptionKey( 0 );
							}

							// Send the connection request complete to the game
							packet=AllocPacket(byteSize, data);
							packet->bitSize = byteSize * 8;
							packet->systemAddress = systemAddress;
							packet->systemIndex = ( SystemIndex ) GetIndexFromSystemAddress( systemAddress, true );
							AddPacketToProducer(packet);

							RakNet::BitStream outBitStream(sizeof(unsigned char)+sizeof(unsigned int)+sizeof(unsigned short));
							outBitStream.Write((MessageID)ID_NEW_INCOMING_CONNECTION);
							outBitStream.Write(systemAddress.binaryAddress);
							outBitStream.Write(systemAddress.port);
							// We turned on encryption with SetEncryptionKey.  This pads packets to up to 16 bytes.
							// As soon as a 16 byte packet arrives on the remote system, we will turn on AES.  This works because all encrypted packets are multiples of 16 and the
							// packets I happen to be sending before this are less than 16 bytes.  Otherwise there is no way to know if a packet that arrived is
							// encrypted or not so the other side won't know to turn on encryption or not.
							SendImmediate( (char*)outBitStream.GetData(), outBitStream.GetNumberOfBitsUsed(), SYSTEM_PRIORITY, RELIABLE, 0, systemAddress, false, false, RakNet::GetTimeNS() );

							if (alreadyConnected==false)
							{
								PingInternal( systemAddress, true, UNRELIABLE );
							}
						}
						else
						{
							// Tell the remote system the connection failed
							NotifyAndFlagForShutdown(systemAddress, true, 0);
#ifdef _DO_PRINTF
							printf( "Error: Got a connection accept when we didn't request the connection.\n" );
#endif
							delete [] data;
						}
					}
					else
					{
						if (data[0]>=(MessageID)ID_RPC && remoteSystem->isActive)
						{
							packet=AllocPacket(byteSize, data);
							packet->bitSize = bitSize;
							packet->systemAddress = systemAddress;
							packet->systemIndex = ( SystemIndex ) remoteSystemIndex;
							AddPacketToProducer(packet);					
						}
						else
						{
							delete [] data;
						}
					}
				}

				// Does the reliability layer have any more packets waiting for us?
				// To be thread safe, this has to be called in the same thread as HandleSocketReceiveFromConnectedPlayer
				bitSize = remoteSystem->reliabilityLayer.Receive( &data );
			}
		}
	}

	return true;
}
