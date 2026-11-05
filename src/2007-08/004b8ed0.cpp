// from server: 100% by colin
struct RakPeer {
    char pad[0x70c];
    bool flag;
    void setFlag(bool value);
};

void RakPeer::setFlag(bool value) {
    flag = value;
}
