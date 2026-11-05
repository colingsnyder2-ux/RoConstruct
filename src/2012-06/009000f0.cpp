// from server: 100% by tester
struct RakPeer {
    void SetOfflinePingResponse(bool value);
};

void RakPeer::SetOfflinePingResponse(bool value) {
    *(unsigned char*)((char*)this + 0x86) = value;
}