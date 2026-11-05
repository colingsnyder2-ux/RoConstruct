// from server: 100% by Cezant64gamejr
struct ProfiledRakPeer {
    void setByteAtOffset70C(char value);
};

void ProfiledRakPeer::setByteAtOffset70C(char value) {
    ((char*)((char*)this + 0x70c))[0] = value;
}
