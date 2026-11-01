// from server: 100% by tester
struct RakPeer {
    char pad[0x15c];
    bool flag;
    void setFlag(bool value);
};

void RakPeer::setFlag(bool value) {
    flag = value;
}