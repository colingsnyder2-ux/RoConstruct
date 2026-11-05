// from server: 35% by atomic.potato
// roc 2009-12 00566280  unit: RakPeer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00566280

struct RakPeer {
    char pad[0x9fc];
    unsigned int count;
    char pad2[0xa04 - 0x9fc - 4];
    int value;
    float getRatio();
};

float RakPeer::getRatio() {
    if (count == 0)
        return 0.0f;
    float num = (float)value;
    if (value < 0)
        num += 2147483648.0f;
    float den = (float)count;
    if ((int)count < 0)
        den += 2147483648.0f;
    return num / den;
}
