// from server: 100% by Intel
struct ProfiledRakPeer {
    void setByteAtOffset70C(char value);
};

void ProfiledRakPeer::setByteAtOffset70C(char value) {
    ((char*)((char*)this + 0x8cc))[0] = value;
}