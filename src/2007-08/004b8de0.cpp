// from server: 100% by colin
struct RakPeer {
    char pad[0x8c4];
    bool flag;
    void setFlag(bool value);
};

void RakPeer::setFlag(bool value) {
    flag = value;
}
