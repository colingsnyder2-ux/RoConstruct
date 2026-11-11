// >>> native-status (generated) -- do not edit >>>
// RakPeerLifetime | 2008-06 | draft (no current byte proof)
// 0/6 mapped addresses byte-exact | 6 unproved | no mapped strings | by tester (+2) (deepseek:deepseek-flash)
// <<< native-status | src 0dcb79f6 | roc native-status --write
#include <malloc.h>
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
#include "NetworkIDObject.h"
#include "RakNetTypes.h"
#include "SHA1.h"
#include "RakSleep.h"
#include "RouterInterface.h"
#include "RakAssert.h"
#include "NetworkIDManager.h"


RakPeer::RakPeer() : processPacketsThreadHandle(0)
{
	StringCompressor::AddReference();
	StringTable::AddReference();

#if !defined(_CONSOLE_1)
	usingSecurity = false;
#endif
	memset( frequencyTable, 0, sizeof( unsigned int ) * 256 );
	rawBytesSent = rawBytesReceived = compressedBytesSent = compressedBytesReceived = 0;
	outputTree = inputTree = 0;
	defaultMTUSize = DEFAULT_MTU_SIZE;
	trackFrequencyTable = false;
	maximumIncomingConnections = 0;
	maximumNumberOfPeers = 0;
	//remoteSystemListSize=0;
	remoteSystemList = 0;
	bytesSentPerSecond = bytesReceivedPerSecond = 0;
	endThreads = true;
	isMainLoopThreadActive = false;
	// isRecvfromThreadActive=false;
	occasionalPing = false;
	connectionSockets = 0;
	connectionSocketsLength=0;
	mySystemAddress = UNASSIGNED_SYSTEM_ADDRESS;
	allowConnectionResponseIPMigration = false;
	blockOnRPCReply=false;
	//incomingPasswordLength=outgoingPasswordLength=0;
	incomingPasswordLength=0;
	router=0;
	splitMessageProgressInterval=0;
	unreliableTimeout=0;
	networkIDManager=0;
    maxOutgoingBPS=0;



	_maxSendBPS=0.0;
	_minExtraPing=0;
	_extraPingVariance=0;
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Destructor
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
RakPeer::~RakPeer()
{
//	unsigned i;

	// Free the ban list.
	ClearBanList();

	Shutdown( 0, 0);


	StringCompressor::RemoveReference();
	StringTable::RemoveReference();
    CloseHandle(processPacketsThreadHandle);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class DataStructures::SingleProducerConsumer<Packet *>;
