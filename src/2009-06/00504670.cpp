// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
#include <string.h>
class RakPeer {
public:
    struct RemoteSystemStruct {
        char pad0[0x1390];
        unsigned char AESKey[16];
        bool setAESKey;
        char pad1[0x13c8 - 0x13a1];
        enum ConnectMode { NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK, REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET, CONNECTED } connectMode;
    };
    void OnConnectionRequest(RemoteSystemStruct* remoteSystem, unsigned char* AESKey, bool setAESKey);
    void SendConnectionRequestAccepted(RemoteSystemStruct* remoteSystem);
};
void RakPeer::OnConnectionRequest(RakPeer::RemoteSystemStruct* remoteSystem, unsigned char* AESKey, bool setAESKey)
{
    SendConnectionRequestAccepted(remoteSystem);
    remoteSystem->setAESKey = setAESKey;
    if (setAESKey)
    {
        memcpy(remoteSystem->AESKey, AESKey, 16);
        remoteSystem->connectMode = RemoteSystemStruct::SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET;
    }
}
