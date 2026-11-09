// from server: 25% by atomic.potato
struct BitStream {
    int maxBits;
    int pad0;
    int bitPos;
    unsigned char* data;
    bool __cdecl readBool(bool* out);
};

bool BitStream::readBool(bool* out) {
    int pos = bitPos;
    if ((unsigned)(pos + 1) <= (unsigned)maxBits) {
        int idx = pos & 7;
        unsigned char mask = (unsigned char)(0x80 >> idx);
        *out = (data[pos >> 3] & mask) != 0;
        bitPos = pos + 1;
        return true;
    }
    return false;
}
