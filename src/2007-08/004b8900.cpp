// from server: 100% by colin
struct RakPeer {
    char pad0[8];
    unsigned short field_8;
    char pad1[0x22c - 0xa];
    char* field_22c;
    int countActivePeers();
};

int RakPeer::countActivePeers()
{
    unsigned short n = field_8;
    int count = 0;
    if (n > 0) {
        char* p = field_22c;
        unsigned int i = n;
        do {
            if (*p != 0)
                count++;
            p += 0x840;
            i--;
        } while (i != 0);
    }
    return count;
}
