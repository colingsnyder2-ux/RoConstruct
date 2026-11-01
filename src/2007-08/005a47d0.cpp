// from server: 100% by colin
struct IControllable {
    char pad[0x164];
    unsigned char lo : 3;
    unsigned char flag : 1;
    unsigned char hi : 4;
    bool getFlag() const;
};

bool IControllable::getFlag() const {
    return flag;
}
