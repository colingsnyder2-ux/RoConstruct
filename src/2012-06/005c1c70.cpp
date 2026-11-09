// from server: 100% by sophus
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 roc_unit_e0727289cbd91caf.cpp

// Candidate translation unit (score above; library headers required).
#include "RakPeer.h"

RakNet::ConnectionAttemptResult RakNet::RakPeer::Connect( const char* host, unsigned short remotePort, const char *passwordData, int passwordDataLength, RakNet::PublicKey *publicKey, unsigned connectionSocketIndex, unsigned sendConnectionAttemptCount, unsigned timeBetweenSendConnectionAttemptsMS, RakNet::TimeMS timeoutTime )
{
	// If endThreads is true here you didn't call Startup() first.
	struct _SocketList { char _[0x42c]; unsigned int size; };
	if ( host == 0 || *((volatile unsigned char*)this + 4) || connectionSocketIndex >= ((struct _SocketList*)this)->size )
		return INVALID_PARAMETER;

	RakAssert(remotePort!=0);

	connectionSocketIndex=GetRakNetSocketFromUserConnectionSocketIndex(connectionSocketIndex);

	if (passwordDataLength>255)
		passwordDataLength=255;

	if (passwordData==0)
		passwordDataLength=0;

	return SendConnectionRequest( host, remotePort, passwordData, passwordDataLength, publicKey, connectionSocketIndex, 0, sendConnectionAttemptCount, timeBetweenSendConnectionAttemptsMS, timeoutTime);
}
