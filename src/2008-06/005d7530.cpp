// from server: 100% by tester
struct IControllable {
    char pad[0x1e8];
    unsigned char lo : 3;
    unsigned char flag : 1;
    unsigned char hi : 4;
    bool getFlag() const;
};

bool IControllable::getFlag() const {
    return flag;
}