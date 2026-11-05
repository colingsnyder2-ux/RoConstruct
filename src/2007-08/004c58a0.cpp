// from server: 100% by tester
struct RakPeer {
    char pad0[0x3d8];
    unsigned int field_3d8;
    unsigned int field_3dc;
    unsigned int field_3e0;
    char pad1[0x778 - 0x3e4];
    unsigned int field_778;
    unsigned int field_77c;
    char pad2[0x798 - 0x780];
    unsigned int field_798;
    unsigned int field_79c;
    void setLimit(unsigned int value);
};

void RakPeer::setLimit(unsigned int value) {
    if (value > field_3e0) {
        field_3d8 = 500;
    } else {
        field_3d8 = value;
    }
    unsigned int sum = field_798 + field_79c;
    sum += sum;
    if (field_3d8 < sum) {
        field_3d8 = sum;
    }
    unsigned int v = field_3d8;
    unsigned int scaled = v + v * 2;
    if (scaled < 30) {
        field_778 = 30000;
        field_77c = 0;
        return;
    }
    unsigned long long product = (unsigned long long)scaled * 1000;
    field_778 = (unsigned int)product;
    field_77c = (unsigned int)(product >> 32);
}
