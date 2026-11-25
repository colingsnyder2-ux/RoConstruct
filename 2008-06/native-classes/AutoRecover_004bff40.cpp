// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <malloc.h>
#include <string.h>
#include "ProfiledRakPeer.h"

// INFERRED: unknown allocator at 0x006a0920 (operator new[] style) used for large RPC payloads
extern "C" int fn_006a0920(int a1);

bool ProfiledRakPeer::HandleRPCPacket(const char *data, int length, SystemAddress systemAddress)
{
    RakNet::BitStream incomingBitStream((unsigned char *)data, length, false);
    RakNet::BitStream replyToSender;
    RPCParameters rpcParms;
    RakNetTime time;
    bool nameIsEncoded, blockingCommand, hasNetworkID;
    RPCIndex rpcIndex;
    NetworkID networkID;
    char uniqueIdentifier[256];
    RPCNode *node;

    rpcParms.replyToSender = &replyToSender;
    rpcParms.recipient = this;
    rpcParms.sender = systemAddress;

    incomingBitStream.IgnoreBits(8);

    if (data[0] == ID_TIMESTAMP)
    {
        incomingBitStream.IgnoreBits(8 * (sizeof(RakNetTime) + sizeof(unsigned char)));
        // INFERRED: timestamp copied straight from the raw packet
        memcpy(&time, data + 1, sizeof(RakNetTime));
    }
    else
        time = 0;
    rpcParms.remoteTimestamp = time;

    if (!incomingBitStream.Read(nameIsEncoded))
        return false;

    if (nameIsEncoded)
    {
        if (!StringCompressor::Instance()->DecodeString(uniqueIdentifier, 256, &incomingBitStream))
            return false;
        rpcIndex = rpcMap.GetIndexFromFunctionName(uniqueIdentifier);
    }
    else
    {
        if (!incomingBitStream.ReadCompressed(rpcIndex))
            return false;
    }

    if (!incomingBitStream.Read(blockingCommand))
        return false;

    if (!incomingBitStream.ReadCompressed(rpcParms.numberOfBitsOfData))
        return false;

    if (!incomingBitStream.Read(hasNetworkID))
        return false;

    if (hasNetworkID)
    {
        if (!incomingBitStream.Read(networkID))
            return false;
    }

    if (rpcIndex == UNDEFINED_RPC_INDEX)
        return false;

    node = rpcMap.GetNodeFromIndex(rpcIndex);
    if (node == 0)
        return false;

    // INFERRED: field names of RPCNode
    if (node->isPointerToMember == true && hasNetworkID == false)
        return false;
    if (node->isPointerToMember == false && hasNetworkID == true)
        return false;

    if (nameIsEncoded)
    {
        if (GetRemoteSystemFromSystemAddress(systemAddress, false, true))
        {
            RakNet::BitStream outgoingBitStream;
            unsigned char id = ID_RPC_MAPPING;
            outgoingBitStream.WriteBits(&id, 8, true);
            StringCompressor::Instance()->EncodeString(node->uniqueIdentifier, 256, &outgoingBitStream);
            unsigned char idx = rpcIndex;
            outgoingBitStream.WriteCompressed(idx);
            SendBuffered((const char *)outgoingBitStream.GetData(), outgoingBitStream.GetNumberOfBitsUsed(),
                         HIGH_PRIORITY, UNRELIABLE, 0, systemAddress, false, RemoteSystemStruct::NO_ACTION);
        }
    }

    rpcParms.functionName = node->uniqueIdentifier;

    if (rpcParms.numberOfBitsOfData == 0)
    {
        rpcParms.input = 0;
        if (hasNetworkID)
        {
            if (networkIDManager)
            {
                void *object = networkIDManager->GET_OBJECT_FROM_ID(networkID);
                if (object)
                    node->memberFunctionPointer(object, &rpcParms);
            }
        }
        else
        {
            node->staticFunctionPointer(&rpcParms);
        }
    }
    else
    {
        int unread = incomingBitStream.GetNumberOfUnreadBits();
        if (unread == 0)
            return false;

        bool callerAllocationDataUsed;
        unsigned char *userData;
        if (BITS_TO_BYTES(unread) < 1048576)
        {
            userData = (unsigned char *)_malloca(BITS_TO_BYTES(unread));
            callerAllocationDataUsed = true;
        }
        else
        {
            userData = (unsigned char *)fn_006a0920(BITS_TO_BYTES(unread));
            callerAllocationDataUsed = false;
        }

        if (!incomingBitStream.ReadBits(userData, rpcParms.numberOfBitsOfData, false))
            return false;

        rpcParms.input = userData;

        if (hasNetworkID)
        {
            if (networkIDManager)
            {
                void *object = networkIDManager->GET_OBJECT_FROM_ID(networkID);
                if (object)
                    node->memberFunctionPointer(object, &rpcParms);
            }
        }
        else
        {
            node->staticFunctionPointer(&rpcParms);
        }

        if (callerAllocationDataUsed == false)
            delete userData;
    }

    if (blockingCommand)
    {
        RakNet::BitStream reply;
        unsigned char id = ID_RPC_REPLY;
        reply.WriteBits(&id, 8, true);
        reply.Write((const char *)replyToSender.GetData(), BITS_TO_BYTES(replyToSender.GetNumberOfBitsUsed()));
        Send(&reply, HIGH_PRIORITY, RELIABLE, 0, systemAddress, false);
    }

    return true;
}
