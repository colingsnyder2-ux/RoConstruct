// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// RakNet::RakPeer::GetConnectionState, standalone with the 2012-06 layout:
// sizeof(RemoteSystemStruct) == 0x1208 and connectMode at 0x1200 (the vendor unit has 0x1210 / 0x120c).
struct SimpleMutex { void Lock(); void Unlock(); };
struct SystemAddress {
    unsigned int address[4]; unsigned short debugPort; unsigned short systemIndex;
    bool operator==(const SystemAddress& right) const;
    bool operator!=(const SystemAddress& right) const;
};
struct RakNetGUID { unsigned __int64 g; unsigned short systemIndex; };
struct AddressOrGUID { RakNetGUID rakNetGuid; SystemAddress systemAddress; };
extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;
enum ConnectionState {
    IS_PENDING, IS_CONNECTING, IS_CONNECTED, IS_DISCONNECTING,
    IS_SILENTLY_DISCONNECTING, IS_DISCONNECTED, IS_NOT_CONNECTED
};
template<class T> struct Queue {
    T* array; unsigned head; unsigned tail; unsigned allocation_size;
    unsigned Size() const { if (head <= tail) return tail - head; else return allocation_size - head + tail; }
    T& operator[](unsigned position) const {
        if (head + position >= allocation_size)
            return array[head + position - allocation_size];
        else
            return array[head + position];
    }
};
struct RemoteSystemStruct {
    bool isActive;
    char pad[0x1200 - 1];
    enum ConnectMode { NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK,
                       REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, CONNECTED } connectMode;
    int tail;
};
struct RequestedConnectionStruct { SystemAddress systemAddress; };
struct RakPeer {
    virtual ConnectionState GetConnectionState(const AddressOrGUID systemIdentifier);
    int GetIndexFromSystemAddress(const SystemAddress systemAddress, bool calledFromNetworkThread) const;
    int GetIndexFromGuid(const RakNetGUID guid);
    char pad[0x22c - 4];
    RemoteSystemStruct* remoteSystemList;
    char pad2[0x2e4 - 0x230];
    Queue<RequestedConnectionStruct*> requestedConnectionQueue;
    SimpleMutex requestedConnectionQueueMutex;
};
ConnectionState RakPeer::GetConnectionState(const AddressOrGUID systemIdentifier)
{
    if (systemIdentifier.systemAddress != UNASSIGNED_SYSTEM_ADDRESS)
    {
        unsigned int i = 0;
        requestedConnectionQueueMutex.Lock();
        for (; i < requestedConnectionQueue.Size(); i++)
        {
            if (requestedConnectionQueue[i]->systemAddress == systemIdentifier.systemAddress)
            {
                requestedConnectionQueueMutex.Unlock();
                return IS_PENDING;
            }
        }
        requestedConnectionQueueMutex.Unlock();
    }

    int index;
    if (systemIdentifier.systemAddress != UNASSIGNED_SYSTEM_ADDRESS)
    {
        index = GetIndexFromSystemAddress(systemIdentifier.systemAddress, false);
    }
    else
    {
        index = GetIndexFromGuid(systemIdentifier.rakNetGuid);
    }

    if (index == -1)
        return IS_NOT_CONNECTED;

    if (remoteSystemList[index].isActive == false)
        return IS_DISCONNECTED;

    switch (remoteSystemList[index].connectMode)
    {
    case RemoteSystemStruct::DISCONNECT_ASAP:
        return IS_DISCONNECTING;
    case RemoteSystemStruct::DISCONNECT_ASAP_SILENTLY:
        return IS_SILENTLY_DISCONNECTING;
    case RemoteSystemStruct::DISCONNECT_ON_NO_ACK:
        return IS_DISCONNECTING;
    case RemoteSystemStruct::REQUESTED_CONNECTION:
        return IS_CONNECTING;
    case RemoteSystemStruct::HANDLING_CONNECTION_REQUEST:
        return IS_CONNECTING;
    case RemoteSystemStruct::UNVERIFIED_SENDER:
        return IS_CONNECTING;
    case RemoteSystemStruct::CONNECTED:
        return IS_CONNECTED;
    default:
        return IS_NOT_CONNECTED;
    }
}