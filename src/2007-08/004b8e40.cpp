// from server: 100% by colin
struct ReliabilityLayer {
    char pad[0x30];
    unsigned int timeoutLo;
    unsigned int timeoutHi;
    void SetUnreliableTimeout(unsigned int ms);
};

struct RakPeer {
    char pad0[8];
    unsigned short count;
    char pad1[0x22c - 0xa];
    char* array;
    char pad2[0x8cc - 0x230];
    unsigned int value;
    void SetTimeout(unsigned int v);
};

void RakPeer::SetTimeout(unsigned int v) {
    value = v;
    unsigned short i = 0;
    if (count > 0) {
        do {
            ReliabilityLayer* layer = (ReliabilityLayer*)(array + i * 0x840 + 0x18);
            layer->SetUnreliableTimeout(value);
            i++;
        } while (i < count);
    }
}
