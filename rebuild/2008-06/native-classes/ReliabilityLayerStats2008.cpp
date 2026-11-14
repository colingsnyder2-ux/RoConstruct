// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /FImalloc.h /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// ReliabilityLayer statistics from preserved RakNet source; inactive pending ABI and integration.
#include "ReliabilityLayer.h"
RakNetStatistics * const ReliabilityLayer::GetStatistics( void )
{
	unsigned i;

	for ( i = 0; i < NUMBER_OF_PRIORITIES; i++ )
	{
		statistics.messageSendBuffer[i] = sendPacketSet[i].Size();
	}

	statistics.acknowlegementsPending = acknowlegements.Size();
	if (lastUpdateTime>histogramStart && histogramBitsSent >0)
		statistics.bitsPerSecond=(long double)histogramBitsSent / ((long double) (lastUpdateTime-histogramStart) / 1000000.0f);
	else
		statistics.bitsPerSecond=0.0;
	statistics.messagesWaitingForReassembly = 0;
	for (i=0; i < splitPacketChannelList.Size(); i++)
		statistics.messagesWaitingForReassembly+=splitPacketChannelList[i]->splitPacketList.Size();
	statistics.internalOutputQueueSize = outputQueue.Size();
	//statistics.lossySize = lossyWindowSize == MAXIMUM_WINDOW_SIZE + 1 ? 0 : lossyWindowSize;
	//	statistics.lossySize=0;
	// The connection is full if we are continuously sending data and we had to throttle back recently.
	statistics.bandwidthExceeded = continuousSend && (lastUpdateTime-lastTimeBetweenPacketsIncrease) > (RakNetTimeNS) 1000000;
	statistics.messagesOnResendQueue = GetResendListDataSize();

	return &statistics;
}

//-------------------------------------------------------------------------------------------------------
// Returns the number of packets in the resend queue, not counting holes
//-------------------------------------------------------------------------------------------------------
unsigned int ReliabilityLayer::GetResendListDataSize(void) const
{
	/*
	unsigned int i, count;
	for (count=0, i=0; i < resendList.Size(); i++)
	if (resendList[i]!=0)
	count++;
	return count;
	*/

	// Not accurate but thread-safe.  The commented version might crash if the queue is cleared while we loop through it
	return resendList.Size();
}

//-------------------------------------------------------------------------------------------------------
