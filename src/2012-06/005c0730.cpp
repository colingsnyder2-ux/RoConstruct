// from server: 100% by sophus
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 roc_unit_e33a557a2db53ae3.cpp

// Candidate translation unit (score above; library headers required).
#include "RakPeer.h"

uint32_t RakNet::RakPeer::SendList( const char **data, const int *lengths, const int numParameters, PacketPriority priority, PacketReliability reliability, char orderingChannel, const RakNet::AddressOrGUID systemIdentifier, bool broadcast, uint32_t forceReceiptNumber )
{
#ifdef _DEBUG
	RakAssert( data );
#endif

	if ( data == 0 || lengths == 0 )
		return 0;

	if ( remoteSystemList == 0 || *((volatile unsigned char*)this + 4) == true )
		return 0;

	if (numParameters==0)
		return 0;

	if (lengths==0)
		return 0;

	if ( broadcast == false && systemIdentifier.IsUndefined() )
		return 0;

	uint32_t usedSendReceipt;
	if (forceReceiptNumber!=0)
		usedSendReceipt=forceReceiptNumber;
	else
		usedSendReceipt=IncrementNextSendReceipt();

	SendBufferedList(data, lengths, numParameters, priority, reliability, orderingChannel, systemIdentifier, broadcast, RemoteSystemStruct::NO_ACTION, usedSendReceipt);

	return usedSendReceipt;
}
