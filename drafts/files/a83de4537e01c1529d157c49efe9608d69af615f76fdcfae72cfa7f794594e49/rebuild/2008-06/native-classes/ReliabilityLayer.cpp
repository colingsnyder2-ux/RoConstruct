// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /FImalloc.h /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "ReliabilityLayer.h"

bool ReliabilityLayer::AckTimeout(RakNetTimeNS curTime)
{
	return curTime > lastAckTime && lastAckTime && curTime - lastAckTime > (RakNetTimeNS)timeoutTime*1000;
}

RakNetTimeNS ReliabilityLayer::GetLastTimeBetweenPacketsDecrease(void) const
{
	return lastTimeBetweenPacketsDecrease;
}

RakNetTimeNS ReliabilityLayer::GetLastTimeBetweenPacketsIncrease(void) const
{
	return lastTimeBetweenPacketsIncrease;
}

bool ReliabilityLayer::IsOutgoingDataWaiting(void)
{
	unsigned i;
	for ( i = 0; i < NUMBER_OF_PRIORITIES; i++ )
	{
		if (sendPacketSet[ i ].Size() > 0)
			return true;
	}


	return acknowlegements.Size() > 0 || resendList.IsEmpty()==false;// || outputQueue.Size() > 0 || orderingList.Size() > 0 || splitPacketChannelList.Size() > 0;
}

bool ReliabilityLayer::AreAcksWaiting(void)
{
	return acknowlegements.Size() > 0;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class DataStructures::Queue<InternalPacket *>;
