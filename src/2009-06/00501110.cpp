// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct SystemAddress
{
    unsigned int binaryAddress;
    unsigned short port;
};

struct RemoteSystemStruct
{
    bool isActive;
    char pad[0x13c8 - 1];
    enum ConnectMode {NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK, REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET, CONNECTED} connectMode;
    char pad2[0x13d0 - 0x13cc];
};

class RakPeer
{
public:
    bool IsConnected(const SystemAddress systemAddress, bool includeInProgress, bool includeDisconnecting);
    int GetIndexFromSystemAddress(const SystemAddress systemAddress, bool calledFromNetworkThread);
private:
    char pad[0x53c];
    RemoteSystemStruct* remoteSystemList;
};

bool RakPeer::IsConnected(const SystemAddress systemAddress, bool includeInProgress, bool includeDisconnecting)
{
    int index = GetIndexFromSystemAddress(systemAddress, false);
    return index != -1 && remoteSystemList[index].isActive &&
        ((includeInProgress &&
                (remoteSystemList[index].connectMode == RemoteSystemStruct::REQUESTED_CONNECTION ||
                 remoteSystemList[index].connectMode == RemoteSystemStruct::HANDLING_CONNECTION_REQUEST ||
                 remoteSystemList[index].connectMode == RemoteSystemStruct::UNVERIFIED_SENDER ||
                 remoteSystemList[index].connectMode == RemoteSystemStruct::SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET))
            ||
            (includeDisconnecting &&
                (remoteSystemList[index].connectMode == RemoteSystemStruct::DISCONNECT_ASAP ||
                 remoteSystemList[index].connectMode == RemoteSystemStruct::DISCONNECT_ASAP_SILENTLY ||
                 remoteSystemList[index].connectMode == RemoteSystemStruct::DISCONNECT_ON_NO_ACK))
            ||
            remoteSystemList[index].connectMode == RemoteSystemStruct::CONNECTED);
}
