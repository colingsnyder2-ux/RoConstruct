// native-flags: /O2 /GS- /EHsc /MD /U_RELEASE /FImalloc.h /I{headers}/../../../tools/openrbx/Client/Network/raknet30/Source /I{headers}/../../../tools/openrbx/util
#include <malloc.h>
#define alloca _malloca
#define RakPeer ProfiledRakPeer
#include "RakNetDefines.h"
#include "RakPeer.h"
#include "DS_HuffmanEncodingTree.h"

bool ProfiledRakPeer::SendImmediate(
    char *data, int numberOfBitsToSend, PacketPriority priority,
    PacketReliability reliability, char orderingChannel,
    SystemAddress systemAddress, bool broadcast,
    bool useCallerDataAllocation, RakNetTimeNS currentTime)
{
    unsigned *sendList;
    unsigned sendListSize;
    bool callerDataAllocationUsed;
    unsigned remoteSystemIndex, sendListIndex;
    unsigned numberOfBytesUsed = BITS_TO_BYTES(numberOfBitsToSend);
    callerDataAllocationUsed = false;

    sendListSize = 0;

    if (broadcast == false)
    {
        sendList = (unsigned *)alloca(sizeof(unsigned));
        remoteSystemIndex = GetIndexFromSystemAddress(systemAddress, true);
        if (remoteSystemIndex != (unsigned)-1 &&
            remoteSystemList[remoteSystemIndex].isActive &&
            remoteSystemList[remoteSystemIndex].connectMode != RemoteSystemStruct::DISCONNECT_ASAP &&
            remoteSystemList[remoteSystemIndex].connectMode != RemoteSystemStruct::DISCONNECT_ASAP_SILENTLY &&
            remoteSystemList[remoteSystemIndex].connectMode != RemoteSystemStruct::DISCONNECT_ON_NO_ACK)
        {
            sendList[0] = remoteSystemIndex;
            sendListSize = 1;
        }
    }
    else
    {
        sendList = (unsigned *)alloca(sizeof(unsigned) * maximumNumberOfPeers);

        for (remoteSystemIndex = 0; remoteSystemIndex < maximumNumberOfPeers; remoteSystemIndex++)
        {
            if (remoteSystemList[remoteSystemIndex].isActive &&
                remoteSystemList[remoteSystemIndex].systemAddress != systemAddress &&
                remoteSystemList[remoteSystemIndex].systemAddress != UNASSIGNED_SYSTEM_ADDRESS)
                sendList[sendListSize++] = remoteSystemIndex;
        }
    }

    if (sendListSize == 0)
        return false;

    for (sendListIndex = 0; sendListIndex < sendListSize; sendListIndex++)
    {
        if (trackFrequencyTable)
        {
            unsigned i;
            for (i = 0; i < numberOfBytesUsed; i++)
                frequencyTable[(unsigned char)(data[i])]++;
            rawBytesSent += numberOfBytesUsed;
        }

        if (outputTree)
        {
            RakNet::BitStream bitStreamCopy(numberOfBytesUsed);
            outputTree->EncodeArray((unsigned char*)data, numberOfBytesUsed, &bitStreamCopy);
            compressedBytesSent += bitStreamCopy.GetNumberOfBytesUsed();
            remoteSystemList[sendList[sendListIndex]].reliabilityLayer.Send(
                (char*)bitStreamCopy.GetData(), bitStreamCopy.GetNumberOfBitsUsed(),
                priority, reliability, orderingChannel, true,
                remoteSystemList[sendList[sendListIndex]].MTUSize, currentTime);
        }
        else
        {
            bool useData = useCallerDataAllocation && callerDataAllocationUsed == false &&
                           sendListIndex + 1 == sendListSize;
            remoteSystemList[sendList[sendListIndex]].reliabilityLayer.Send(
                data, numberOfBitsToSend, priority, reliability, orderingChannel,
                useData == false, remoteSystemList[sendList[sendListIndex]].MTUSize, currentTime);
            if (useData)
                callerDataAllocationUsed = true;
        }

        if (reliability == RELIABLE || reliability == RELIABLE_ORDERED || reliability == RELIABLE_SEQUENCED)
            remoteSystemList[sendList[sendListIndex]].lastReliableSend = (RakNetTime)(currentTime / (RakNetTimeNS)1000);
    }

    return callerDataAllocationUsed;
}
