// from server: 100% by Intel
struct RakPeer {
    void SetOfflinePingResponse(bool value);
};

void RakPeer::SetOfflinePingResponse(bool value) {
    *(unsigned char*)((char*)this + 0x46C) = value;
}
