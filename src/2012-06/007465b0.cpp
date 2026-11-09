// from server: 29% by Intel
struct BitTester {
    int flags;
    int testBit(int index);
};

int BitTester::testBit(int index) {
    if (index > 5) {
        return 0;
    }
    switch (index) {
        case 0:
            return (flags & 1) == 0;
        case 1:
            return (flags & 2) != 0;
        case 2:
            return (flags & 4) != 0;
        default:
            return 0;
    }
}
