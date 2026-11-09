// from server: 100% by tester
struct RakPeer {
    char pad[0xad];
    bool flag;
    void setFlag(bool value);
};

void RakPeer::setFlag(bool value) {
    flag = value;
}